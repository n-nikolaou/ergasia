#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *openTxt(const char *filename)
{
    FILE *fp = fopen(filename, "r");\
    return fp;
}

void editTxt(FILE *fp)
{
    FILE *newTxt = fopen("edited-sample.txt", "w");
    if (newTxt == NULL) return;

    char *bufferFP = (char*) malloc(sizeof (char) * 2), prevChar = ' ', singleChar;
    while (!feof(fp))
    {
        fgets(bufferFP, 2, fp);
        if ('a' <= bufferFP[0] && bufferFP[0] <= 'z') {
            singleChar = bufferFP[0];
            prevChar = singleChar;
            printf("%c", singleChar);
            fprintf(newTxt, "%c", singleChar);
        }
        else if ('A' <= bufferFP[0] && bufferFP[0] <= 'Z')
        {
            singleChar = bufferFP[0] + ('a' - 'A');
            prevChar = singleChar;
            printf("%c", singleChar);
            fprintf(newTxt, "%c", singleChar);
        }
        else if (prevChar != ' ')
        {
            singleChar = ' ';
            prevChar = ' ';
            printf("%c", singleChar);
            fprintf(newTxt, "%c", singleChar);
        }
    }
    fclose(newTxt);
    fclose(fp);
    return;
}

int main() {
    if (openTxt("small-file.txt") == NULL) return 1;
    else
    {
        editTxt(openTxt("small-file.txt"));

    }

    return 0;
}
