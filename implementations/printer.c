#include "stdio.h"
#include "string.h"
#include "../headers/printer.h"

void print(const char *message){
    int length = strlen(message);

    for (int i = 0; i < length; i++) {
        printf("%c", message[i]);
    }
}

void printInfo(const char *message) {
    printf("\n" ANSI_COLOR_BLUE ANSI_COLOR_WHITE);
    print(message);
    printf(ANSI_COLOR_RESET "\n\n");
}

void printError(const char *message) {
    printf("\n" ANSI_COLOR_RED ANSI_COLOR_WHITE);
    print(message);
    printf(ANSI_COLOR_RESET "\n\n");
}

void printSuccess(const char *message) {
    printf("\n" ANSI_COLOR_GREEN ANSI_COLOR_WHITE);
    print(message);
    printf(ANSI_COLOR_RESET "\n\n");
}