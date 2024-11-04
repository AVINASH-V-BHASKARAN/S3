#include <stdio.h>
#include <stdlib.h>
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; 
    }
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);
    free(arr);
    return 0;
}

