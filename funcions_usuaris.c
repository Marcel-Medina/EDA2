#include "estructures_i_funcions.h"


User *find_user(User *head, char username[MAX_LENGTH]) {
    User *current = head;
    while (current != NULL) {
        if (strcmp(current->Username, username) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void insert_user(User **head) {
    User *node = (User *)malloc(sizeof(User));
    User *index = *head;

    if (*head == NULL) {
        *head = node;
        node->next = NULL;
    } else {
        while (index->next != NULL) {
            index = index->next;
        }
        index->next = node;
        node->next = NULL;
    }

    printf("Usuari: ");
    scanf("%s", node->Username);
    printf("Edat: ");
    scanf("%d", &node->Age);
    printf("Ubicació: ");
    scanf("%s", node->Location);
    printf("Correu: ");
    scanf("%s", node->Mail);
    getchar();
    printf("5 Hobbies: ");
    char input[MAX_LIKINGS * MAX_LENGTH];
    fgets(input, sizeof(input), stdin);
    char *token = strtok(input, ",");
    int i = 0;
    while (token != NULL && i < MAX_LIKINGS) {
        strcpy(node->List_Likings[i], token);
        token = strtok(NULL, ",");
        i++;
    }
}

void read_users_from_file(User **head) {
    FILE *file = fopen("../UserList.txt", "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        User *new_user = (User *)malloc(sizeof(User));
        sscanf(line, "%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
               new_user->Username, &(new_user->Age), new_user->Mail, new_user->Location,
               new_user->List_Likings[0], new_user->List_Likings[1], new_user->List_Likings[2],
               new_user->List_Likings[3], new_user->List_Likings[4]);

        new_user->next = NULL;

        if (*head == NULL) {
            *head = new_user;
        } else {
            User *current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_user;
        }
    }
    fclose(file);
}

