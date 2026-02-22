#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long sum = 0;
    long long count = 0;

    
    int hash[200001] = {0}; 
    int offset = 100000;  

    hash[offset] = 1;  

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(hash[sum + offset] > 0) {
            count += hash[sum + offset];
        }

        hash[sum + offset]++;
    }

    printf("%lld", count);

    return 0;
}