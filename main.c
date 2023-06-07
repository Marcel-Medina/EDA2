#include "estructures_i_funcions.h"


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
                while (sub_option != 7) {
                    printf("\nAcciones del usuario:\n");
                    printf("1. Realizar una publicacion\n");
                    printf("2. Mostrar tus publicaciones\n");
                    printf("3. Ver todas las publicaciones\n");
                    printf("4. Enviar una solicitud de amistad\n");
                    printf("5. Gestionar solicitudes de amistad\n");
                    printf("6. Ver lista de amigos\n");
                    printf("7. Salir\n");
                    printf("Selecciona una opcion: ");
                    scanf("%d", &sub_option);
                    getchar();

                    if (sub_option == 1) {
                        realizar_publicacion(current_user);


                    } else if (sub_option == 2) {
                        listar_mis_publicaciones(current_user);
                    } else if (sub_option == 3) {
                        listar_publicaciones(*head);
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
                    }
                    else if(sub_option == 6){
                        mostrar_amigos(current_user);
                    }
                    else if (sub_option == 7) {
                        printf("\nVolviendo al menu principal.\n");
                    }
                    else {
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
