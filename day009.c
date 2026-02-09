#include <stdio.h>
#include <string.h>

int main() {
    char code_name[100];   // buffer for input string
    scanf("%s", code_name); // read string (no spaces)

    int len = strlen(code_name);

    // print characters in reverse order
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", code_name[i]);
    }

    return 0;
}