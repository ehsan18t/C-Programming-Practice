#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STR 20
#define MAX_DIR 255

// Declaring a function to add delay
void delay(int number_of_seconds);

// Declaring a function that can check input type
// we will use it for int input
int scan_int(const char *message);

// Main function
int main() {
    int i;
    int opt;
    int opt2 = 0;
    int flag = 0;
    int length = 0;
    char c;
    char input[MAX_STR];
    char file[MAX_DIR];
    FILE *fp;
    FILE *f = NULL;

    // Title
    printf("****************************\n"
           "**   Palindrome Checker   **\n"
           "****************************\n\n"
           "Available Options:\n"
           "    1. Read string from user\n"
           "    2. Read string from file\n\n");

    // Asking user to to choose method
    do {
        opt = scan_int("Please Select Option (1,2)");
        if (opt == 1 || opt == 2)
            break;
        else
            printf("WRONG INPUT! PLEASE TRY AGAIN!\n\n");
    } while (1);

    // Taking string input via selected method
    if (opt == 1) {
        printf("\nEnter a string:");
        scanf("%s", input);
    } else {
        printf("\nEnter File Location(EG: C:\\\\file.txt): ");
        scanf("%s", file);
        fp = fopen(file, "r");
        if (fp == NULL) {
            printf("FILE NOT FOUND AT '%s'!", file);
            exit(1);
        } else {
            for (i = 0; i <= 20; i++) {
                fscanf(fp, "%s", &input[i]);
                fclose(fp);
            }
        }
    }

    // Generating input length
    for (i = 0; input[i]; i++) {
        length++;
    }

    //Checking If input Palindrome or not
    for (i = 0; i < length; i++) {
        if (input[i] != input[length - i - 1]) {
            flag = 1;
            break;
        }
    }

    // Printing Result
    if (flag) {
        printf("%s is not a palindrome\n", input);
        printf("\n => Press any key to exit");
        getchar();
        getchar();
        return 0;
    } else {
        strupr(input);
        printf("%s is a palindrome\n", input);

        // Asking user if he want to save the result or not (only asking if it's palindrome)
        getchar();
        while ((opt2 != 1) && (opt2 != 2)) {
            printf("\nWant to save it in file? (Y/N): ");
            scanf("%c", &c);
            getchar();
            switch (c) {
                case 'y':
                case 'Y':
                    opt2 = 1;
                    break;
                case 'n':
                case 'N':
                    opt2 = 2;
                    break;
                default:
                    printf("WRONG INPUT! PLEASE TRY AGAIN!\n");
            }
        }
    }

    // Taking selected action
    if (opt2 == 1) {
        FILE *ft = fopen("result.txt", "w+,ccs=UTF-8");
        fwprintf(ft, L"%hs", input);
        fclose(f);
        printf("Operation Successful\nExiting in 3s...\n");
        delay(3);
    } else {
        printf("You Choose N\nEXITING from program in 3s...\n");
        delay(3);
    }
    return 0;
}


// Creating a function that can check input type
// we already used it for int input
int scan_int(const char *const message)
{
    int value;

    printf("%s: ", message);
    while (scanf("%d", &value) != 1)
    {
        int chr;
        printf("WRONG INPUT! PLEASE TRY AGAIN!\n\n");
        do {
            chr = getchar();
        } while ((chr != EOF) && (chr != '\n'));
        printf("%s: ", message);
    }
    return value;
}

// Created function for add delay
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}