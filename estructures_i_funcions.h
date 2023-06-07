#ifndef EDA2_ESTRUCTURES_I_FUNCIONS_H
#define EDA2_ESTRUCTURES_I_FUNCIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIKINGS 5
#define MAX_LENGTH 100


typedef struct solicitud {
    char emisor[50];
    char receptor[50];
    struct solicitud *next;
} SolicitudAmistad;

typedef struct {

    SolicitudAmistad *head;
    SolicitudAmistad *tail;

} lista_solicitudes;


typedef struct solicitud_aceptada{
    struct solicitud_aceptada *next;
    char amic[MAX_LENGTH];
}solicitud_aceptada;

typedef struct {
    solicitud_aceptada *head;
}lista_amigos;

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
    lista_amigos amigos;

} User;


void wordCount(char publicacion[MAX_LENGTH], WordCount *countArray);
WordCount dicionario_global;
void imprimirPalabrasFrecuentes(WordCount* diccionario);
User *find_user(User *head, char username[MAX_LENGTH]);
void insert_user(User **head);
void read_users_from_file(User **head);
void realizar_publicacion(User *user);
void listar_mis_publicaciones(User *head);
void listar_publicaciones(User *head);
void send_friend_request(User *sender, User *recipient);
void anadir_amigo(User *user,char amic[MAX_LENGTH]);
void mostrar_amigos(User *user);
void handle_friend_requests(User *user);
void menu(User **head);


#endif //EDA2_ESTRUCTURES_I_FUNCIONS_H
