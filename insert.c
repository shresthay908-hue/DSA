#include <stdio.h>

int main() {
    int arr[100], n, i, elem, pos;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted order: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to insert: ");
    scanf("%d", &elem);

    pos = n;
    for(i = 0; i < n; i++) {
        if(arr[i] > elem) {
            pos = i;
            break;
        }
    }

    for(i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = elem;
    n++;

    printf("Array after insertion: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
