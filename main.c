#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "headers/menu.h"
#include "headers/printer.h"
#include "headers/user.h"
#include "headers/file_reader.h"
#include "headers/globals.h"


User *userList = NULL;
WordFrequencyCounter *counter_dictionary = NULL;

void showMenu();

int main() {
    showMenu();
    return 0;
}

void showMenu() {

    int option = 0;

    printInfo(WELCOME_MESSAGE);

    while (option != EXIT_SIGNAL) {
        printf("1. Insert new comediant.\n");
        printf("2. List all existing humorists.\n");
        printf("3. Operate as a specific comic.\n");
        printf("4. Show most used words in jokes.\n");
        printf("5. Exit (End execution)\n");
        printf("Select your option: ");

        scanf("%d", &option);
        getchar();
        while (option < 1 || option > 5) {
            printError(INVALID_OPTION_MESSAGE);
            printf("Enter your option (1-5): ");
            scanf("%d", &option);
        }
        printf("\n");

        if (option == INSERT_USER_SIGNAL) {
            int sub_option = 0;

            printf("1. Create new comediant.\n");
            printf("2. Read comediants from txt file.\n");
            scanf("%d", &sub_option);

            while (sub_option < 1 || sub_option > 3) {
                printError(INVALID_INSERT_USER_OPTION_MESSAGE);
                printf("Enter your option (1-3): ");
                scanf("%d", &sub_option);
            }

            if (sub_option == 1) {

                char name[MAX_NAME_LENGTH];
                int age;
                char email[MAX_MAIL_LENGTH];
                char location[MAX_LOCATION_LENGTH];
                char hobbies[MAX_HOBBIES_LENGTH][MAX_SINGLE_HOBBY_LENGTH];

                printf("Fill user data.\n");

                do {
                    printf("username(Max. %d characters): ", MAX_NAME_LENGTH);
                    scanf("%s", name);

                } while (strlen(name) > (MAX_NAME_LENGTH));

                printf("age: ");
                scanf("%d", &age);
                getchar();

                do {
                    printf("email(Max. %d characters): ", MAX_MAIL_LENGTH);
                    scanf("%s", email);
                } while (strlen(email) > (MAX_MAIL_LENGTH));

                do {
                    printf("current location(Max. %d characters): ", MAX_LOCATION_LENGTH);
                    scanf("%s", location);
                } while (strlen(location) > (MAX_LOCATION_LENGTH));


                printf("Introduce 5 hobbies(Each with max. %d characters): \n", MAX_SINGLE_HOBBY_LENGTH);

                for (int i = 0; i < MAX_HOBBIES_LENGTH; i++) {
                    printf("hobby %d: ", i + 1);
                    scanf("%s", hobbies[i]);
                    while (strlen(hobbies[i]) > MAX_SINGLE_HOBBY_LENGTH) {
                        printError("Please enter a hobby up to 40 characters: ");
                        printf("hobby %d: ", i + 1);
                        scanf("%s", hobbies[i]);
                    }
                }

                User *user = create_user(name, age, email, location, hobbies);
                add_user(&userList, user);
                printSuccess(USER_CREATED_SUCCESSFULLY_MESSAGE);
            } else {
                read_users_from_txt_file();
            }
        } else if (option == LIST_EXISTING_USER_SIGNAL) {
            int sub_option = 0;

            printf("1. Default printing.\n");
            printf("2. Sort by name.\n");

            scanf("%d", &sub_option);

            while (sub_option < 1 || sub_option > 2) {
                printError(INVALID_PRINT_USERS_OPTION_MESSAGE);
                printf("Enter your option (1-2): ");
                scanf("%d", &sub_option);
            }

            if (sub_option == 1) {
                print_user_list(userList);
            } else {
                sort_user_list_by_name(&userList);
                print_user_list(userList);
            }
            printSuccess(LIST_USERS_SUCCESSFULLY_MESSAGE);
        } else if (option == ACTING_AS_USER_SIGNAL) {
            bool exit_submenu = false;
            int sub_option = 0;
            char username[MAX_NAME_LENGTH];

            printf("Type the comediant's name you want to act as: ");
            scanf("%s", username);

            User *currentUser;

            currentUser = find_user(userList, username);

            while (currentUser == NULL) {
                printError("Comediant not found. Please introduce a correct name. ");
                printf("username: ");
                scanf("%s", username);
                currentUser = find_user(userList, username);
            }

            while (!exit_submenu) {
                printf("1. Send funny friend request.\n");
                printf("2. Manage pending funny friend requests.\n");
                printf("3. My funny friends.\n");
                printf("4. Post your joke.\n");
                printf("5. List my jokes.\n");
                printf("6. Back to Main Menu.\n");
                printf("Select your option: ");

                scanf("%d", &sub_option);
                getchar();

                while (sub_option < 1 || sub_option > 6) {
                    printError(INVALID_SUBMENU_OPTION_MESSAGE);
                    printf("Enter your option (1-6): ");
                    scanf("%d", &sub_option);
                }

                printf("\n");

                if (sub_option == 1) {
                    char name[MAX_NAME_LENGTH];
                    printf("Type the comediant you want to send the request: ");
                    scanf("%s", name);
                    printf("\n");
                    User *recipient = find_user(userList, name);
                    if (recipient != NULL) {
                        send_friend_request(currentUser, recipient);
                    } else {
                        printError(USER_NOT_FOUND);
                    }

                } else if (sub_option == 2) {
                    handle_friend_requests(currentUser,userList);
                } else if (sub_option == 3) {
                    display_friend_list(currentUser);
                } else if (sub_option == 4) {
                    char text[MAX_PUBLICATION_TEXT_LENGTH];
                    do {
                        printf("Joke content: (Max. %d characters): ", MAX_PUBLICATION_TEXT_LENGTH);
                        scanf(" %[^\n]", text);
                    } while (strlen(text) > (MAX_PUBLICATION_TEXT_LENGTH));

                    create_publication(currentUser, text, &counter_dictionary);
                } else if (sub_option == 5) {
                    print_user_publications(currentUser);
                }
                else if (sub_option == 6) {
                    exit_submenu = true;
                }

                printf("\n");
            }
        }else if (option == SHOW_TOP_10_DICTIONARY) {
            print_word_frequency_count(counter_dictionary);
        }else if (option == EXIT_SIGNAL) {
            printInfo(EXIT_MESSAGE);
        }
    }
}