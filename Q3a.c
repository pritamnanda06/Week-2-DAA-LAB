#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeInto(int arr1[], int n1, int arr2[], int n2, int dest[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            dest[k++] = arr1[i++];
        } else {
            dest[k++] = arr2[j++];
        }
    }
    while (i < n1) dest[k++] = arr1[i++];
    while (j < n2) dest[k++] = arr2[j++];
}

int* mergeKArraysMethod1Optimized(int **arrays, int k, int n, int *totalSize) {
    if (k <= 0) {
        *totalSize = 0;
        return NULL;
    }
    *totalSize = k * n;
    int *result = (int *)malloc((*totalSize) * sizeof(int));
    int *tempBuf = (int *)malloc((*totalSize) * sizeof(int));

    for (int i = 0; i < n; i++) {
        result[i] = arrays[0][i];
    }
    int currentSize = n;

    for (int i = 1; i < k; i++) {
        mergeInto(result, currentSize, arrays[i], n, tempBuf);
        
        currentSize += n;
        int *swp = result;
        result = tempBuf;
        tempBuf = swp;
    }

    free(tempBuf); 
    *totalSize = currentSize;
    return result;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void generateSortedArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
    qsort(arr, n, sizeof(int), compare);
}

int main() {
    srand(time(NULL));
    int n = 1000; 
    int k_values[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int num_tests = sizeof(k_values) / sizeof(k_values[0]);

    printf("k\t\tMethod 1 Optimized Time (s)\n");
    printf("---------------------------------------------\n");

    for (int t = 0; t < num_tests; t++) {
        int k = k_values[t];
        
        int **arrays = (int **)malloc(k * sizeof(int *));
        for (int i = 0; i < k; i++) {
            arrays[i] = (int *)malloc(n * sizeof(int));
            generateSortedArray(arrays[i], n);
        }

        clock_t start = clock();
        int totalSize;
        int *sortedResult = mergeKArraysMethod1Optimized(arrays, k, n, &totalSize);
        clock_t end = clock();

        double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d\t\t%f\n", k, elapsed);

        free(sortedResult);
        for (int i = 0; i < k; i++) {
            free(arrays[i]);
        }
        free(arrays);
    }
    return 0;
}