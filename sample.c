#include <stdio.h>

int main(){
    FILE *fp ;
    fp = fopen("sample.txt", "w");

    if(fp == NULL){
        printf("invalid");
    } else {
        printf("success");
    }

    fprintf(fp,"aapended text");
    fclose(fp);


    return 0;
}
