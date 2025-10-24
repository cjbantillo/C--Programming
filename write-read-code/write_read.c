#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("data.txt", "w");
    fprintf(fp, "Apple\nBanana\nCherry");
    fclose(fp);

    fp = fopen("data.txt", "r");
    char line[20];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
    return 0;
}
