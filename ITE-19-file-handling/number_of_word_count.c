

#include <stdio.h>
#include <ctype.h>

int main(void) {
        FILE *file;
        const char filename[] = "text2.txt"; /* file to read; change as needed */
        int ch;                 /* store fgetc() return value here (int for EOF)
                                                            * Use 'int' to correctly detect EOF. */
        int inWord = 0;         /* flag: 0 = currently outside a word, 1 = inside */
        int wordCount = 0;      /* running total of words found */

        /* Open the file for reading (text mode). fopen returns NULL on error. */
        file = fopen(filename, "r");
        if (file == NULL) {
                /* Could not open the file -- print an error and exit with non-zero */
                perror(filename);
                return 1;
        }

        /* Read one character at a time until fgetc() returns EOF. */
        while ((ch = fgetc(file)) != EOF) {
                unsigned char uch = (unsigned char) ch; /* safe for ctype functions */

                /* If this character is whitespace (space, tab, newline, etc.) or
                     punctuation, treat it as a separator between words. */
                if (isspace(uch) || ispunct(uch)) {
                        inWord = 0; /* we are now outside a word */
                } else if (!inWord) {
                        /* We found a non-separator character and we were previously
                             outside a word, so this is the start of a new word. */
                        inWord = 1;
                        wordCount++;
                }
                /* If we're already inside a word and the character isn't a separator,
                     we keep going without incrementing. */
        }

        fclose(file); /* close the file when done */

        /* Print the result to stdout */
        printf("The file %s contains %d words\n", filename, wordCount);

        return 0; /* indicate success */
}
