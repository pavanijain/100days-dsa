#include <stdio.h>

int main() {
    int n, i;
    
    // Input size
    scanf("%d", &n);
    
    int arr[n];
    
    // Input array
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    int max_len = 0;

    // Using simple array as map (for students)
    int hash[1000];
    
    // Initialize all values as -1
    for(i = 0; i < 1000; i++) {
        hash[i] = -1;
    }

    for(i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: If sum becomes 0
        if(sum == 0) {
            max_len = i + 1;
        }

        // Case 2: If sum seen before
        if(hash[sum + 500] != -1) {
            int len = i - hash[sum + 500];
            if(len > max_len) {
                max_len = len;
            }
        } else {
            // Store first occurrence of sum
            hash[sum + 500] = i;
        }
    }

    printf("%d", max_len);

    return 0;
}