#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 30

typedef struct dipendente{
    char matricola[5];
    char cognome[MAX];
    int eta;
    struct dipendente *next;
} Dipendenti;

Dipendenti* nuovoDipendente();
Dipendenti* addOnHead(Dipendenti* testa);
void stampaDipendente(Dipendenti* testa);

int main()
{
    srand(time(NULL));

    Dipendenti *testa;

    testa = addOnHead(testa);

    stampaDipendente(testa);
    return 0;
}

void stampaDipendente(Dipendenti* testa){
    printf("STAMPA DIPENDENTE\n");
    printf("% \n % \n % \n % \n % \n ", );
}

Dipendenti* addOnHead(Dipendenti* testa){
    Dipendenti* nodo;

    nodo = nuovoDipendente();

    if(testa == NULL) // testa è vuoto quindi posso metterci nodo
        testa = nodo;
    else{
        nodo->next = testa;
        testa = nodo;
    }
    return testa;
}

Dipendenti* nuovoDipendente(){
    Dipendenti* dip;

    char matr[5];
    char cogn[MAX];
    int eta;
    // INSERIMENTO MATRICOLA
    for(int i = 0; i < 2; i++)
        matr[i] = 'A' + rand() % ('A'-'Z');
    for(int i = 0; i < 4; i++)
        matr[i] = '0' + rand() % ('0'-'9');
    // INSERIMENTO COGNOME
    printf("Cognome ---> ");
    gets(cogn);
    // INSERIMENTO ETA
    printf("Eta --> ");
    scanf("%d", &eta);

    strcpy(dip->matricola, matr);
    strcpy(dip->cognome, cogn);
    dip->eta = eta;

    return dip;
}
