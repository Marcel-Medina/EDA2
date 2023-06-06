#include "estructures_i_funcions.h"

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
    printf("Quieres ver las solicitudes aceptadas?\n");
    printf("1.SI\n2.NO");
    scanf("%d",&llista_amics);
    if(llista_amics == 1){
        solicitudes_aceptadas(user);
    }
}