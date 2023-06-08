#ifndef EDA2_USER_H
#define EDA2_USER_H



#define MAX_NAME_LENGTH 50
#define MAX_MAIL_LENGTH 100
#define MAX_LOCATION_LENGTH 50
#define MAX_HOBBIES_LENGTH 5
#define MAX_SINGLE_HOBBY_LENGTH 40
#define MAX_PUBLICATION_TEXT_LENGTH 120
#define MAX_WORD_FREQUENCY_KEY 50
#define USER_CREATED_SUCCESSFULLY_MESSAGE "User created successfully."
#define USER_NOT_FOUND "User not found."
#define LIST_USERS_SUCCESSFULLY_MESSAGE "Listed all users from the memory."
#define FRIEND_REQUEST_ACCEPTED "Friend request accepted."
#define FRIEND_REQUEST_REJECTED "Friend request rejected."
#define PUBLICATION_CREATED_SUCCESSFULLY "Joke posted successfully."
#define NO_AVAILABLE_PUBLICATION "No available joke."
#define MEMORY_ALLOCATION_FAILED "Memory allocation failed."
#define NO_FREQUENCY_WORDS "No available frequency words."

#include <stdbool.h>

// Estructura de una publicación que contiene el texto y un puntero a la siguiente publicación
typedef struct Publication {
    char text[MAX_PUBLICATION_TEXT_LENGTH];
    struct Publication *next;
} Publication;

//Estructura de una solicitud de amistad que contiene el nombre del receptor, el del emisor y un puntero
//a la siguiente solicitud
typedef struct FriendRequest {
    char sender[MAX_NAME_LENGTH];
    char recipient[MAX_NAME_LENGTH];
    bool accepted;
    struct FriendRequest *next;
} FriendRequest;

// Estructura de la cola de solicitudes de amistades, que contiene el puntero al primer elemento y otro al último
typedef struct FriendRequestQueue {
    FriendRequest *front;
    FriendRequest *rear;
} FriendRequestQueue;

// Estructura de la lista de amigos, que contiene el nombre del usuario y un puntero a la siguiente estructura
typedef struct FriendList {
    char username[MAX_NAME_LENGTH];
    struct FriendList* next;
} FriendList;

// Estructura para contar las veces que aparece una palabra, que contiene la llave, el contador y un puntero
// al siguiente elemento
typedef struct WordFrequencyCounter{
    char key[MAX_WORD_FREQUENCY_KEY];
    int count;
    struct WordFrequencyCounter *next;
} WordFrequencyCounter;

// Estructura de un usuario,que contiene su nombre, su edad, su correo, sus hobbies (lista de doble entrada,donde la
// primera representada la posición del hobbie y la longitud del hobbie), un puntero a la primera solicitud de
// amistad, un puntero al primer amigo de la lista, un puntero a la primer publicación y puntero al siguiente usuario
typedef struct User {
    char name[MAX_NAME_LENGTH];
    int age;
    char email[MAX_MAIL_LENGTH];
    char current_location[MAX_LOCATION_LENGTH];
    char hobbies[MAX_HOBBIES_LENGTH][MAX_SINGLE_HOBBY_LENGTH];
    FriendRequestQueue *friend_requests;
    FriendList *friend_list;
    Publication *publications;
    struct User *next;
} User;

User *create_user(const char *username, int age, const char *email,
                  const char *location, const char hobbies[MAX_HOBBIES_LENGTH][MAX_SINGLE_HOBBY_LENGTH]);

void fill_user_data(User *user);

void add_user(User **userList, User *newUser);

void print_user_list(User *userList);

void sort_user_list_by_name(User **head);
// Linear search user
User *find_user(User *userList, const char *username);

void send_friend_request(User *sender, User *recipient);

void handle_friend_requests(User *user, User *head);

void initializeQueue(FriendRequestQueue *queue);

bool is_queue_empty(FriendRequestQueue *queue);

void enqueue_friend_request(FriendRequestQueue *queue, FriendRequest *request);

void dequeue_friend_request(FriendRequestQueue *queue);


void display_friend_list(User* user);

void create_publication(User *user, const char *text, WordFrequencyCounter **counter_dictionary);

void print_user_publications(User *user);

void frequency_word_count(char *publication_text, WordFrequencyCounter **counter_dictionary);

WordFrequencyCounter *sort_word_frequency_counter(WordFrequencyCounter *counter_dictionary);

void swap_word_frequency_counter(WordFrequencyCounter *a, WordFrequencyCounter *b);

void print_word_frequency_count(WordFrequencyCounter *counter_dictionary);

#endif //EDA2_USER_H
