#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* used for timing the execution of several functions */
#include <chrono>

#include "unorderedTable.h"

FILE *openTxt(const char *filename)
{
    FILE *fp = fopen(filename, "r");\
    return fp;
}

void editTxt(FILE *fp)
{
    FILE *newTxt = fopen("edited-sample.txt", "w");
    if (newTxt == nullptr) return;

    /* fgets command needs a char* to pass on even one readable character, so we use
     * a char array consisting of 2 positions. one for the valuable char and one for '\0' */
    char *bufferFP = (char*) malloc(sizeof (char) * 2), prevChar = ' ', singleChar;
    while (!feof(fp))
    {
        fgets(bufferFP, 2, fp);
        /* if the valuable char is not capital we pass it on with no edit*/
        if ('a' <= bufferFP[0] && bufferFP[0] <= 'z') {
            singleChar = bufferFP[0];
            prevChar = singleChar;
            printf("%c", singleChar); //DEBUGGING PURPOSE!! TO BE DELETED!!
            fprintf(newTxt, "%c", singleChar);
        }
        /*if the valuable char is capital we make it into small */
        else if ('A' <= bufferFP[0] && bufferFP[0] <= 'Z')
        {
            singleChar = bufferFP[0] + ('a' - 'A');
            prevChar = singleChar;
            printf("%c", singleChar); //DEBUGGING PURPOSE!! TO BE DELETED!!
            fprintf(newTxt, "%c", singleChar);
        }
        /* if the valuable char is anything other than an a-z char we convert it into
         * space char ONLY IF the previous char is not space, so we dont have spaces
         * chars in order more the one time*/
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

unorderedTable fillUnTable(const char *filename)
{
    unorderedTable unTable;
    FILE *fp = openTxt(filename);
    if (fp != nullptr)
    {
        /* fgets command needs a char* to pass on even one readable character, so we use
         * a char array consisting of 2 positions. one for the valuable char and one for '\0' */
        char bufferFP[2], singleChar;
        /* token string is the concatenation of the first word (stringA) and the second
         * (stringB) with a space char between them*/
        char tokenString[500], stringA[500], stringB[500];
        bool isStringAfilled = false;
        int stringSize = 0;
        long int pos;
        while (!feof(fp))
        {
            fgets(bufferFP, 2, fp);
            singleChar = bufferFP[0];
            /* we fill the stringA only once, with the first word of the given file
             * (in small file should be "the")*/
            if (!isStringAfilled)
            {
                if (singleChar != ' ')
                {
                    stringA[stringSize] = singleChar;
                    stringSize++;
                } else
                /* if the valuable char is space char then we end the string with '\0'
                 * because obviously the first word ends*/
                {
                    stringA[stringSize] = '\0';
                    isStringAfilled = true;
                    stringSize = 0;
                }
            } else
            {
                if (singleChar != ' ')
                {
                    stringB[stringSize] = singleChar;
                    stringSize++;
                } else
                /* if the valuable char is space char then we end the string with '\0'
                 * because obviously the first word ends*/
                {
                    stringB[stringSize] = '\0';
                    /*we crate the token string by concat-ing stringA with space char and then
                     * stringB*/
                    strcpy(tokenString, strcat(strcat(stringA, " "),stringB));

                    /* if the token string doesnt exist in the unordered table, we create a
                     * new entry in the unordered table, else we increase the count of
                     * the given string by one*/
                    if (!unTable.findPair(tokenString, pos)) unTable.add(tokenString);
                    else unTable.increase(pos);
                    /*the 2nd string becomes the 1st so we can repeat the process*/
                    strcpy(stringA, stringB);
                    stringSize = 0;
                }
            }
        }
        /* each time the read of the sample text ends the last token string will be
         * a single word alone so we remove it from the table */
        unTable.decrease(unTable.getPos() - 1);
    }
    return unTable;
}

int main() {
    if (openTxt("small-file.txt") == nullptr) return 1;
    else
    {
        /*COMMENT THE editTxt() BELOW SO YOU DONT HAVE TO WAIT FOR THE FILE TO BE
         * EDITED EACH TIME YOU DEBUG THE PROGRAM*/
        //editTxt(openTxt("small-file.txt"));

        /*START OF CREATION OF UNORDERED TABLE*/
        auto start = std::chrono::high_resolution_clock::now(); //start timing the creation of unordered table
        unorderedTable unTable;
        unTable = fillUnTable("edited-sample.txt");
        auto stop = std::chrono::high_resolution_clock::now(); //stop timing
        /*END OF CREATION OF UNORDERED TABLE*/
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        FILE *output = fopen("output.txt", "w");
        fprintf(output, "%d unique pairs of words.\n", unTable.getPos());
        fprintf(output, "UnTable created in: %d microseconds.\n", duration.count());

        /* FOR DEBUGGING PURPOSES. NOT TO BE INCLUDED IN THE FINAL PROJECT */
        printf("<%s, %d>\n", unTable.get(0)->getToken(), unTable.get(0)->getCount()); //"small-file": should be "the project"
        printf("<%s, %d>\n", unTable.get(unTable.getPos() - 1)->getToken(), unTable.get(unTable.getPos() - 1)->getCount()); //"small-file": should be "ver end"

        fclose(output);
    }

    return 0;
}