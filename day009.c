#include <stdio.h>
#include <string.h>

int main() {
    char code_name[100];   
    scanf("%s", code_name); 
    int len = strlen(code_name);

    
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", code_name[i]);
    }

    return 0;
}