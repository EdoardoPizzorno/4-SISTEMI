#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER 50

typedef int bool;

void menu(char *sc){
    system("@cls||clear");

    printf("a. Dato vettore v1 di interi casuali caricare in v2 solo i valori pari\n");
    printf("b. \n");
    printf("c. \n");
    printf("d. \n");
    printf("q. ESCI\n");

    printf("Scelta --> ");
    scanf("%c",sc);
}
void caricaVetRnd(int* v, int *len);
void stampaVet(int* v, int *len);
int* copiaPari(int *v1, int *v2, int* len);

int main()
{
    char *scelta;

    int* v1;
    int* v2;
    int *len;

    scelta = (char*) malloc(sizeof(char));

    do{
        menu(scelta); //è già un puntatore

        switch(*scelta){
            case 'a':
            case 'A':
                printf("\nInserisci lunghezza dei vettori: ");
                scanf("%d",len);
                caricaVetRnd(v1, len);

                printf("\nVettore 1: \n");
                stampaVet(v1, len);

                //v2 = copiaPari(v1, v2, len); //bisogna fare un ciclo (?)

                printf("\nVettore 2: \n");
                stampaVet(v2, len);
                break;
            case 'b':
            case 'B':
                break;
            case 'c':
            case 'C':
                break;
            case 'd':
            case 'D':
                break;
            default:
                break;
        }
        fflush(stdin);
        getchar();
        system("@cls||clear");
    }while(*scelta != 'q' && *scelta != 'Q');
    printf("Premi per continuare...");
    return 0;
}
void caricaVetRnd(int* v, int* len){
    srand(time(NULL));
    int* i;

    v = (int*)calloc(*len, sizeof(int));

    for(*i = 0; *i < *len; (*i)++)
        *(v + (*i)) = 1 + rand()%BUFFER;
}
void stampaVet(int *v, int* len){
    int *i;

    v = (int*)calloc(*len, sizeof(int));

    for(*i = 0; *i < *len; (*i)++)
        printf("%d ",*(v + (*i)));
}
