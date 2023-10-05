#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int *vI;
    char *vC;

    int *i;
    int *len;

    // ALLOCAZIONE DINAMICA: MALLOC (memory allocation), restituisce un puntatore di void [*void]
    i = (int*)malloc(sizeof(int));
    len = (int*)malloc(sizeof(int));

    *len = 10;

    printf("Address puntatore: %p\nAddress in puntatore: %p\nContenuto della cella puntata: %d",&len, len, *len);

    //ALLOCAZIONE DINAMICA ARRAY: MALLOC

    vC = (char*)malloc(sizeof(char) * (*len));
    srand(time(NULL));
    printf("\n\nMALLOC\n");
    //Caricamento vC
    for(*i = 0; *i < *len; (*i)++)
        *(vC+*i) = 'a' + rand()%('a'-'z');
    //Stampa vC
    for(*i = 0; *i < *len; (*i)++)
        printf("%c ",*(vC+(*i)));
    printf("\n");

    //ALLOCAZIONE DINAMICA ARRAY: CALLOC, restituisce un puntatore di void (*void)

    vI = (int*)calloc(*len, sizeof(int));
    //Caricamento
    for(*i = 0; *i < *len; (*i)++)
        *(vI + (*i)) = 1 + rand()%(*len);
    //Stampa
    for(*i = 0; *i < *len; (*i)++)
        printf("%d ",*(vI + (*i)));
    printf("\n");

    //ALLOCAZIONE DINAMICA ARRAY: REALLOC, restituisce un puntatore dello stesso tipo del primo parametro passato

    printf("\n\nREALLOC\n");

    *len = 15;

    vI = realloc(vI, (*len * sizeof(int))); //tipo Array.Resize(array, len)
    //Stampa
    for(*i = 0; *i < *len; (*i)++)
        printf("%d ",*(vI + (*i)));
    printf("\n");

    // FREE --> rilascio risorse allocate in memoria

    printf("\n\nFREE\n");
    free(vC);
    free(vI);
    free(len);
    free(i);

    printf("\n----vC----\nAddress puntatore: %p\nAddress in puntatore: %p\nContenuto della cella puntata: %d\n",&vC, vC, *vC);
    printf("\n----vI----\nAddress puntatore: %p\nAddress in puntatore: %p\nContenuto della cella puntata: %d\n",&vI, vI, *vI);
    printf("\n----len----\nAddress puntatore: %p\nAddress in puntatore: %p\nContenuto della cella puntata: %d\n",&len, len, *len);
    printf("\n----i----\nAddress puntatore: %p\nAddress in puntatore: %p\nContenuto della cella puntata: %d\n",&i, i, *i);

    return 0;
}
