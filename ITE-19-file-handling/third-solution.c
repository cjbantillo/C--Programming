#include <stdio.h>
#include <ctype.h>
int main(){
    
    char text[] = "text2.txt";
    FILE *fp;
    fp = fopen (text, "r");
    
   

    if(fp == NULL){
        printf("Error opening file!\n");
        return 1;
    }

    int current, previous =  ' ';
    int word_count = 0;

    while ((current = fgetc(fp)) != EOF){
    // char buffer[100];
    // while ( fgets(buffer, sizeof(buffer), fp) != NULL)    {
       
    //     for ( int i = 0; buffer[i] != '\0'; i++){
    //         current = buffer[i];
    //         if(!isspace(current) && isspace(previous)){
    //             word_count++;
    //         }
    //         previous = current;
    //     }


        if(!isspace(current) && isspace(previous)){
            word_count++;
            // printf("Found word: %d %c\n", word_count, current);
        }
     printf("Found word: %d %c\n", word_count, current);
        previous = current;
    }

    printf("the file %s contains %d words\n", text, word_count);

    fclose(fp);

    return 0;
}