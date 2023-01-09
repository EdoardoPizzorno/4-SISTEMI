#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef int bool;

typedef struct candidato
{
    char matricola[6];
    char cognome[15];
    char regione[15];
    int punti1, punti2, punti3;
    float media;
    struct candidato *next;
}Candidati;

Candidati* loadFromFile(Candidati *head, char* file_name_candidati, char* file_name_punteggi);
Candidati* addOnHead(Candidati *head, char matr[], char cogn[], char reg[], int p1, int p2, int p3); // Add nodo in testa alla lista
Candidati* addOnTail(Candidati *head, char matr[], char cogn[], char reg[], int p1, int p2, int p3); // Add nodo in coda alla lista
Candidati* nuovoCandidato(char matr[], char cogn[], char reg[], int p1, int p2, int p3);
int contaNodi(Candidati *head);
void showList(Candidati *head);

Candidati * nuovoCandidato(char matr[], char cogn[], char reg[], int p1, int p2, int p3)
{
    Candidati *nodo;

    // CARICAMENTO DATI IN NUOVO NODO
    nodo = (Candidati*) malloc(sizeof(Candidati));

    strcpy(nodo->matricola, matr);
    strcpy(nodo->cognome, cogn);
    strcpy(nodo->regione, reg);
    nodo->punti1 = p1;
    nodo->punti2 = p2;
    nodo->punti3 = p3;
    /* TODO: CALCOLO DELLA MEDIA */

    nodo->next = NULL;
    return nodo;
}

Candidati * addOnHead(Candidati *testa, char matr[], char cogn[], char reg[], int p1, int p2, int p3)
{
    Candidati *nodo;

    nodo = nuovoCandidato(matr, cogn, reg, p1, p2, p3);

    if (testa == NULL)
        testa = nodo;
    else
    {
        nodo->next = testa;
        testa = nodo;
    }
    return testa;
}
Candidati * addOnTail(Candidati *testa, char matr[], char cogn[], char reg[], int p1, int p2, int p3)
{
    Candidati *nodo, *pLista;

    nodo = nuovoCandidato(matr, cogn, reg, p1, p2, p3);

    if(testa == NULL)
        testa = addOnHead(testa, matr, cogn, reg, p1, p2, p3);
    else
    {
        pLista = testa;
        while(pLista->next != NULL)
            pLista = pLista->next;
        pLista->next = nodo;
    }
    return testa;
}

Candidati* loadFromFile(Candidati *head, char* file_name_candidati, char* file_name_punteggi)
{
    FILE *fpC, *fpP;
    bool trovato;
    char row_file[20+1];
    int p1, p2, p3;
    char matr[10], cogn[20], reg[20];
    char matrP[10];
    char sp1[5], sp2[5], sp3[5];
    int i=0, j=0;
    fpC = fopen(file_name_candidati, "r"); // Apertura file in modalità read

    if (fpC == NULL && fpP == NULL)
        printf("Apertura files non riuscita\n");
    else{
        while(!feof(fpC)){ // Scorro il file, riga per riga, fino a quando non raggiungo EOF
            fscanf(fpC, "%s %s %s", matr, cogn, reg);
            //printf("LETTO: %s %s %s\n", matr, cogn, reg);
            trovato = FALSE;
            fpP = fopen(file_name_punteggi, "r"); // Apertura file in modalità read
            while((!feof(fpP)) && trovato==FALSE){
                fscanf(fpP, "%s %s %s %s", matrP, sp1, sp2, sp3);
                if (strcmp(matr, matrP) == 0)
                    trovato = TRUE;
            }
            fclose(fpP); // Chiusura del file

            if (trovato == TRUE){
                p1 = atoi(sp1);
                p2 = atoi(sp2);
                p3 = atoi(sp3);
                head = addOnTail(head, matr, cogn, reg, p1, p2, p3);
            }
        }
    }
    fclose(fpC); // Chiusura del file
    return head;
}
int contaNodi(Candidati *head)
{
    int tot = 0;
    Candidati *pDip;
    pDip = head;

    while(pDip != NULL)
    {
        tot++;
        pDip = pDip->next;
    }
    return tot;
}
void showList(Candidati *head){
    Candidati *pLista;

    if (head == NULL)
        printf("Lista Vuota\n");
    else{
        pLista = head;
        printf("LISTA CANDIDATI\n");
        printf("Matr.\tPunti1\tPunti2\tPunti3\tCognome (Regione)\t\t\n");
        do{
            /* TODO: MODIFICARE PER LA CORRETTA VISUALIZZAZIONE DELLE MEDIE */
            printf("%s\t%d\t%d\t%d\t%s (%s)\n",
                    pLista->matricola, pLista->punti1, pLista->punti2, pLista->punti3, pLista->cognome, pLista->regione);
            pLista = pLista->next;
        }
        while(pLista != NULL);
    }
}
