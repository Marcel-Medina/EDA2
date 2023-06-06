#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIKINGS 5
#define MAX_LENGTH 100

typedef struct solicitud {
    char emisor[50];
    char receptor[50];
    int aceptada;
    struct solicitud *next;
} SolicitudAmistad;

typedef struct lista_solicitudes {

    SolicitudAmistad *head;
    SolicitudAmistad *tail;

} lista_solicitudes;

typedef struct {
    char dicionario[MAX_LENGTH];
    int count_word;
    int count_total;
} WordCount;

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
    lista_solicitudes llista;
    Publicacion *publicaciones;

} User;


void wordCount(char publicacion[MAX_LENGTH], WordCount *countArray) {
    char *copy = strdup(publicacion);
    char *word = strtok(copy, " ");

    while (word != NULL) {
        int found = 0;

        for (int i = 0; i < countArray->count_total; i++) {
            if (strcmp(countArray[i].dicionario, word) == 0) {
                countArray[i].count_word++;
                found = 1;
                break;
            }
        }

        if (found == 0) {
            if (countArray->count_total == MAX_LENGTH) {
                printf("El número máximo de palabras se ha alcanzado. Algunas palabras pueden no contarse.\n");
                break;
            }

            strcpy(countArray[countArray->count_total].dicionario, word);
            countArray[countArray->count_total].count_word = 1;
            countArray->count_total++;
        }

        word = strtok(NULL, " ");
    }

}

WordCount dicionario_global;

void imprimirPalabrasFrecuentes(WordCount* diccionario) {
    // Ordenar el diccionario en orden descendente por conteo usando bubble sort
    for (int i = 0; i < diccionario->count_total - 1; i++) {
        for (int j = 0; j < diccionario->count_total - i - 1; j++) {
            if (diccionario[j].count_word< diccionario[j + 1].count_word) {
                WordCount temp = diccionario[j];
                diccionario[j] = diccionario[j + 1];
                diccionario[j + 1] = temp;
            }
        }
    }

    // Imprimir las primeras MAX_WORDS palabras frecuentes
    printf("Las palabras más frecuentes son:\n");
    for (int i = 0; i < 10&& i < diccionario->count_total; i++) {
        printf("%s: %d\n", diccionario[i].dicionario, diccionario[i].count_word);
    }
}

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
    }
    else {
        Publicacion *current = user->publicaciones;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_post;
    }
    wordCount(new_post->contenido,&dicionario_global);
}
void listar_mis_publicaciones(User *head) {
    User *current = head;
    printf("\nPublicacions del usuari:\n");
    Publicacion *post = current->publicaciones;
    if (post == NULL) {
    } else {
        while (post != NULL) {
            printf("- %s: %s\n", post->autor, post->contenido);
            post = post->next;
        }
    }
}


void listar_publicaciones() {
    printf("\nPublicacions:\n");

}
void send_friend_request(User *sender, User *recipient) {
    SolicitudAmistad *new_request = (SolicitudAmistad *)
            malloc(sizeof(SolicitudAmistad));
    strcpy(new_request->emisor, sender->Username);
    strcpy(new_request->receptor, recipient->Username);
    new_request->next = NULL;
    if (recipient->llista.head == NULL) {
        recipient->llista.head = new_request;
        recipient->llista.tail = new_request;
    }
    else {
        recipient->llista.tail->next = new_request;
        recipient->llista.tail = new_request;
    }
}

void solicitudes_aceptadas(User *user){
    SolicitudAmistad *index = user->llista.head;
    while(index != NULL){
        if(index->aceptada == 1){
            printf("-%s",index->emisor);
        }
        index = index->next;
    }
}
void handle_friend_requests(User *user) {
    SolicitudAmistad *index = user->llista.head;
    if(index == NULL){
        printf("No tienes solicitudes de amistad");
    }
    int opcion = 0;
    while (index != NULL) {
        printf("Tienes una solicitud de amistad de: %s\n", index->emisor);
        printf("1.ACEPTAR\n2.RECHAZAR");
        scanf("%d",&opcion);
        getchar();
        if(opcion == 1){
            index->aceptada = 1;
        }
        else if (opcion == 2){
            index->aceptada = 0;
        }
        else{
            printf("Opción incorrecta");
        }
        index = index->next;
    }
    int llista_amics = 0;
    printf("Quieres ver las solicitudes aceptadas?");
    printf("1.SI\n2.NO");
    scanf("%d",&llista_amics);
    if(llista_amics == 1){
        solicitudes_aceptadas(user);
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
        printf("5. Mostrar diccionari\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &option);
        getchar();

        if (option == 1) {
            int subopcio;
            printf("\nOpciones para añadir usuarios:\n");
            printf("1. Insertar un nuevo usuario manualmente\n");
            printf("2. Añadir usuarios desde un archivo(ya estan)\n");
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
                printf("\nUsuario no encontrado.\n");
            } else {
                int sub_option = 0;
                while (sub_option != 6) {
                    printf("\nAcciones del usuario:\n");
                    printf("1. Realizar una publicacion\n");
                    printf("2. Mostrar tus publicaciones\n");
                    printf("3. Ver todas las publicaciones\n");
                    printf("4. Enviar una solicitud de amistad\n");
                    printf("5. Gestionar solicitudes de amistad\n");
                    printf("6. Salir\n");
                    printf("Selecciona una opcion: ");
                    scanf("%d", &sub_option);
                    getchar();

                    if (sub_option == 1) {
                        realizar_publicacion(current_user);


                    } else if (sub_option == 2) {
                        listar_mis_publicaciones(current_user);
                    } else if (sub_option == 3) {
                        listar_publicaciones();
                    } else if (sub_option == 4) {
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
                    } else if (sub_option == 5) {
                        handle_friend_requests(current_user);
                    } else if (sub_option == 6) {
                        printf("\nVolviendo al menu principal.\n");
                    } else {
                        printf("\nOpcion invalida.\n");
                    }
                }
            }
        }
        else if (option == 4) {
            printf("\nSaliendo...\n");

        } else if(option == 5){
            imprimirPalabrasFrecuentes(&dicionario_global);
        }
        else {
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
