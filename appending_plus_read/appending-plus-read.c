#include <stdio.h>

int main(){
    FILE *fp;

//     //write mode
//     fp = fopen ("sample.txt", "w");

//     if(fp == NULL)
//     {
//         printf("Error opening file!\n");
//         return 1;
// }

//     fprintf(fp, "Hello, World!\n");
//     fclose(fp);

    //append and read mode
    fp = fopen ("sample.txt", "a+");

    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fp, "Appending text.\n");
    rewind(fp);// same as fseek(fp, 0, SEEK_SET); but more readable
    
    //fseek(fp, 0, SEEK_SET); // Move the file pointer to the beginning
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);

    return 0;
}