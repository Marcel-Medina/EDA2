#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIKINGS 5
#define MAX_LENGTH 50

typedef struct llista_solicituds{
    char persona;
    struct llista_solicituds *tail;
    struct llista_solicituds *head;
}Solicituds;

typedef struct user_t{
    char Username[MAX_LENGTH];
    int Age;
    char Mail[MAX_LENGTH];
    char Location[MAX_LENGTH];
    char List_Likings[MAX_LIKINGS][MAX_LENGTH];
    struct user_t *next; // punter al següent usuari de la llista
    Solicituds llista;
}User;



int linear_search(User* index,char usuari[MAX_LENGTH]){
    while(index->Username != usuari){
        index = index->next;
    }
    if(index == NULL){
        return -1;
    }
    else{
        return 0;
    }
}


int menu(int *stop, User **head){ /*Reben com a paràmetres l'adreça de stop i de head, per poder anar
                                    modificant els seus valors*/

    while (*stop == 0){

        *stop = 0;
        int opcio;

        printf("\n--------MENU--------\n");
        printf("1. Insertar un nou usuari\n");
        printf("2. Llistar tots els usuaris\n");
        printf("3. Operar como un usuari específic\n");
        printf("4. Sortir\n");
        printf("--------------------\n");
        printf("Tria una opció:");
        scanf("%d", &opcio);

        if(opcio == 1){

            User *node = (User*)malloc(sizeof(User)); //Reservam memèoria pel nou usuari
            User *index = *head; //Cream un punter per anar recorrent la llista


            if(*head == NULL){ /* Si la llista està buida, el nou node serà el primer de la llista,
                                 i per tant el head apuntarà a aquest node*/
                *head = node;
                node->next = NULL;
            }
            else{
                while(index->next != NULL){//Cercam el darrer node
                    index = index->next;
                }
                index->next = node; //El next del que era el darrer node serà el node que hem insertat
                node->next = NULL; //El next del nou node serà NULL, perquè és el darrer element
            }

            printf("Usuari:");
            scanf("%s",node->Username);
            printf("Edat:");
            scanf("%d",&node->Age);
            printf("Ubicació:");
            scanf("%s",node->Location);
            printf("Correu:");
            scanf("%s",node->Mail);
            getchar();
            printf("5 Hobbies:");
            char input[MAX_LIKINGS*MAX_LENGTH]; //Cream un string on emmagatzarem tota la línia
            fgets(input, sizeof(input),stdin);
            char * token= strtok(input,",");//Dividim tota la linia a través de strtok que utilitza la coma com a delimitador
            int i = 0;
            while(token != NULL && i<MAX_LIKINGS){
                strcpy(node->List_Likings[i],token);//Cada string entre les comes l'emmagatzemem als hobbies de l'usuari
                token = strtok(NULL,",");
                i++;
            }

            }

        else if(opcio == 2){
            User* index = *head; /*Cream un punter per anar recorrent tota la llista i en primer lloc li assignem el punter
                                 al primer element*/
            if(index == NULL){
                printf("La llista està buida");
            }
            while(index != NULL){
                printf("Usuari: %s\n",index->Username);
                index = index->next; //Passam al següent element
            }
        }
        else if(opcio == 3){

            printf("Introdueix el nom de l'usuari:");
            char usuari[MAX_LENGTH];
            scanf("%s",usuari);
            User *index = *head; //Índex per anar recorrent la llista enllaçada

            if(linear_search(index,usuari) == -1){
                printf("No existeix l'usuari");
            }
            else if(linear_search(index,usuari) == 0){
                int eleccio; //El submenú per a cada usuari
                printf("\n--------SUBMENU--------\n");
                printf("1. Enviar sol·licituds d'amistat\n");
                printf("2. Gestionar les sol·licituds pendents\n");
                printf("3. Realitzar una publicació\n");
                printf("4. Llistar les publicacions de l'usuari seleccionat\n");
                printf("5. Tornar al menu principal\n");
                printf("--------------------\n");
                printf("Tria una opció:");
                scanf("%d",&eleccio);
                if (eleccio == 1){
                    printf("Introdueix el nom de l'usuari al qual vols enviar la sol·licitud");
                    char amic[MAX_LENGTH];
                    scanf("%s",amic);
                    int x;
                    x = linear_search(*head,amic);
                    if (x == -1){
                        printf("L'usuari no existeix");
                    }
                    else{
                        printf("L'usuari existeix");
                    }

                }
            }

        }
        else if(opcio == 4){
            *stop = -1;
        }

        else if (opcio != 4){
            printf("L'opció que has triat no és vàlida, torna a intentar-ho");
            scanf("%d",&opcio);
        }
        return *stop;
        }

    }

int main(){
    int stop = 0;
    User *head = NULL;
    while (menu(&stop,&head) != -1){
    }
    //Un cop hem acabat alliberam memòria

    User *current = head;
    while (current != NULL) {
        User *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}