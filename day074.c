#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    char names[1000][50];

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Sort names lexicographically
    qsort(names, n, sizeof(names[0]), cmp);

    int maxCount = 1, count = 1;
    char winner[50];
    strcpy(winner, names[0]);

    for (int i = 1; i < n; i++) {
        if (strcmp(names[i], names[i - 1]) == 0) {
            count++;
        } else {
            count = 1;
        }

        // Update winner
        if (count > maxCount) {
            maxCount = count;
            strcpy(winner, names[i]);
        }
        // If tie → lexicographically smaller already handled by sorting
    }

    printf("%s %d", winner, maxCount);

    return 0;
}