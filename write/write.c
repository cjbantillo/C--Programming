#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("example.txt", "w");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fp, "Hello, file handling in C!\n");

    fclose(fp);
    return 0;
}
