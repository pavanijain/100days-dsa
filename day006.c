#include <stdio.h>

int main() {
    int n, i;
    int arr[100];

   
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print first element
    printf("Unique elements: ");
    printf("%d ", arr[0]);

    for(i = 1; i < n; i++) {
        if(arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
