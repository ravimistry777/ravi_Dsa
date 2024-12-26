#include <stdio.h>
int main() {
    int n, position, value;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n + 1];
    printf("Enter %d elements of the array: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position (1 to %d) where you want to add the element: ", n + 1);
    scanf("%d", &position);
    if (position < 1 || position > n + 1) {
        printf("Invalid position!\n");
        return 1;
    }
    printf("Enter the value to insert at position %d: ", position);
    scanf("%d", &value);
    for (int i = n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = value;
    printf("Updated array: \n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}