#include <stdio.h>

int main(){

    FILE *fp;
    fp = fopen ("sample.txt", "a");
    
    if(fp == NULL){
        printf("Error opening file!\n");
        return 1;
    }
    fprintf (fp, "Appending a line to the file.\n");
    fclose(fp);

    return 0;
}