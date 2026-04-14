#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    
    // Input string
    printf("Enter the string: ");
    scanf("%s", s);

    // Array to store visited characters (26 lowercase letters)
    int visited[26] = {0};

    // Traverse the string
    for (int i = 0; i < strlen(s); i++) {
        int index = s[i] - 'a';   // convert character to index (0–25)

        if (visited[index] == 1) {
            // If already seen, print and exit
            printf("%c\n", s[i]);
            return 0;
        }

        visited[index] = 1;  // mark as seen
    }

    // If no repeated character found
    printf("-1\n");

    return 0;
}