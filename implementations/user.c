#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../headers/user.h"
#include "../headers/printer.h"


User *create_user(const char *username, int age, const char *email, const char *location,
                  const char hobbies[MAX_HOBBIES_LENGTH][MAX_SINGLE_HOBBY_LENGTH]) {
    User *user = (User *) malloc(sizeof(User)); // Reservamos espacio de la memoria para el nuevo usuario

    // Actualizamos los atributos del usuario con los parametros recibidos y al puntero next le asignamos NULL
    strcpy(user->name, username);
    user->age = age;
    strcpy(user->email, email);
    strcpy(user->current_location, location);

    for (int i = 0; i < MAX_HOBBIES_LENGTH; i++) {
        strcpy(user->hobbies[i], hobbies[i]);
    }

    user->next = NULL;

    return user;
}
// Funcion que recibe el puntero del primer usuario de la lista y un nuevos usuario y añade el usuario a la lista
void add_user(User **userList, User *newUser) {
    if (*userList == NULL) {
        *userList = newUser;
    } else {
        User *current = *userList;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newUser;
    }
}
// Funcion para mostrar los diferentes usuarios que hay en la lista de usuarios
void print_user_list(User *userList) {
    User *currentUser = userList;
    while (currentUser != NULL) { // Vamos recorriendo lista hasta encontrar el último usuario
        printf("Username: %s, ", currentUser->name);
        printf("Age: %d, ", currentUser->age);
        printf("Email: %s, ", currentUser->email);
        printf("Current location: %s, ", currentUser->current_location);
        printf("Hobbies: ");

        for (int i = 0; i < MAX_HOBBIES_LENGTH; i++) {
            printf("%s ", currentUser->hobbies[i]);
        }


        printf("\n");

        currentUser = currentUser->next;
    }
}

// Función para ordenar alfabéticamente la lista de usuarios aplicando el algoritmo InsertionSort
void sort_user_list_by_name(User **head) {
    if (*head == NULL || (*head)->next == NULL) { // Comprobamos si la lista está vacía o tiene un solo elemento
        return; // No es necesario ordenar, por lo que retornamos
    }

    User *sorted = NULL; // Puntero a la lista ordenada
    User *current = *head; // Puntero para recorrer la lista no ordenada

    while (current != NULL) { // Recorremos la lista no ordenada
        User *next = current->next; // Guardamos el puntero al siguiente nodo

        if (sorted == NULL || strcmp(current->name, sorted->name) < 0) {
            // Si la lista ordenada está vacía o el nombre del usuario actual es menor que el nombre del primer nodo de la lista ordenada
            current->next = sorted; // Insertamos el usuario actual al principio de la lista ordenada
            sorted = current; // Actualizamos el puntero a la lista ordenada
        } else {
            User *temp = sorted; // Puntero auxiliar para buscar la posición de inserción

            while (temp->next != NULL && strcmp(current->name, temp->next->name) > 0) {
                // Avanzamos en la lista ordenada hasta encontrar la posición de inserción correcta (nombre mayor al del usuario actual)
                temp = temp->next;
            }

            current->next = temp->next; // Insertamos el usuario actual entre temp y temp->next
            temp->next = current;
        }
        current = next; // Avanzamos al siguiente usuario en la lista no ordenada
    }

    *head = sorted; // Actualizamos la cabeza de la lista para que apunte a la lista ordenada

    printInfo("Comediant List is now ordered by username as default");
}
// Función para encontrar un usuario en la lista de usuarios
User *find_user(User *userList, const char *username) {
    User *currentUser = userList; // Creamos un índice para ir recorriendo la lista y empezamos con el puntero al primer
    //usuario

    while (currentUser != NULL) { // Vamos recorriendo la lista
        if (strcmp(currentUser->name, username) == 0) { // Si encontramos algun usuario con el mismo nombre devolvemos el puntero
            return currentUser;
        }

        currentUser = currentUser->next; // Pasamos al siguiente usuario
    }

    return NULL; // Si no hemos encontrado el usuario devolvemos NULL
}

// Función para enviar una solicitud de amistad
void send_friend_request(User *sender, User *recipient) {
    FriendRequest *newRequest = malloc(sizeof(FriendRequest)); // Creamos espacio de la memoria para la nueva solicitud
    // Actualizamos los atributos de emisor y receptor con los parametros recibidos
    strcpy(newRequest->sender, sender->name);
    strcpy(newRequest->recipient, recipient->name);
    //newRequest->accepted = false;
    newRequest->next = NULL;

    // Si el receptor no tiene ninguna solicitud de amistad, inicializamos la cola con la solicitud creada
    if (recipient->friend_requests == NULL) {
        recipient->friend_requests = malloc(sizeof(FriendRequestQueue));
        initializeQueue(recipient->friend_requests);
    }
    // Encolamos la nueva solicitud a la cola de solicitudes del receptro
    enqueue_friend_request(recipient->friend_requests, newRequest);

    printInfo("Funny friend request sent!");
}

// Funcionar para gestionar las solicitudes de amistad de un usuario
void handle_friend_requests(User *user, User*head) {
    FriendRequestQueue *requestQueue = user->friend_requests; // Puntero para recorrer la cola de solicitudes

    if (requestQueue == NULL || requestQueue->front == NULL) {
        // Si la cola de solicitudes está vacía o no tiene un frente, no hay solicitudes pendientes
        printInfo("You have 0 pending funny friend request.");
        return;
    }

    printInfo("Processing funny friend requests.");

    while (requestQueue->front != NULL) {
        FriendRequest *currentRequest = requestQueue->front; // Obtenemos el frente de la cola actual

        char choice;
        printf("Friend request from: %s\n", currentRequest->sender);
        printf("Do you wanna accept this friend request? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'Y') {
            // Si se selecciona aceptar la solicitud de amistad
            currentRequest->accepted = true; // Marcamos la solicitud como aceptada
            printSuccess(FRIEND_REQUEST_ACCEPTED);

            // Creamos un nuevo amigo en la lista de amigos del usuario actual
            FriendList *new_friend = (FriendList *) malloc(sizeof(FriendList));
            strcpy(new_friend->username, currentRequest->sender);
            new_friend->next = user->friend_list;
            user->friend_list = new_friend;

            User *receptor = find_user(head,currentRequest->sender);
            FriendList *new_friend2 = (FriendList *) malloc(sizeof(FriendList));
            strcpy(new_friend2->username, currentRequest->recipient);
            new_friend2->next = receptor->friend_list;
            receptor->friend_list = new_friend2;

        } else {
            printError(FRIEND_REQUEST_REJECTED);
        }

        dequeue_friend_request(user->friend_requests);

        free(currentRequest); // Liberamos la memoria del nodo actual de solicitud
    }

    printInfo("End of processing. Reset queue.");
}

// Función para inicializar una cola de solicitudes de amistad
void initializeQueue(FriendRequestQueue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}
// Función para comprobar si la cola de solicitudes de amistad de un usuario esta vacía
bool is_queue_empty(FriendRequestQueue *queue) {
    return (queue->front == NULL);
}

// Función para encolar una solicitud de amistad
void enqueue_friend_request(FriendRequestQueue *queue, FriendRequest *request) {
    request->next = NULL;

    if (is_queue_empty(queue)) {
        queue->front = request;
        queue->rear = request;
    } else {
        queue->rear->next = request;
        queue->rear = request;
    }
}

void dequeue_friend_request(FriendRequestQueue *queue){
    if (is_queue_empty(queue)) {
        printf("La cola ya esta vacía");
    }
    else{
        queue->front = queue->front->next;
    }

}

// Función para mostrar los amigos de un usuario
void display_friend_list(User *user) {
    FriendList *friendList = user->friend_list;

    if (friendList == NULL) {
        printInfo("You have 0 funny friends.");
        return;
    }

    printInfo("Your funny friends:");

    while (friendList != NULL) {
        printf("  - %s\n", friendList->username);
        friendList = friendList->next;
    }

    printf("\n");
}

// Función para crear una publicación
void create_publication(User *user, const char *text, WordFrequencyCounter **counter_dictionary) {
    Publication *new_publication = (Publication *) malloc(sizeof(Publication)); // Reservamos espacio de la memoria
    if (new_publication == NULL) {
        printError(MEMORY_ALLOCATION_FAILED);
        return;
    }

    strcpy(new_publication->text, text);

    new_publication->next = NULL;

    if (user->publications == NULL) { // Comprobamos si la lista de publicaciones esta vacía
        user->publications = new_publication;
    } else { // Recorremos la lista de publicaciones y metemos la nueva publicación como la última
        Publication *current_publication = user->publications;
        while (current_publication->next != NULL) {
            current_publication = current_publication->next;
        }
        current_publication->next = new_publication;
    }
    // Sometemos la publicación al sistema de conteo
    frequency_word_count(new_publication->text, counter_dictionary);

    printInfo(PUBLICATION_CREATED_SUCCESSFULLY);
}

// Función para mostrar las publicaciones del usuario. Creamos un puntero de publicación al cual le asignamos el puntero
// a la primera publicación y vamos recorriendo la lista y mostrando las publicaciones
void print_user_publications(User *user) {
    Publication *current_publication = user->publications;

    if (current_publication == NULL) {
        printError(NO_AVAILABLE_PUBLICATION);
        return;
    }

    printf("Publications of %s:\n", user->name);

    while (current_publication != NULL) {
        printf("  - %s\n", current_publication->text);
        current_publication = current_publication->next;
    }
}

// Función para contar las palabras de una publicación y añadirlo al diccionario global
void frequency_word_count(char *publication_text, WordFrequencyCounter **counter_dictionary) {
    char text_copy[MAX_PUBLICATION_TEXT_LENGTH]; // String donde copiamos la publicacioon
    strncpy(text_copy, publication_text, MAX_PUBLICATION_TEXT_LENGTH);

    char *word = strtok(text_copy, " "); // Guardamos el texto de la linea de codigo hasta encontrar un espacio
    // en la variable word
    while (word != NULL) { // Mientras sigamos encontrando texot

        WordFrequencyCounter *current = *counter_dictionary; // Puntero para ir recorriendo las palabras del diccionario
        int found = 0;
        // Vamos comparando cada palabra de la publicación con las del diccionario. Si ya se encuentra en el diccionario
        // actualizamos su contador y si no añadimos la palabra al diccionario
        while (current != NULL) {
            if (strcmp(current->key, word) == 0) {
                current->count++;
                found = 1;
                break;
            }
            current = current->next;
        }

        if (!found) {
            WordFrequencyCounter *new_counter = (WordFrequencyCounter *) malloc(sizeof(WordFrequencyCounter));
            if (new_counter == NULL) {
                printError(MEMORY_ALLOCATION_FAILED);
                return;
            }

            strncpy(new_counter->key, word, MAX_WORD_FREQUENCY_KEY);
            new_counter->count = 1;
            new_counter->next = NULL;

            // Añadimos la nueva palabra al final del diccionario
            WordFrequencyCounter *last = *counter_dictionary;
            if (last != NULL) {
                while (last->next != NULL) {
                    last = last->next;
                }

                last->next = new_counter;
            } else {
                *counter_dictionary = new_counter;
            }
        }

        word = strtok(NULL, " ");
    }
    // Reordenamos el diccionario (utilizando el algoritmo BubbleSort)
    *counter_dictionary = sort_word_frequency_counter(*counter_dictionary);
}

// Función que utiliza el algoritmo BubbleSort para ordenar un diccionario de manera descendente
WordFrequencyCounter *sort_word_frequency_counter(WordFrequencyCounter *counter_dictionary) {
    WordFrequencyCounter *current; // Índice para ir recorriendo el diccionario
    int swapped; // Variable para controlar si se deben intercambiar dos elementos
    if (counter_dictionary == NULL)
        return NULL;

    do {
        swapped = 0;
        current = counter_dictionary;

        while (current->next != NULL) { // Vamos recorriendo el diccionario
            if (current->count < current->next->count) { // Si se cumple el requisito se intercambian los elementos
                // Intercambiamos los elementos llamando a la funcion complementaria
                swap_word_frequency_counter(current, current->next);
                swapped = 1;
            }
            current = current->next; // Pasamos al siguiente elemento
        }
    } while (swapped);

    return counter_dictionary;
}
// Funcion complementaria del BubbleSort(compara dos elementos y los intercambia si el segundo es mayor)
void swap_word_frequency_counter(WordFrequencyCounter *a, WordFrequencyCounter *b) {
    WordFrequencyCounter temp;
    strncpy(temp.key, a->key, MAX_WORD_FREQUENCY_KEY);
    temp.count = a->count;

    strncpy(a->key, b->key, MAX_WORD_FREQUENCY_KEY);
    a->count = b->count;

    strncpy(b->key, temp.key, MAX_WORD_FREQUENCY_KEY);
    b->count = temp.count;
}
// Funcion para mostrar las 10 palabras mas frecuentes en las publicaciones
void print_word_frequency_count(WordFrequencyCounter *counter_dictionary) {
    int count = 0;
    printf("Word Frequency Count:\n");
    WordFrequencyCounter *current = counter_dictionary; // Índice para ir recorriendo el diccionario

    if (current == NULL) {
        printInfo(NO_FREQUENCY_WORDS);
    }

    while (current != NULL) {
        if (count == 10) {
            break;
        }
        // Mostramos cada palabra y las veces que aparece
        printf(" -%s: %d\n", current->key, current->count);
        current = current->next;
        count++;
    }
}