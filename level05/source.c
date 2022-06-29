#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
    unsigned int i = 0;
    char buffer[100];

    fgets(buffer, 100, stdin);
    while (i < strlen(buffer)) {
        buffer[i] == tolower(buffer[i]);
        i++;
    }
    printf(buffer);
    exit(0);
}