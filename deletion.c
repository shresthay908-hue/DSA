#include <stdio.h>

int main() {
    int arr[100], n, i, elem, pos = -1;


    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted order: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to delete: ");
    scanf("%d", &elem);

    for(i = 0; i < n; i++) {
        if(arr[i] == elem) {
            pos = i;
            break;
        }
    }

    if(pos == -1) {
        printf("Element not found in array.\n");
    } else {

        for(i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;

        printf("Array after deletion: ");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
