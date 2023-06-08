#ifndef EDA2_PRINTER_H
#define EDA2_PRINTER_H

#define ANSI_COLOR_BLUE "\x1b[44m"
#define ANSI_COLOR_WHITE "\x1b[97m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[41m"
#define ANSI_COLOR_GREEN "\x1b[102m"

void print(const char *message);

void printInfo(const char *message);

void printError(const char *message);

void printSuccess(const char *message);

#endif //EDA2_PRINTER_H
