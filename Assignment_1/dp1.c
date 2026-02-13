#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float dp(long N, float *pA, float *pB) {
    float R = 0.0;
    for (long j = 0; j < N; j++)
        R += pA[j] * pB[j];
    return R;
}

double get_time() {
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + t.tv_nsec * 1e-9;
}

int main(int argc, char **argv) {
    long N = atol(argv[1]);
    int reps = atoi(argv[2]);

    float *A = (float*) malloc(N * sizeof(float));
    float *B = (float*) malloc(N * sizeof(float));

    for (long i = 0; i < N; i++) {
        A[i] = 1.0;
        B[i] = 1.0;
    }

    double total_time = 0.0;

    for (int r = 0; r < reps; r++) {
        double start = get_time();
        volatile float result = dp(N, A, B);
        double end = get_time();

        if (r >= reps/2)
            total_time += (end - start);
    }

    double avg_time = total_time / (reps/2);

    double bytes = 8.0 * N;
    double flops = 2.0 * N;

    double bandwidth = bytes / avg_time / 1e9;
    double throughput = flops / avg_time;

    printf("N: %ld <T>: %lf sec B: %lf GB/sec F: %lf FLOP/sec\n",
           N, avg_time, bandwidth, throughput);

    free(A);
    free(B);
    return 0;
}
