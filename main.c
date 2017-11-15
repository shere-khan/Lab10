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

    for (int i = 0; i < length; i++) {
        int wordMinA = (word[i] - 'A');
        value = value * 26 + wordMinA;
    }

    return value;
}

void printText(long long value, int length) {
    char word[MAX_LEN];

    int i = MAX_LEN - 1;
    do {
        word[i] = (char) (value % 26 + 'A');
        value /= 26;
        i--;
    } while (value != 0);

    i++;
    int word_len = MAX_LEN - i;
    char sol[word_len + 1];
    for (int j = 0; j < word_len; j++) {
        sol[j] = word[i];
        i++;
    }
    sol[word_len] = '\0';
    printf("%s\n", sol);
}
