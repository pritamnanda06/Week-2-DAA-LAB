#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* merge(int arr1[], int n1, int arr2[], int n2, int *outSize) {
    *outSize = n1 + n2;
    int *res = (int *)malloc((*outSize) * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) res[k++] = (arr1[i] <= arr2[j]) ? arr1[i++] : arr2[j++];
    while (i < n1) res[k++] = arr1[i++];
    while (j < n2) res[k++] = arr2[j++];
    return res;
}

int* mergeKArraysMethod2(int **arrays, int left, int right, int n, int *outSize) {
    if (left == right) {
        *outSize = n;
        int *res = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) res[i] = arrays[left][i];
        return res;
    }
    
    int mid = left + (right - left) / 2;
    int size1, size2;
    
    int *leftMerged = mergeKArraysMethod2(arrays, left, mid, n, &size1);
    int *rightMerged = mergeKArraysMethod2(arrays, mid + 1, right, n, &size2);
    
    int *result = merge(leftMerged, size1, rightMerged, size2, outSize);
    
    free(leftMerged);
    free(rightMerged);
    return result;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    srand(time(NULL));
    int n = 1000;
    int k = 16; 
    
    int **arrays = (int **)malloc(k * sizeof(int *));
    for (int i = 0; i < k; i++) {
        arrays[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) arrays[i][j] = rand() % 10000;
        qsort(arrays[i], n, sizeof(int), compare);
    }
    int totalSize;
    clock_t start = clock();
    int *sortedResult = mergeKArraysMethod2(arrays, 0, k - 1, n, &totalSize);
    clock_t end = clock();

    printf("Merged %d arrays of size %d. Time taken: %f seconds\n", k, n, ((double)(end - start)) / CLOCKS_PER_SEC);

    free(sortedResult);
    for (int i = 0; i < k; i++) free(arrays[i]);
    free(arrays);
    return 0;
}