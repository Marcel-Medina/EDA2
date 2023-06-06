#include "estructures_i_funcions.h"

void wordCount(char publicacion[MAX_LENGTH], WordCount *countArray) {
    char *copy = strdup(publicacion);
    char *word = strtok(copy, " ");

    while (word != NULL) {
        int found = 0;

        for (int i = 0; i < countArray->count_total; i++) {
            if (strcmp(countArray[i].dicionario, word) == 0) {
                countArray[i].count_word++;
                found = 1;
                break;
            }
        }

        if (found == 0) {
            if (countArray->count_total == MAX_LENGTH) {
                printf("El número máximo de palabras se ha alcanzado. Algunas palabras pueden no contarse.\n");
                break;
            }

            strcpy(countArray[countArray->count_total].dicionario, word);
            countArray[countArray->count_total].count_word = 1;
            countArray->count_total++;
        }

        word = strtok(NULL, " ");
    }

}



void imprimirPalabrasFrecuentes(WordCount* diccionario) {
    // Ordenar el diccionario en orden descendente por conteo usando bubble sort
    for (int i = 0; i < diccionario->count_total - 1; i++) {
        for (int j = 0; j < diccionario->count_total - i - 1; j++) {
            if (diccionario[j].count_word< diccionario[j + 1].count_word) {
                WordCount temp = diccionario[j];
                diccionario[j] = diccionario[j + 1];
                diccionario[j + 1] = temp;
            }
        }
    }

    // Imprimir las primeras MAX_WORDS palabras frecuentes
    printf("Las palabras más frecuentes son:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s: %d\n", diccionario[i].dicionario, diccionario[i].count_word);
    }
}
