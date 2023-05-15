#include <stdio.h>
#include <stdlib.h>

#define MAX_LIKINGS 5
#define MAX_LENGTH 50

typedef struct user_t{
    char Username[MAX_LENGTH];
    int Age;
    char Mail[MAX_LENGTH];
    char Location[MAX_LENGTH];
    char List_Likings[MAX_LIKINGS][MAX_LENGTH+1];
    struct user_t *next; // punter al següent usuari de la llista
}User;



int menu(int *stop, User **head){



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
            printf("Hobbies:");
            scanf("%s, %s, %s, %s, %s",node->List_Likings[0],node->List_Likings[1],node->List_Likings[2]
            ,node->List_Likings[3],node->List_Likings[4]);
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
    User *current = head;
    while (current != NULL) {
        User *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}