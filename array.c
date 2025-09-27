
#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum array size

// Function prototypes
void createArray(int arr[], int *n);
void displayArray(int arr[], int n);
void insertElement(int arr[], int *n, int elem, int pos);
void deleteElement(int arr[], int *n, int pos);

int main() {
    int arr[MAX];
    int n = 0, choice, elem, pos;

    while (1) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createArray(arr, &n);
                break;
            case 2:
                displayArray(arr, n);
                break;
            case 3:
                printf("Enter element to insert: ");
                scanf("%d", &elem);
                printf("Enter position (1 to %d): ", n + 1);
                scanf("%d", &pos);
                insertElement(arr, &n, elem, pos);
                break;
            case 4:
                printf("Enter position (1 to %d) to delete: ", n);
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to create array
void createArray(int arr[], int *n) {
    int i;
    printf("Enter number of elements: ");
    scanf("%d", n);

    if (*n > MAX) {
        printf("Maximum size allowed is %d\n", MAX);
        *n = 0;
        return;
    }

    printf("Enter %d elements:\n", *n);
    for (i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to display array
void displayArray(int arr[], int n) {
    int i;
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element
void insertElement(int arr[], int *n, int elem, int pos) {
    int i;
    if (*n == MAX) {
        printf("Array is full, cannot insert.\n");
        return;
    }
    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position!\n");
        return;
    }

    for (i = *n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = elem;
    (*n)++;
    printf("Element inserted successfully.\n");
}

// Function to delete an element
void deleteElement(int arr[], int *n, int pos) {
    int i;
    if (*n == 0) {
        printf("Array is empty, nothing to delete.\n");
        return;
    }
    if (pos < 1 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }

    for (i = pos - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element deleted successfully.\n");
}