#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *generate_random_array(int size);
int factorial(int n);
int fibonacci(int n);
int compare(const void *this, const void *that);
int binary_search(int *arr, int key, int size);
int binary_search_recursive(int key, int* arr, int lo, int hi);

int  main(int argc, char const *argv[]) {    
    int arr_size = 100;
    int key = 86;
    int (*comparator)(const void *, const void *) = &compare;
    
    int *arr = generate_random_array(arr_size);
    qsort(arr, arr_size, sizeof(int), comparator);
    
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
 
    printf("\n\n");

    printf("did we find %d? %d\n", key, binary_search(arr, key, arr_size));

    
    return 0;
}

int *generate_random_array(int size) {
    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int fibonacci(int n) {
    if (n == 0 || n == 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int compare(const void *this, const void *that) {
    return *(int *)this - *(int *)that;
}

int binary_search(int *arr, int key, int size) {
    return binary_search_recursive(key, arr, 0, size);
}

int binary_search_recursive(int key, int* arr, int lo, int hi) {
    if (lo > hi) return -1;
    int mid = (lo + hi)/2;
    if (key < arr[mid]) return binary_search_recursive(key, arr, lo, mid - 1);
    if (key > arr[mid]) return binary_search_recursive(key, arr, mid + 1, hi);
    else                return mid;
}