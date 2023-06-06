#include "estructures_i_funcions.h"


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