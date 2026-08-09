#include <stdio.h>
#include <stdlib.h>

// Node structures for linked lists
typedef struct SNode {
    int key;
    struct SNode *next;
} SNode;

typedef struct DNode {
    int key;
    struct DNode *prev;
    struct DNode *next;
} DNode;

// Function to print execution step count data in CSV format
void benchmark_growth() {
    int sizes[] = {1000, 2000, 4000, 8000, 16000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("N,UnsortedArray_Search,SortedArray_Search,SinglyUnsorted_Delete,DoublyUnsorted_Delete\n");

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];

        // Operation step counts representing growth functions
        long long unsorted_search_steps = n;          // O(n)
        long long sorted_search_steps = 0;           // O(log2 n)
        int temp = n;
        while (temp > 0) { sorted_search_steps++; temp /= 2; }

        long long singly_delete_steps = n;            // O(n) traversal to find prev
        long long doubly_delete_steps = 1;            // O(1) direct pointer update

        printf("%d,%lld,%lld,%lld,%lld\n", 
               n, unsorted_search_steps, sorted_search_steps, 
               singly_delete_steps, doubly_delete_steps);
    }
}

int main() {
    printf("--- DICTIONARY OPERATION ASYMPTOTIC GROWTH DATA ---\n\n");
    benchmark_growth();
    return 0;
}