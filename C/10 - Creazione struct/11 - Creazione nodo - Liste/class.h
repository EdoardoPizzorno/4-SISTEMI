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
Candidati* delByMatr(Candidati* testa,char matr[]);
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
    nodo->media = (float)(p1 + p2 + p3) / 3;
    nodo->next = NULL;
    return nodo;
}

Candidati* addOnHead(Candidati *testa, char matr[], char cogn[], char reg[], int p1, int p2, int p3)
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
Candidati* addOnTail(Candidati *testa, char matr[], char cogn[], char reg[], int p1, int p2, int p3)
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
        printf("Lista Canditati\n");
        printf("Matr.\tPunti1\tPunti2\tPunti3\tCognome (Regione)\t\t\n");
        do{
            /* TODO: MODIFICARE PER LA CORRETTA VISUALIZZAZIONE DELLE MEDIE */
            printf("%s\t%d\t%d\t%d\t%.2f\t%s (%s)\n",
                    pLista->matricola, pLista->punti1, pLista->punti2, pLista->punti3, pLista->media, pLista->cognome, pLista->regione);
            pLista = pLista->next;
        }
        while(pLista != NULL);
    }
}

Candidati * posizionaNodo(Candidati *head, int pos){
    int i;
    Candidati *posizione = head;
    for(i=0; i<pos; i++)
        posizione = posizione->next;
    return posizione;
}
void swapNodes(Candidati** head_ref, Candidati *x, Candidati *y){ /* NON OTTIMIZZATO: ANDREBBE TENUTA IN CONSIDERAZIONE LA POSSIBILITA' CHE I NODI SIANO <= 2 */
    Candidati *prevX = NULL, *currX = *head_ref;
    Candidati *prevY = NULL, *currY = *head_ref;
    Candidati *aus; // PER SCAMBIO NODI

    /* POSIZIONAMENTO NODO PRECEDENTE X */
    while (currX && currX != x) {
        prevX = currX;
        currX = currX->next;
    }
    /* POSIZIONAMENTO NODO PRECEDENTE Y */
    while (currY && currY != y) {
        prevY = currY;
        currY = currY->next;
    }

    /* CONTROLLO SE NODO X PRECEDENTE E' NULLO O MENO (CASO NODO DI TESTA) */
    if (prevX != NULL)
        prevX->next = currY;
    else
        *head_ref = currY;


    if (prevY != NULL) /* NON SI VERIFICA A MENO CHE LA LISTA NON SIA VUOTA */
        prevY->next = currX;
    else
        *head_ref = currX;

    aus = currY->next;
    currY->next = currX->next;
    currX->next = aus;
}
Candidati* ordinaPerRegione(Candidati *testa){
    //ordinamento per selezione CRESCENTE
    int n = contaNodi(testa);
    int aus;
    Candidati *n1, *n2;
    Candidati *posmin;
    for (int i = 0; i <= n - 2; i++)
    {
        posmin = posizionaNodo(testa, i);
        n1 = posizionaNodo(testa, i);
        for (int j = i + 1; j <= n - 1; j++)
        {
            n2 = posizionaNodo(testa, j);
            if (strcmp(posmin->regione, n2->regione) > 0)
            {
                posmin = n2;
            }

        }
        if (n1 != posmin)  //serve a sapere se devo fare o no lo scambio
            swapNodes(&testa, n1, posmin);
    }
    return testa;
}

Candidati* miglioriPerRegione(Candidati* testa){
    if(testa!=NULL)
    {
        char cogn[15];
        float media=0;
        if(testa->next==NULL)
        {
            printf("Regione: %s  %s\n",testa->regione,testa->cognome);
        }
        else
        {
            testa=ordinaPerRegione(testa);
            Candidati *l1;
            for(l1=testa;l1->next->next!=NULL;l1=l1->next)
            {
                if(l1->media > media)
                {
                    media=l1->media;
                    strcpy(cogn,l1->cognome);
                }
                if(strcmp(l1->regione,l1->next->regione)!=0)
                {
                    printf("Regione: %s  %s\n",l1->regione,cogn);
                    media=0;
                }
            }
            if(l1->media > media)
            {
                media=l1->media;
                strcpy(cogn,l1->cognome);
            }
            if(strcmp(l1->regione,l1->next->regione)!=0)
            {
                printf("Regione: %s  %s\n",l1->regione,cogn);
                media=0;
            }
            l1=l1->next;
            if(l1->media > media)
            {
                media=l1->media;
                strcpy(cogn,l1->cognome);
            }
            printf("Regione: %s  %s\n",l1->regione,cogn);
        }

    }
    else
        printf("LISTA VUOTA\n");
    return testa;

}

Candidati * ordinaMedia(Candidati *head){
    //ordinamento per selezione DECRESCENTE
    int n = contaNodi(head);
    int aus;
    Candidati *n1, *n2;
    Candidati *posmin;
    for (int i = 0; i <= n - 2; i++)
    {
        posmin = posizionaNodo(head, i);
        n1 = posizionaNodo(head, i);
        for (int j = i + 1; j <= n - 1; j++)
        {
            n2 = posizionaNodo(head, j);
            if (posmin->media < n2->media)
                posmin = n2;

        }
        if (n1 != posmin)  //serve a sapere se devo fare o no lo scambio
            swapNodes(&head, n1, posmin);
    }
    return head;
}

void miglioriAssoluto(Candidati *testa){
    ordinaMedia(testa);

    for(int i = 0; i < 3; i++){
        printf("%d. %s (%s) con un totale di %.2f punti di media\n", (i + 1), testa->cognome, testa->regione, testa->media);
        testa = testa->next;
    }
}
void stampaSuFile(Candidati* testa, char *path){
    FILE *fp;
    Candidati* plista=testa;
    fp = fopen(path, "w");
    fprintf(fp, "COGNOME; MATRICOLA; REGIONE; MEDIA; PUNTI1; PUNTI2; PUNTI3\n");
    while(plista != NULL){
        fprintf(fp, "%s;%s;%s;%.2f;%i;%i;%i\n", plista->cognome, plista->matricola, plista->regione, plista->media, plista->punti1, plista->punti2, plista->punti3);
        plista = plista->next;
    }
    fclose(fp);
    printf("SALVATAGGIO SU FILE EFFETTUATO");
}

Candidati* delByMatr(Candidati* testa, char matr[]){
    if(testa!=NULL)
    {
        Candidati *pDel, *pPrec;
        int i;

        if (strcmp(testa->matricola,matr)==0)
        {
            pDel = testa;
            testa = testa -> next;
        }
        else
        {
            pPrec = testa;
            pDel = testa->next;
            while(pDel->next!= NULL && strcmp(pDel->matricola,matr)!=0)
            {
                pPrec=pDel;
                pDel=pDel->next;
            }
            if(strcmp(pDel->matricola,matr)==0)
                pPrec->next = pDel->next;
        }
        if(strcmp(pDel->matricola,matr)==0)
        {
            printf("Matricola eliminata");
            free(pDel);
        }
        else
            printf("Matricola non trovata\n");
    }
    return testa;
}
