// Arup Guha
// 8/17/2015
// Secret Messages (Strings)

// Modified by Sarah Angell
// 3/16/2016
// Added print statement to printText function
// for uniformity in submissions

#include <stdio.h>
#include <string.h>

#define MAX_LEN 14

long long convert(char word[], int length);

void printText(long long value, int length);

int main() {

    int choice;
    printf("Would you like to (1) encode or (2) decode?\n");
    scanf("%d", &choice);

    // Encode.
    if (choice == 1) {

        // Get input file name.
        char filename[MAX_LEN];
        printf("Please enter the input file name, to encode.\n");
        scanf("%s", filename);
        FILE *ifp = fopen(filename, "r");

        // Convert each word, one by one.
        while (!feof(ifp)) {
            char word[MAX_LEN];
            fscanf(ifp, "%s", word);
            int len = strlen(word);
            long long res = convert(word, len);
            printf("%lld %d\n", res, len);
        }
        fclose(ifp);
    } else {

        // Get input file name.
        char filename[MAX_LEN];
        printf("Please enter the input file name, to decode.\n");
        scanf("%s", filename);
        FILE *ifp = fopen(filename, "r");

        // Convert each pair of numbers, one by one.
        while (!feof(ifp)) {
            long long value;
            int len;
            fscanf(ifp, "%lld%d", &value, &len);
            printText(value, len);
        }
        fclose(ifp);

    }

    return 0;
}

long long convert(char word[], int length) {
    long long value = 0;

    for (int i = 0; i < length; i++)
        value = value * 26 + (word[i] - 'A');

    return value;
}

void printText(long long value, int length) {
    char word[MAX_LEN];

    /*** Fill in this code. Populate the word array by filling in each
         character, backwards, using the algorithm shown in the program
         write up.  Remember to to null terminate your string appropriately.
    ***/

    printf("%s\n", word);

    return;
}
