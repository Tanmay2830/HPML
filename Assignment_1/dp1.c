#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

static inline double now_seconds_monotonic(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec * 1e-9;
}

float dp(long N, float *pA, float *pB) {
    float R = 0.0f;
    for (long j = 0; j < N; j++) {
        R += pA[j] * pB[j];
    }
    return R;
}

static void *xaligned_alloc(size_t alignment, size_t size) {
    void *p = NULL;
    int rc = posix_memalign(&p, alignment, size);
    if (rc != 0) {
        errno = rc;
        return NULL;
    }
    return p;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <N> <repetitions>\n", argv[0]);
        return 1;
    }

    long N = atol(argv[1]);
    long reps = atol(argv[2]);
    if (N <= 0 || reps <= 0) {
        fprintf(stderr, "Error: N and repetitions must be positive.\n");
        return 1;
    }

    size_t bytes = (size_t)N * sizeof(float);

    float *A = (float *)xaligned_alloc(64, bytes);
    float *B = (float *)xaligned_alloc(64, bytes);
    if (!A || !B) {
        fprintf(stderr, "Allocation failed (need %zu bytes per array). Try smaller N or more RAM.\n", bytes);
        return 1;
    }

    // initialize to 1.0
    for (long i = 0; i < N; i++) {
        A[i] = 1.0f;
        B[i] = 1.0f;
    }

    double *times = (double *)malloc((size_t)reps * sizeof(double));
    if (!times) {
        fprintf(stderr, "Failed to allocate times array.\n");
        return 1;
    }

    volatile float sink = 0.0f;

    for (long r = 0; r < reps; r++) {
        double t0 = now_seconds_monotonic();
        volatile float result = dp(N, A, B);
        double t1 = now_seconds_monotonic();
        sink += result;
        times[r] = (t1 - t0);
    }

    long start = reps / 2;
    long count = reps - start;

    double sum = 0.0;
    for (long r = start; r < reps; r++) sum += times[r];
    double mean_t = sum / (double)count;

    double bytes_moved = (double)N * 2.0 * (double)sizeof(float);
    double bw_gbs = (bytes_moved / mean_t) / 1e9;

    double flops_per_sec = (2.0 * (double)N) / mean_t;

    printf("N: %ld <T>: %.6f sec B: %.6f GB/sec F: %.6f FLOP/sec\n",
           N, mean_t, bw_gbs, flops_per_sec);

    if (sink == 1234567.0f) {
        printf("Impossible sink: %f\n", sink);
    }

    free(times);
    free(A);
    free(B);
    return 0;
}
