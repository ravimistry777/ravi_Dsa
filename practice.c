#include <stdio.h>

int main() {
    int arr[5] = {10, 2, 5, 7, 3};
    
    int target = 12;
    
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Pair found: %d + %d = %d\n", arr[i], arr[j], target);
            }
        }
    }

    return 0;
}
