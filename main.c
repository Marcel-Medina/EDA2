#include <stdio.h>

#define MAX_LIKINGS = 5

typedef struct{
    char Username;
    int Age;
    char Mail;
    char Location;
    char List_Likings[MAX_LIKINGS];
}User;


int menu(){
    int opt = -1;
    while (opt == -1){
        scanf("%d",&opt);
        if(opt == 1){
            //Insertar nuevo usuario
        }
        else if(opt == 2){
            //Listar todos los usuarios existentes
        }
        else if(opt == 3){
            //Operar como usuario especifico
        }
        else if(opt == 4){
            //Salir
        }
        else {
            printf("La opción que has elegído no és valida, vuelva a intentar-lo")
            scanf("%d",&opt);
        }
    }
}
