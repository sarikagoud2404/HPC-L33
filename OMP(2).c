%%writefile vector_add.c
#include <stdio.h>
#include <omp.h>

#define N 1024

void vector_add(float* a, float* b, float* c) {
    int i;
    #pragma omp simd // Add SIMD pragma
    for(i=0;i<N;i++) {
        c[i] = a[i] + b[i];
    }
}

int main() {
    float a[N],b[N],c[N];
    for (int i=0;i<N;i++) {
        a[i] = (float)i * 1.5f;
        b[i] = (float)i * 2.3f;
        c[i] = 0.0f;
    }
    vector_add(a,b,c);
    for (int i=0;i<N;i++){
        if (c[i] != a[i] + b[i]) {
            printf("Error at index %d! Expected %.2f, Got %.2f\n", i, a[i] + b[i], c[i]);
            return 1;
        }
    }
    printf("vector addition successful with openMP SIMD.\n");
    return 0;
}
