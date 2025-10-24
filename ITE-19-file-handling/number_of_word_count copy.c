#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Return non-zero if the character should be treated as a separator between
   words. We accept an unsigned char so callers can cast fgetc() results
   safely. */
static int is_separator(unsigned char uch) {
	/* Explicitly handle common ASCII whitespace characters */
	if (uch == ' ' || uch == '\t' || uch == '\n' || uch == '\r' || uch == '\v' || uch == '\f')
		return 1;

	/* Punctuation characters treated as separators. Adjust this string
	   to change which characters split words. Note: currently includes
	   apostrophe and hyphen; remove them if you want contractions or
	   hyphenated words counted as single words. */
	const char *punct = ".,;:!?()[]{}<>\"'`~-_/\\@#%^&*+=|";
	return (strchr(punct, (int)uch) != NULL);
}

int main(void) {
	FILE *file;
	const char filename[] = "text2.txt"; /* change if you want a different file */
	int ch;                 /* store fgetc() result (int so we can detect EOF) */
	int inWord = 0;         /* 0 = outside a word; 1 = inside a word */
	int wordCount = 0;      /* running total */

	/* Open file for reading; perror() gives a useful error message on failure */
	file = fopen(filename, "r");
	if (file == NULL) {
		perror(filename);
		return 1;
	}

	/* Read each byte until EOF. fgetc() returns an int; we cast to
	   unsigned char for classification. */
	while ((ch = fgetc(file)) != EOF) {
		unsigned char uch = (unsigned char) ch;

		if (is_separator(uch)) {
			/* We hit a separator, so we're no longer inside a word. */
			inWord = 0;
		} else if (!inWord) {
			/* We found a non-separator and were previously outside a word:
			   this starts a new word. */
			inWord = 1;
			wordCount++;
		}
		/* If already inside a word and current character isn't a separator,
		   nothing changes. */
	}

	fclose(file);

	printf("The file %s contains %d words\n", filename, wordCount);
	return 0;
}

