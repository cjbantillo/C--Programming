#include <stdio.h>

int main() {
    FILE *fp;
    char text[100];

    fp = fopen("example.txt", "r");

    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    while (fgets(text, 100, fp) != NULL) {
        printf("%s", text);
    }

    fclose(fp);
    return 0;
}