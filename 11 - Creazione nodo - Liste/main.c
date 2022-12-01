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
Dipendenti* delByPos(Dipendenti* testa, int pos);

void stampaLista(Dipendenti* testa);
int contaNodi(Dipendenti* testa);

int main()
{
    Dipendenti *testa = NULL;
    int pos = 0;

    srand(time(NULL));

    testa = addOnHead(testa);
    testa = addOnTail(testa);
    testa = addOnTail(testa);

    printf("\n");
    stampaLista(testa);

    printf("\n\n\nCi sono %d nodi\n", contaNodi(testa));

    printf("\nInserisci posizione per aggiungere --> ");
    scanf("%d", &pos);
    fflush(stdin);

    testa = addByPos(testa, pos);

    stampaLista(testa);

    pos = 0;
    do{
        printf("\nInserisci posizione per eliminare --> ");
        scanf("%d", &pos);
    }while(pos <= 0 || pos >= contaNodi(testa));

    testa = delByPos(testa, pos);

    stampaLista(testa);
    return 0;
}

Dipendenti* delByPos(Dipendenti* testa, int pos){
    Dipendenti* Lista;
    Dipendenti* nodo;

    Lista = testa;

    for(int i = 0; i < pos - 1; i++)
        Lista = Lista->next;

    nodo = NULL;
    nodo->next = Lista->next;
    Lista->next = nodo;

    return testa;
}

Dipendenti* addByPos(Dipendenti* testa, int pos){
    Dipendenti* Lista;
    Dipendenti* nodo;

    if(pos <= 1)
        testa = addOnHead(testa);
    else{
        if(pos > contaNodi(testa))
            testa = addOnTail(testa);
        else{
            nodo = nuovoDipendente();
            Lista = testa;

            for(int i = 1; i < pos - 1; i++)
                Lista = Lista->next;

            nodo->next = Lista->next;
            Lista->next = nodo;
        }
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

    if(nodo == NULL)
        printf("\nLista vuota");
    else{
        printf("\nLISTA DIPENDENTI\n\n");
        printf("Matr.\tCognome\tEta\n\n");
        while (nodo != NULL) {
            printf("%s\t%s\t%d\n", nodo->matricola, nodo->cognome, nodo->eta);
            nodo = nodo->next;
        }
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

    if(testa == NULL) // SE E' NULL NON CI SONO NODI NELLA LISTA (� il primo nodo in assoluto)
        testa = nodo;
    else{
        nodo->next = testa; // sposta in seconda posizione testa
        testa = nodo; // e in prima posizione mette un nuovoDipendente
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
