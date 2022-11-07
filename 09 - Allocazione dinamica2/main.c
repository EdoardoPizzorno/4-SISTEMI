#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFFER 50 + 1
#define TRUE 1
#define FALSE 0

typedef int bool;

void menu(char *sc){
    system("@cls||clear");

    printf("a. Dato vettore v1 di interi casuali caricare in v2 solo i valori pari\n");
    printf("b. Inverti contenuto stringa\n");
    printf("c. Concatena stringa s1 ed s2\n");
    printf("d. Sposta in stringa s2 solo caratteri che non si ripetono in s1\n");
    printf("e. Splitta stringa\n");
    printf("q. ESCI\n");

    printf("Scelta --> ");
    scanf("%c",sc);
}
void caricaVetRnd(int* v, int *len);
void stampaVet(int* v, int *len);
int* copiaPari(int *v1, int *v2, int* len);
void invertiStringa(char *s);
void concatenaStringa(char* s1, char* s2);
void spostaInS2(char* s1, char* s2);
void splittaString(char *s1, char* s2);

void ordina(char* s);

int main()
{
    char *scelta;

    int* v1;
    int* v2;
    int *len1;
    int* len2;

    char* s1;
    char* s2;

    scelta = (char*)malloc(sizeof(char));

    srand(time(NULL));
    do{
        menu(scelta); //è già un puntatore

        switch(*scelta){
            case 'a':
            case 'A':
                getchar();

                len1 = (int*)malloc(sizeof(int)); //solo dopo questo posso caricare un valore intero

                do{
                    printf("Inserisci dimensione vettore --> ");
                    scanf("%d", len1);
                }while(*len1 <= 0);
                fflush(stdin);

                v1 = (int*)malloc(sizeof(int) * (*len1));
                v2 = (int*)malloc(sizeof(int) * (*len1));

                printf("\nVettore 1: \n");
                caricaVetRnd(v1, len1);
                stampaVet(v1, len1);

                len2 = copiaPari(v1, v2, len1);

                printf("\nVettore 2: \n");
                stampaVet(v2, len2);

                free(v1);
                free(v2);
                free(len1);
                free(len2);
                break;
            case 'b':
            case 'B':
                getchar();
                s1 = (char*)malloc(BUFFER * sizeof(int));
                printf("Inserisci stringa: ");
                gets(s1);

                invertiStringa(s1);
                printf("\nStringa invertita: %s", s1);

                free(s1);
                break;
            case 'c':
            case 'C':
                getchar();

                s1 = (char*)malloc(BUFFER * sizeof(int));
                fflush(stdin);
                printf("Inserisci prima stringa: ");
                gets(s1);

                s2 = (char*)malloc(BUFFER * sizeof(int));
                fflush(stdin);
                printf("Inserisci seconda stringa: ");
                gets(s2);

                concatenaStringa(s1, s2);
                printf("Stringa concatenata: %s", s1);

                free(s1);
                free(s2);
                break;
            case 'd':
            case 'D':
                getchar();

                s1 = (char*)malloc(sizeof(char));
                fflush(stdin);
                printf("Inserisci stringa: ");
                gets(s1);

                s2 = (char*)malloc(sizeof(char));
                spostaInS2(s1, s2);
                printf("\nStringa modificata: %s", s2);

                free(s1);
                free(s2);
                break;
            case 'e':
            case 'E':
                s1 = (char*)malloc(sizeof(char));
                fflush(stdin);
                printf("Inserisci stringa: ");
                gets(s1);

                s2 = (char*)malloc(sizeof(char));
                fflush(stdin);
                printf("\nInserisci carattere per fare la split: ");
                scanf("%c", s2);

                splittaString(s1, s2);

                getchar();
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
void splittaString(char* s1, char* s2){
    s1 = realloc(s1, sizeof(char) * strlen(s1) + 1);
}

void spostaInS2(char* s1, char* s2){
    s1 = realloc(s1, sizeof(char) * strlen(s1) + 1);
    s2 = realloc(s2, sizeof(char) * strlen(s2) + 1);

    char* aus;
    aus = realloc(s1, sizeof(char) * strlen(s1) + 1);

    int* cont;
    int* i;
    int* j;
    i = (int*)malloc(sizeof(int));
    j = (int*)malloc(sizeof(int));
    cont = (int*)malloc(sizeof(int));

    *cont = 0;

    ordina(aus);
    for(*i = 0; *i < strlen(s1); (*i)++){
        for(*j = 0; *j < strlen(aus); (*j)++){
            if(*(s1 + (*i)) == *(aus + (*j))){
                (*cont)++;
            }
        }
        if(*cont <= 1){
            *s2 = *(s1 + (*i));
            s2++;
        }
        *cont = 0;
    }
    s2 = '\0';
}
void ordina(char* s){
    int* i;
    int* j;
    int* posmin;

    i = (int*)malloc(sizeof(int));
    j = (int*)malloc(sizeof(int));
    posmin = (int*)malloc(sizeof(int));

    for(*i = 0; *i <= strlen(s) - 2; (*i)++){
        *posmin = *i;
        for(*j = (*i + 1); *j <= strlen(s) - 1; (*j)++){
            if(*(s + (*posmin)) > *(s + (*j)))
                *posmin = *j;
        }
        if(*posmin != *j){
            char* aus;
            aus = (char*)malloc(sizeof(char));
            *aus = *(s + (*i));
            *(s + (*i)) = *(s + (*posmin));
            *(s + (*posmin)) = *aus;
        }
    }
}
void concatenaStringa(char* s1, char* s2){
    s1 = realloc(s1, strlen(s1) + strlen(s2) + 1 * sizeof(char));
    s2 = realloc(s2, strlen(s2) + 1 * sizeof(char));

    s1 += strlen(s1);
    while(*s2 != '\0'){
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

void invertiStringa(char* s){
    char* pF;
    char* aus;

    aus = (char*)malloc(sizeof(char));
    s = realloc(s, sizeof(char) * strlen(s) + 1);

    pF = s + (strlen(s) - 1);

    while(s < pF){
        *aus = *s;
        *s = *pF;
        *pF = *aus;
        s++;
        pF--;
    }
}

int* copiaPari(int *v1, int *v2, int* len){
    int *i, *j;
    i = (int*)malloc(sizeof(int));
    j = (int*)malloc(sizeof(int));

    *j = 0;
    for(*i = 0; *i < *len; (*i)++){
        if(*(v1 + (*i)) % 2 == 0){
            *(v2 + (*j)) = *(v1 + (*i)); //v2[j] = v1[i];
            (*j)++;
        }
    }
    v2 = realloc(v2, (*j) * sizeof(int));
    return j;
}

void caricaVetRnd(int* v, int* len){
    int* i;
    i = (int*)malloc(sizeof(int));

    for(*i = 0; *i < *len; (*i)++)
        *(v + (*i)) = 1 + rand() % 10;
}
void stampaVet(int *v, int* len){
    int *i;
    i = (int*)malloc(sizeof(int));

    for(*i = 0; *i < *len; (*i)++)
        printf("%d ", *(v + (*i)));
    printf("\n");
}
