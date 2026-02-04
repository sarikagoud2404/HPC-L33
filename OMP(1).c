%%writefile simd_example.c
#include <stdio.h>
#include <omp.h>

#define N 16

int main() {
    int i;
    float a[N], b[N], c[N];

    // Initialize arrays
    for (i=0; i<N; i++) {
        a[i] = i * 1.0;
        b[i] = i * 2.0;
    }

    // SIMD vectorization
    #pragma omp simd
    for (i=0; i<N; i++) {
        c[i] = a[i] + b[i];
}
    
    for (i=0; i<N; i++) {
        printf("c[%d] = %.2f\n", i, c[i]);
    }
    return 0;
}
