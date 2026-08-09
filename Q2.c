#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge2(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L); free(R);
}

void mergeSort2(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort2(arr, l, m);
        mergeSort2(arr, m + 1, r);
        merge2(arr, l, m, r);
    }
}

void merge3(int arr[], int l, int mid1, int mid2, int r) {
    int n1 = mid1 - l + 1;
    int n2 = mid2 - mid1;
    int n3 = r - mid2;

    int *L = (n1 > 0) ? (int *)malloc(n1 * sizeof(int)) : NULL;
    int *M = (n2 > 0) ? (int *)malloc(n2 * sizeof(int)) : NULL;
    int *R = (n3 > 0) ? (int *)malloc(n3 * sizeof(int)) : NULL;

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) M[i] = arr[mid1 + 1 + i];
    for (int i = 0; i < n3; i++) R[i] = arr[mid2 + 1 + i];

    int i = 0, j = 0, k = 0, p = l;
    
    while (i < n1 && j < n2 && k < n3) {
        if (L[i] <= M[j]) {
            if (L[i] <= R[k]) arr[p++] = L[i++];
            else arr[p++] = R[k++];
        } else {
            if (M[j] <= R[k]) arr[p++] = M[j++];
            else arr[p++] = R[k++];
        }
    }

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) arr[p++] = L[i++];
        else arr[p++] = M[j++];
    }
    while (j < n2 && k < n3) {
        if (M[j] <= R[k]) arr[p++] = M[j++];
        else arr[p++] = R[k++];
    }
    while (i < n1 && k < n3) {
        if (L[i] <= R[k]) arr[p++] = L[i++];
        else arr[p++] = R[k++];
    }
    while (i < n1) arr[p++] = L[i++];
    while (j < n2) arr[p++] = M[j++];
    while (k < n3) arr[p++] = R[k++];

    if (L) free(L); if (M) free(M); if (R) free(R);
}

void mergeSort3(int arr[], int l, int r) {
    if (l >= r) return;
    int len = r - l + 1;
    int third = len / 3;
    int rem = len % 3;

    int n1 = third + (rem > 0 ? 1 : 0);
    int n2 = third + (rem > 1 ? 1 : 0);

    int mid1 = l + n1 - 1;
    int mid2 = mid1 + n2;

    mergeSort3(arr, l, mid1);
    mergeSort3(arr, mid1 + 1, mid2);
    mergeSort3(arr, mid2 + 1, r);

    merge3(arr, l, mid1, mid2, r);
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

int main() {
    srand(time(NULL));
    int sizes[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    FILE *fp = fopen("data.txt", "w");
    fprintf(fp, "Size(n)\t\t2-Way Merge(s)\t\t3-Way Merge(s)\n");
    fprintf(fp, "----------------------------------------------------------\n");

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int *arr_orig = (int *)malloc(n * sizeof(int));
        int *arr_test = (int *)malloc(n * sizeof(int));

        generateRandomArray(arr_orig, n);
        copyArray(arr_orig, arr_test, n);
        clock_t start2 = clock();
        mergeSort2(arr_test, 0, n - 1);
        clock_t end2 = clock();
        double time2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;

        copyArray(arr_orig, arr_test, n);
        clock_t start3 = clock();
        mergeSort3(arr_test, 0, n - 1);
        clock_t end3 = clock();
        double time3 = ((double)(end3 - start3)) / CLOCKS_PER_SEC;
        fprintf(fp, "%d\t\t%f\t\t%f\n", n, time2, time3);

        free(arr_orig);
        free(arr_test);
    }
    
    fclose(fp);
    printf("Data generation complete. Launching matplotlib...\n");
    
    system("python plot.py"); 
    
    return 0;
}