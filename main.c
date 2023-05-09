#include <stdio.h>
#include <stdlib.h>
#define MAX_LIKINGS 5
#define MAX_USUARIS 33

typedef struct{
    char Username;
    int Age;
    char Mail;
    char Location;
    char List_Likings[MAX_LIKINGS];
}User;


int menu(){

    User* usuaris = malloc(MAX_USUARIS*sizeof(User));
    int index = 0;
    int opt = -1;
    while (opt == -1){
        scanf("%d",&opt);
        if(opt == 1){
            if (index < 33)
                printf("Usuari:");
                scanf("%s",&usuaris[index].Username);
                printf("Edat:");
                scanf("%d",&usuaris[index].Age);
                printf("Correu:");
                scanf("%s",&usuaris[index].Mail);
                printf("Ubicació:");
                scanf("%s",&usuaris[index].Location);
                printf("%s, %s, %s, %s, %s",&usuaris[index].List_Likings[0],&usuaris[index].List_Likings[1],
                       &usuaris[index].List_Likings[2],&usuaris[index].List_Likings[3],&usuaris[index].List_Likings[0]);
        }
        else if(opt == 2){
            for (int i = 0; i < MAX_USUARIS;i++){
                if (usuaris[i].Username != NULL)
            }
        }
        else if(opt == 3){
            //Operar como usuario especifico
        }
        else if(opt == 4){
            //Salir
        }
        else {
            printf("L'opció que has triat no és vàlida, torna a intentar-ho");
            scanf("%d",&opt);
        }
        return 0;
    }
}

int main(){
    int stop = 0;
    while (stop == 0){
        menu();
    }
    return 0;
}