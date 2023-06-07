#include "estructures_i_funcions.h"

void send_friend_request(User *sender, User *recipient) {
    SolicitudAmistad *new_request = (SolicitudAmistad *)malloc(sizeof(SolicitudAmistad)); //Creamos la nueva solicitud de amistad
    strcpy(new_request->emisor, sender->Username); //Copiamos el nombre del receptor y del emisor en la nueva solicitud
    strcpy(new_request->receptor, recipient->Username);
    new_request->next = NULL; //Como la nueva solicitud sera la última de la cola le asignamos NULL al puntero next
    if (recipient->llista.head == NULL) { //Comprobamos que la lista no esté vacía
        recipient->llista.head = new_request;
        recipient->llista.tail = new_request;
    }
    else {
        recipient->llista.tail->next = new_request; // A la última solicitud le asignamos como next la nueva solicitud
        recipient->llista.tail = new_request; // Asignamos la nueva solicitud como la última de la lista
    }
}

void anadir_amigo(User *user,char amic[MAX_LENGTH]){
    solicitud_aceptada *amigo_nuevo = (solicitud_aceptada *) malloc(sizeof(solicitud_aceptada));
    strcpy(amigo_nuevo->amic,amic);
    amigo_nuevo->next == NULL;

    if (user->amigos.head == NULL) {
        user->amigos.head = amigo_nuevo;
    } else {
        solicitud_aceptada *index = user->amigos.head;
        while (index->next != NULL) {
            index = index->next;
        }
        index->next = amigo_nuevo;
    }

}

void mostrar_amigos(User *user){
    solicitud_aceptada *index = user->amigos.head;
    if (index == NULL){
        printf("No tienes amigos");
    }
    else{
        while(index != NULL){
            printf("-%s\n",index->amic);
            index = index->next;
        }
    }
}

void handle_friend_requests(User *user) {
    SolicitudAmistad *index = user->llista.head; //Creamos un índice para ir recorriendo la lista de solicitudes de amistad y empezamos por el head
    if(index == NULL){ //Si el head es NULL significa que no hay ninguna solicitud
        printf("No tienes solicitudes de amistad");
    }
    int opcion = 0;
    while (index != NULL) {//Vamos recorriendo la lista de solicitudes
        printf("Tienes una solicitud de amistad de: %s\n", index->emisor);
        printf("1.ACEPTAR\n2.RECHAZAR\n");
        scanf("%d",&opcion);
        getchar();
        if(opcion == 1){//Añadimos el amigo a la lista del usuario
            anadir_amigo(user,index->emisor);
        }
        else if (opcion != 2){
            printf("Opción incorrecta");
        }
        user->llista.head = user->llista.head->next;
        if(user->llista.head == user->llista.tail){
            user->llista.tail = NULL;
        }
        index = index->next;
    }
}
