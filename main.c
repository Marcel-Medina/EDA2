#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIKINGS 5
#define MAX_LENGTH 100

typedef struct llista_solicituds {
    char persona[MAX_LENGTH];
    struct llista_solicituds *tail;
    struct llista_solicituds *head;
} Solicituds;

typedef struct publicacion_t {
    char autor[MAX_LENGTH];
    char contenido[MAX_LENGTH];
    struct publicacion_t *next;
} Publicacion;

typedef struct user_t {
    char Username[MAX_LENGTH];
    int Age;
    char Mail[MAX_LENGTH];
    char Location[MAX_LENGTH];
    char List_Likings[MAX_LIKINGS][MAX_LENGTH];
    struct user_t *next;
    Solicituds llista;
    Publicacion *publicaciones;
} User;


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

void realizar_publicacion(User *user) {
    Publicacion *new_post = (Publicacion *)malloc(sizeof(Publicacion));
    printf("Escribe tu publicacion:\n");
    fgets(new_post->contenido, sizeof(new_post->contenido), stdin);
    new_post->contenido[strcspn(new_post->contenido, "\n")] = 0;
    strcpy(new_post->autor, user->Username);
    new_post->next = NULL;

    if (user->publicaciones == NULL) {
        user->publicaciones = new_post;
    } else {
        Publicacion *current = user->publicaciones;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_post;
    }
}

void listar_publicaciones(User *head) {
    User *current = head;
    printf("\nPublicacions:\n");
    while (current != NULL) {
        Publicacion *post = current->publicaciones;
        if (post == NULL) {
        } else {
            while (post != NULL) {
                printf("- %s: %s\n", post->autor, post->contenido);
                post = post->next;
            }
        }
        current = current->next;
    }
}


void send_friend_request(User *sender, User *recipient) {
    Solicituds *new_request = (Solicituds *)malloc(sizeof(Solicituds));
    strcpy(new_request->persona, sender->Username);
    new_request->head = sender;
    new_request->tail = recipient->llista.head;

    if (recipient->llista.head == NULL) {
        recipient->llista.head = new_request;
        recipient->llista.tail = new_request;
    } else {
        recipient->llista.tail->tail = new_request;
        recipient->llista.tail = new_request;
    }
}

void handle_friend_requests(User *user) {
    printf("Tienes las siguientes solicitudes de amistad:\n");
    Solicituds *current = user->llista.head;
    int count = 0;
    while (current != NULL) {
        printf("- %s\n", current->persona);
        current = current->tail;
        count++;
    }

    if (count == 0) {
        printf("No tienes solicitudes de amistad pendientes.\n");
    }
}

void menu(User **head) {
    int option = 0;
    char username[MAX_LENGTH];

    while (option != 4) {
        printf("\nOpciones:\n");
        printf("1. Insertar usuario\n");
        printf("2. Listar usuarios\n");
        printf("3. Acciones como usuario\n");
        printf("4. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &option);
        getchar();

        if (option == 1) {
            int subopcio;
            printf("\nOpciones para añadir usuarios:\n");
            printf("1. Insertar un nuevo usuario manualmente\n");
            printf("2. Añadir usuarios desde un archivo\n");
            printf("Elige una opción: ");
            scanf("%d", &subopcio);

            if (subopcio == 1) {
                insert_user(head);
            } else if (subopcio == 2) {
                read_users_from_file(head);
            } else {
                printf("Opción no valida\n");
            }
        } else if (option == 2) {
            User *index = *head;
            if (index == NULL) {
                printf("La lista está vacia\n");
            }
            while (index != NULL) {
                printf("Usuario: %s\n", index->Username);
                index = index->next;
            }
        } else if (option == 3) {
            printf("Ingresa el nombre del usuario: ");
            scanf("%s", username);
            getchar();
            User *current_user = find_user(*head, username);
            if (current_user == NULL) {
                printf("Usuario no encontrado.\n");
            } else {
                int sub_option = 0;
                while (sub_option != 5) {
                    printf("\nAcciones del usuario:\n");
                    printf("1. Realizar una publicacion\n");
                    printf("2. Ver publicaciones\n");
                    printf("3. Enviar una solicitud de amistad\n");
                    printf("4. Gestionar solicitudes de amistad\n");
                    printf("5. Salir\n");
                    printf("Selecciona una opcion: ");
                    scanf("%d", &sub_option);
                    getchar();

                    if (sub_option == 1) {
                        realizar_publicacion(current_user);
                    } else if (sub_option == 2) {
                        listar_publicaciones(current_user);
                    } else if (sub_option == 3) {
                        printf("\nIngresa el nombre de usuario de la persona a la que quieres enviar la solicitud de amistad: ");
                        scanf("%s", username);
                        getchar();
                        User *recipient = find_user(*head, username);
                        if (recipient == NULL) {
                            printf("\nUsuario no encontrado.\n");
                        } else {
                            send_friend_request(current_user, recipient);
                            printf("\nSolicitud de amistad enviada.\n");
                        }
                    } else if (sub_option == 4) {
                        handle_friend_requests(current_user);
                    } else if (sub_option == 5) {
                        printf("\nVolviendo al menu principal.\n");
                    } else {
                        printf("\nOpcion invalida.\n");
                    }
                }
            }
        } else if (option == 4) {
            printf("\nSaliendo...\n");

        } else {
            printf("\nOpcion invalida.\n");
        }
    }
}


int main() {
    User *head = NULL;
    read_users_from_file(&head);
    menu(&head);
    return 0;
}
