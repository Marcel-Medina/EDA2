#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/file_reader.h"
#include "../headers/printer.h"
#include "../headers/user.h"
#include "../headers/globals.h"
//Función para cargar los usuarios desde un fichero a la estructura de usuarios
void read_users_from_txt_file() {

    FILE *txt_file = fopen("../files/users.txt","r");

    if (txt_file == NULL) {
        printError(FILE_NOT_FOUND_MESSAGE);
        return;
    }

    char name[MAX_NAME_LENGTH];
    int age;
    char email[MAX_MAIL_LENGTH];
    char location[MAX_LOCATION_LENGTH];
    char hobbies[MAX_HOBBIES_LENGTH][MAX_SINGLE_HOBBY_LENGTH];

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), txt_file)) {

        sscanf(line, "%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
               name, &age, email, location, hobbies[0], hobbies[1], hobbies[2],
               hobbies[3], hobbies[4]);

        User *new_user = create_user(name, age, email, location, hobbies);
        add_user(&userList, new_user);
    }

    fclose(txt_file);

    printSuccess(READ_AND_PARSED_TXT_USERS_DATA_INTO_MEMORY_MESSAGE);
}
