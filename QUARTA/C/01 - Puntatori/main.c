#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=8;
    int *p;

    printf("Size(int): %d\nSize(float): %d\nSize(char): %d",sizeof(int), sizeof(char), sizeof(float));

    printf("Size(int*): %d\nSize(float*): %d\nSize(char*): %d",sizeof(int*), sizeof(char*), sizeof(float*));

    //Leggo contenuto/indirizzo n
    printf("Contenuto n: %d - Indirizzo di n: %p\n", n, &n);

    //Leggo contenuto/indirizzo *p
    printf("Contenuto p: %d - Indirizzo di p: %p\n", p, &p);

    p=&n; //in p metto l'indirizzo di n
    printf("Indirizzo p dopo assegnazione a n: %p", p);

    //stampo contenuto di n
    printf("\nContenuto di n: (classico)%d - (puntatore)%d", n, *p); //con *p mi stampa 8 perchè c'è il contenuto di n
    n=6;
    *p = 5;
    printf("\nContenuto di n: (classico)%d - (puntatore)%d", n, *p); //ora entrambe diventano 8 perchè sto lavorando sulla stessa cella
    return 0;
}
