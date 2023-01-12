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
    nodo->media = (float)(p1 + p2 + p3) / 3;
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
        printf("Matr.\tPunti1\tPunti2\tPunti3\tMedia\tCognome (Regione)\t\t\n");
        do{
            /* TODO: MODIFICARE PER LA CORRETTA VISUALIZZAZIONE DELLE MEDIE */
            printf("%s\t%d\t%d\t%d\t%.2f\t%s (%s)\n",
                    pLista->matricola, pLista->punti1, pLista->punti2, pLista->punti3, pLista->media, pLista->cognome, pLista->regione);
            pLista = pLista->next;
        }
        while(pLista != NULL);
    }
}

Candidati* posizionaNodo(Candidati* testa, int pos){
    Candidati* posizione = testa;
    for(int i = 0; i < pos; i++)
        posizione = posizione->next;
    return posizione;
}

void ordinaRegione(Candidati *testa){
    int n = contaNodi(testa);
    Candidati *ni, *nj;
    Candidati *posmin;

    for(int i = 0; i <= n - 2; i++){
        posmin = posizionaNodo(testa, i);
        ni = posizionaNodo(testa, i);

        for(int j = i + 1; j <= n - 1; j++){
            nj = posizionaNodo(testa, j);
            if(strcmp(posmin->regione, nj->regione) > 0)
                posmin = nj;
        }
        if(posmin != ni){ // si poteva anche fare (strcmp(posmin->matricola, ni->matricola) != 0) in quanto la matricola è univoca
            Swap(&testa, ni->matricola, posmin->matricola);
        }
    }
}
void Swap(Candidati** testa, char *ni_matr, char *posmin_matr){
    Candidati* precMX = NULL, *attMX = *testa, *mx;
    Candidati* precMY = NULL, *attMY = *testa, *my;
    Candidati* aus;

    while(attMX && strcmp(attMX->matricola, mx) != 0){
        precMY = attMX;
        attMY = attMY->next;
    }
    while(attMY && strcmp(attMX->matricola, mx) != 0){
        precMY = attMX;
        attMY = attMY->next;
    }
    if(precMX == NULL)
        *testa = attMY;
    else
        precMX->next = attMY;

    if(precMY == NULL)
        *testa = attMX;
    else
        precMY->next = attMX;

    aus = attMY->next;
    attMY->next = attMX->next;
    attMX->next = aus;
}

void miglioriPerRegione(Candidati* testa){
    ordinaRegione(testa);
    Candidati* l1 = testa;
    Candidati* l2 = testa;
    float massimo = l1->media;
    char migliore[15];

    strcpy(migliore, l1->cognome);

    for(; l2->next != NULL; l2 = l2->next){
        if(strcmp(l1->regione, l2->regione) == 0){
            if(l2->media > massimo){
                massimo = l2->media;
                strcpy(migliore, l2->cognome);
            }
        }
        else{
            //REGIONE CAMBIATA
            printf("Migliore regione %s: %s con %.2f punti\n", l1->regione, migliore, massimo);
            massimo = l2->media;
        }
        l1 = l1->next;
    }
    printf("Migliore regione %s: %s con %.2f punti\n", l1->regione, l2->cognome, massimo);
}

void ordinaMedia(Candidati *testa){
    int rifare = TRUE;
    char ausChar[100];
    int ausInt = 0;
    float ausFloat = 0;

    Candidati* l1 = NULL;
    Candidati* l2 = NULL;

    while(rifare == TRUE){
        rifare = FALSE;
        for(l1 = testa; l1->next != NULL; l1 = l1->next){
            for(l2 = l1->next; l2 != NULL; l2 = l2->next){
                if(l1->media < l2->media){
                    rifare = TRUE;
                    //SWAPs (NON OITIMIZZATO)
                    strcpy(ausChar, l1->matricola);
                    strcpy(l1->matricola, l2->matricola);
                    strcpy(l2->matricola, ausChar);

                    strcpy(ausChar, l1->cognome);
                    strcpy(l1->cognome, l2->cognome);
                    strcpy(l2->cognome, ausChar);

                    strcpy(ausChar, l1->regione);
                    strcpy(l1->regione, l2->regione);
                    strcpy(l2->regione, ausChar);

                    ausInt = l1->punti1;
                    l1->punti1 = l2->punti1;
                    l2->punti1 = ausInt;

                    ausInt = l1->punti2;
                    l1->punti2 = l2->punti2;
                    l2->punti2 = ausInt;

                    ausInt = l1->punti3;
                    l1->punti3 = l2->punti3;
                    l2->punti3 = ausInt;

                    ausFloat = l1->media;
                    l1->media = l2->media;
                    l2->media = ausFloat;

                    /*
                    Candidati* aus = l1;
                    l1 = l2;
                    l2 = aus;
                    */
                }
            }
        }
    }
}

void miglioriAssoluto(Candidati* testa){
    ordinaMedia(testa);

    for(int i = 0; i < 3; i++){
        printf("%d. %s (%s) con un totale di %.2f punti di media\n", (i + 1), testa->cognome, testa->regione, testa->media);
        testa = testa->next;
    }
}
void stampaSuFile(Candidati* testa, char *path){
    FILE *fp;
    Candidati* Lista;

    Lista = testa;

    fp = fopen(path, "w");
    fprintf(fp, "COGNOME; MATRICOLA; REGIONE; MEDIA; PUNTI1; PUNTI2; PUNTI3\n");
    while(Lista->next != NULL){
        fprintf(fp, "%s;%s;%s;%f;%i;%i;%i\n", Lista->cognome, Lista->matricola, Lista->regione, Lista->media, Lista->punti1, Lista->punti2, Lista->punti3);
        Lista = Lista->next;
    }
    fclose(fp);
    printf("SALVATAGGIO SU FILE EFFETTUATO");
}
Candidati* eliminaPersona(Candidati* testa, char* del_matr){
    Candidati* previous;
    Candidati* del;
    int trovato = FALSE;

    previous = testa;

    while(trovato == FALSE && previous == NULL){
        if(strcasecmp(previous->matricola, del_matr) == 0){
            del = previous->next;
            previous->next = del->next;

            trovato = TRUE;
        }
        previous = previous->next;
    }
    if(trovato == FALSE)
        printf("\nNessun nodo con la matricola inserita");
    else printf("\nNODO ELIMINATO CORRETTAMENTE");

    free(del);
    return testa;
}
