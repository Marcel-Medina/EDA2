#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIKINGS 5
#define MAX_LENGTH 50

typedef struct llista_solicituds {
    char persona;
    struct llista_solicituds *tail;
    struct llista_solicituds *head;
} Solicituds;

typedef struct user_t {
    char Username[MAX_LENGTH];
    int Age;
    char Mail[MAX_LENGTH];
    char Location[MAX_LENGTH];
    char List_Likings[MAX_LIKINGS][MAX_LENGTH];
    struct user_t *next;
    Solicituds llista;
} User;

int linear_search(User *index, char usuari[MAX_LENGTH]) {
    while (strcmp(index->Username, usuari) != 0) {
        index = index->next;
    }
    if (index == NULL) {
        return -1;
    } else {
        return 0;
    }
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

    printf("Usuari:");
    scanf("%s", node->Username);
    printf("Edat:");
    scanf("%d", &node->Age);
    printf("Ubicació:");
    scanf("%s", node->Location);
    printf("Correu:");
    scanf("%s", node->Mail);
    getchar();
    printf("5 Hobbies:");
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

    char line[MAX_LENGTH * 7];

    while (fgets(line, sizeof(line), file)) {
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

        sscanf(line, "%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",node->Username, &node->Age, node->Mail, node->Location,node->List_Likings[0], node->List_Likings[1],node->List_Likings[2], node->List_Likings[3],node->List_Likings[4]);
    }

    fclose(file);
}

int menu(int *stop, User **head) {
    while (*stop == 0) {
        *stop = 0;
        int opcio;

        printf("\n--------MENU--------\n");
        printf("1. Insertar un nou usuari\n");
        printf("2. Llistar tots els usuaris\n");
        printf("3. Operar com un usuari específic\n");
        printf("4. Sortir\n");
        printf("--------------------\n");
        printf("Tria una opció:");
        scanf("%d", &opcio);

        if (opcio == 1) {
            int subopcio;
            printf("1. Insertar un nou usuari manualment\n");
            printf("2. Afegir usuaris des d'un fitxer\n");
            printf("Tria una opció:");
            scanf("%d", &subopcio);

            if (subopcio == 1) {
                insert_user(head);
            } else if (subopcio == 2) {
                char filename[MAX_LENGTH];
                read_users_from_file(head);
            } else {
                printf("Opció no vàlida\n");
            }
        } else if (opcio == 2) {
            User *index = *head;
            if (index == NULL) {
                printf("La llista està buida\n");
            }
            while (index != NULL) {
                printf("Usuari: %s\n", index->Username);
                index = index->next;
            }
        } else if (opcio == 3) {
            printf("Introdueix el nom de l'usuari:");
            char usuari[MAX_LENGTH];
            scanf("%s", usuari);
            User *index = *head;

            if (linear_search(index, usuari) == -1) {
                printf("No existeix l'usuari\n");
            } else if (linear_search(index, usuari) == 0) {
                int eleccio;
                printf("\n--------SUBMENU--------\n");
                printf("1. Enviar sol·licituds d'amistat\n");
                printf("2. Gestionar les sol·licituds pendents\n");
                printf("3. Realitzar una publicació\n");
                printf("4. Llistar les publicacions de l'usuari seleccionat\n");
                printf("5. Tornar al menu principal\n");
                printf("--------------------\n");
                printf("Tria una opció:");
                scanf("%d", &eleccio);

                if(eleccio==1){

                }
            }
        } else if (opcio == 4) {
            *stop = -1;
        } else {
            printf("L'opció que has triat no és vàlida, torna a intentar-ho\n");
            scanf("%d", &opcio);
        }

        return *stop;
    }
}

int main() {
    int stop = 0;
    User *head = NULL;

    while (menu(&stop, &head) != -1) {
    }

    User *current = head;
    while (current != NULL) {
        User *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
