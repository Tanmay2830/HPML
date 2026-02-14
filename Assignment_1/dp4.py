#!/usr/bin/env python3
import sys
import time
import numpy as np

def dp_loop(N, A, B):
    r = 0.0  # python float (double precision)
    for j in range(N):
        r += float(A[j]) * float(B[j])
    return r

def main():
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <N> <repetitions>", file=sys.stderr)
        sys.exit(1)

    N = int(sys.argv[1])
    reps = int(sys.argv[2])
    if N <= 0 or reps <= 0:
        print("Error: N and repetitions must be positive.", file=sys.stderr)
        sys.exit(1)

    A = np.ones(N, dtype=np.float32)
    B = np.ones(N, dtype=np.float32)

    times = np.empty(reps, dtype=np.float64)
    sink = 0.0

    for r in range(reps):
        t0 = time.perf_counter()
        result = dp_loop(N, A, B)
        t1 = time.perf_counter()
        sink += result
        times[r] = (t1 - t0)

    start = reps // 2
    mean_t = float(times[start:].mean())

    bytes_moved = N * 2 * 4.0
    bw_gbs = (bytes_moved / mean_t) / 1e9

    flops_per_sec = (2.0 * N) / mean_t

    print(f"N: {N} <T>: {mean_t:.6f} sec B: {bw_gbs:.6f} GB/sec F: {flops_per_sec:.6f} FLOP/sec")

    # consume sink
    if sink == 1234567.0:
        print("Impossible sink:", sink)

if __name__ == "__main__":
    main()
