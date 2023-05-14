#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LIKINGS 5
#define MAX_USUARIS 33
#define MAX_LENGTH 50

typedef struct user_t{
    char Username[MAX_LENGTH];
    int Age;
    char Mail[MAX_LENGTH];
    char Location[MAX_LENGTH];
    char List_Likings[MAX_LIKINGS][MAX_LENGTH];
    struct user_t* next; // punter al següent usuari de la llista
}User;


int menu(int stop){
    User * head = NULL;
    head = (User*) malloc(sizeof(User));// Cream el punter que apunta al primer usuari de la llista//

    // booleà per controlar quan sortir del menu

    while (stop == 0){

        int opcio;

        printf("\n--------MENU--------\n");
        printf("1. Insertar un nou usuari\n");
        printf("2. Llistar tots els usuaris\n");
        printf("3. Operar como un usuari específic\n");
        printf("4. Sortir\n");
        printf("--------------------\n");
        printf("Tria una opció: ");
        scanf("%d", &opcio);

        if(opcio == 1){

            User* usuari = head;
            if(usuari->next == NULL){ //Comprovam si la llista està buida
                printf("Usuari:");
                scanf("%s",usuari->Username);
                printf("Edat:");
                scanf("%d",&usuari->Age);
                printf("Correu:");
                scanf("%s",usuari->Mail);
                printf("Ubicació:");
                scanf("%s",usuari->Location);
                printf("Hobbies:");
                scanf("%s, %s, %s, %s, %s",usuari->List_Likings[0],usuari->List_Likings[1],usuari->List_Likings[2],
                      usuari->List_Likings[3],usuari->List_Likings[4]);
            }
            else if (usuari->next != NULL){
                while (usuari != NULL){ //Mentre no trobem el punter al darrer element anem recorrent la llista
                    usuari = usuari->next;
                }
                //Un cop tenim el darrer element, afegim el nou usuari al final de la llista
                usuari->next = (User*) malloc(sizeof(User)); //Reservam espai de memòria per el nou usuari

                printf("Usuari:");
                scanf("%s",usuari->next->Username);
                printf("Edat:");
                scanf("%d",&usuari->next->Age);
                printf("Correu:");
                scanf("%s",usuari->next->Mail);
                printf("Ubicació:");
                scanf("%s",usuari->next->Location);
                printf("Hobbies:");
                scanf("%s, %s, %s, %s, %s",usuari->next->List_Likings[0],usuari->next->List_Likings[1],usuari->next->List_Likings[2],
                      usuari->next->List_Likings[3],usuari->next->List_Likings[4]);

            }



            }
        else if(opcio == 2){
            User* index = head; /*Cream un punter per anar recorrent tota la llista i en primer lloc li assignem el puner
                                 al primer element*/
            if(index)
            while(index != NULL){
                printf("Usuari: %s\n",index->Username);
                index = index->next; //Passam al següent element
            }
        }
        else if(opcio == 3){
            stop = -1;
        }

        else if (opcio != 4){
            printf("L'opció que has triat no és vàlida, torna a intentar-ho");
            scanf("%d",&opcio);
        }
        return stop;
        }

    }



int main(){
    int stop = 0;
    while (stop == 0){
        menu(stop);
    }
}