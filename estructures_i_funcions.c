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
