#include <stdio.h>

int main() {
    FILE *file;
    char filename[] = "sample.txt";
    char charac[50];
    int wordCount = 0;

    file = fopen(filename, "r");
    if(file == NULL) {
        printf("Cannot open file %s", filename);
    }

    while(fscanf(file, "%s",charac) ==1){
          wordCount++;
        //   printf("Found word: %d %s\n", wordCount, charac);
    }

    printf("The file %s contains %d words", filename, wordCount);

    fclose(file);

    return 0;
}