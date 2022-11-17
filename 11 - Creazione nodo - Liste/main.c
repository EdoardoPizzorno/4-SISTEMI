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
Dipendenti* addOnTail(Dipendenti* testa); // AGGIUNGE IN CODA
Dipendenti* addByPos(Dipendenti* testa, int pos);
void stampaLista(Dipendenti* testa);
int contaNodi(Dipendenti* testa);

int main()
{
    Dipendenti *testa = NULL;
    int pos = 0;
    int len_lista = 0;

    srand(time(NULL));

    testa = addOnHead(testa);
    testa = addOnHead(testa);
    testa = addOnTail(testa);

    printf("\n");
    stampaLista(testa);

    len_lista = contaNodi(testa);
    printf("\nCi sono %d nodi\n", len_lista);

    do{
        printf("\nInserisci posizione --> ");
        scanf("%d", &pos);
    }while(pos < 0 || pos > len_lista);

    testa = addByPos(testa, pos);

    stampaLista(testa);
    return 0;
}

Dipendenti* addByPos(Dipendenti* testa, int pos){
    Dipendenti* nodo;
    int i = 0;

    nodo = testa;

    while(i != pos){
        nodo = nodo->next;
        if(i == pos - 1){
            getchar();
            nodo->next = nuovoDipendente();
        }
        i++;
    }

    return testa;
}

int contaNodi(Dipendenti* testa){
    Dipendenti* nodo;
    int cont = 0;

    nodo = testa;

    while (nodo != NULL) {
        cont++;
        nodo = nodo->next;
    }
    return cont;
}
void stampaLista(Dipendenti* testa){
    Dipendenti* nodo;

    nodo = testa;

    while (nodo != NULL) {
        printf("%s - %d - %s\n", nodo->cognome, nodo->eta, nodo->matricola);
        nodo = nodo->next;
    }
}

Dipendenti* addOnTail(Dipendenti* testa){
    Dipendenti* nodo;
    Dipendenti* Lista;

    nodo = nuovoDipendente();

    if(testa == NULL)
        testa = nodo;
    else{
        Lista = testa; // salvo indirizzo di testa in Lista
        while(Lista->next != NULL) // ciclo fino a quando la Lista non contiene NULL (quindi siamo arrivati alla coda)
            Lista = Lista->next;
        Lista->next = nodo;
    }
    return testa;
}

Dipendenti* addOnHead(Dipendenti* testa){
    Dipendenti* nodo;
    nodo = nuovoDipendente();

    if(testa == NULL) // SE E' NULL NON CI SONO NODI NELLA LISTA
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

    /// INSERIMENTO MATRICOLA
    for(int i = 0; i < 2; i++)
        matr[i] = 'A' + rand() % ('Z'-'A');
    for(int i = 2; i < 4; i++)
        matr[i] = '0' + rand() % ('9'-'0');

    /// INSERIMENTO COGNOME
    printf("Cognome ---> ");
    gets(cogn);

    /// INSERIMENTO ETA
    //printf("Eta --> ");
    //scanf("%d", &eta);
    eta = 18 + rand() % (65 - 18);

    dip = (Dipendenti*) malloc(sizeof(Dipendenti));

    strcpy(dip->cognome, cogn);
    dip->eta = eta;
    strcpy(dip->matricola, matr);
    dip->next = NULL;

    return dip;
}
