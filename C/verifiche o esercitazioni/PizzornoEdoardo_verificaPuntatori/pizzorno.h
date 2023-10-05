#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct Libro
{
    int cod;
    char isbn[14];
    char titolo[100];
    char autore[50];
    char editore[50];
    int nPag;
    struct Libro *next;
}Libri;

Libri* loadFromFile(Libri *head, char *filename);
void splittaString(char row[], char ret[], int pos, char separatore);
Libri* inserisciNodo(Libri *head, int _cod, char *_isbn, char *_titolo, char *_autore, char *_editore, int _nPag);
int contaNodi(Libri *head);
void stampaLista(Libri *head);

void swapNodes(Libri** head_ref, Libri *x, Libri *y);
Libri* posizionaNodo(Libri *lista, int pos);
void visualizzaLibri(Libri* testa, int pages);
Libri* ordinaLibriPagine(Libri* testa);
int findIsin(Libri* testa, char* del_isin);
void findPages(Libri* testa, int pages);
void cercaEditore(Libri* testa, Libri* seconda_lista, char* editore);
Libri* ordinaLibriEditore(Libri* lista);
/* ----------------------------------------------------------------------------------------------------- */
int contaNodi(Libri *head){
    int cnt = 0;
    for(; head != NULL; head = head->next)
        cnt++;
    return cnt;
}
void splittaString(char row[], char ret[], int pos, char separatore)
{
    int cnt = 0;
    int i = 0;

    while(cnt != pos){
        while(row[i] != separatore)
            i++;
        cnt++;
        i++;
    }
    cnt = 0;
    while(row[i] != separatore && row[i] != '\0'){
        ret[cnt] = row[i];
        i++;
        cnt++;
    }
    ret[cnt] = '\0';
}
Libri *loadFromFile(Libri *head, char *filename)
{
    FILE *fp;
    char *token; // Split
    int i;
    char v[100];

    char line[200];
    int _cod;
    char _isbn[14];
    char _titolo[100];
    char _autore[50];
    char _editore[50];
    int _nPag;

    fp = fopen(filename, "r");

    while(!feof(fp))
    {
        fgets(line, 200, fp);
        splittaString(line, v, 0, ';'); _cod = atoi(v);
        splittaString(line, _isbn, 1, ';');
        splittaString(line, _titolo, 2, ';');
        splittaString(line, _autore, 3, ';');
        splittaString(line, _editore, 4, ';');
        splittaString(line, v, 5, ';');  _nPag = atoi(v);
        head = inserisciNodo(head, _cod, _isbn, _titolo, _autore, _editore, _nPag);
    }
    fclose(fp);
    return head;
}
Libri* inserisciNodo(Libri *head, int _cod, char *_isbn, char *_titolo, char *_autore, char *_editore, int _nPag)
{
    Libri *new, *aus;

    new = (Libri*) malloc(sizeof(Libri));

    new->cod = _cod;
    new->nPag = _nPag;
    strcpy(new->isbn, _isbn);
    strcpy(new->titolo, _titolo);
    strcpy(new->autore, _autore);
    strcpy(new->editore, _editore);
    new->next = NULL;

    if (head == NULL)
        head = new;
    else
    {
        aus = head;
        while(aus->next != NULL)
            aus = aus->next;
        aus->next = new;
    }
    return head;
}
void stampaLista(Libri *head)
{
    for(; head != NULL; head = head->next)
        printf("%15s%30s%100s[%d]\n", head->isbn, head->autore, head->titolo, head->nPag);
}

Libri* eliminaNodo(Libri *head, int pos){
    Libri *pDip = head;
    Libri *pDel;

    if (pos == 0)
    {
        head = pDip->next;
        free(pDip);
    }
    else
    {
        for(int i=1; i<pos; i++)
            pDip = pDip->next;
        pDel = pDip->next;
        pDip->next = pDel->next;
        free(pDel);
    }
    return head;
}

Libri* posizionaNodo(Libri *lista, int pos){
    Libri *posizione = lista;
    for(int i = 0; i < pos; i++)
        posizione = posizione->next;
    return posizione;
}
void swapNodes(Libri** head_ref, Libri *x, Libri *y)
{ /* NON OTTIMIZZATO: ANDREBBE TENUTA IN CONSIDERAZIONE LA POSSIBILITA' CHE I NODI SIANO <= 2 */
    Libri *prevX = NULL, *currX = *head_ref;
    Libri *prevY = NULL, *currY = *head_ref;
    Libri *aus; // PER SCAMBIO NODI

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
int findIsin(Libri* testa, char* del_isin){
    Libri *lista = testa;
    int i = 0;

    while(lista != NULL && strcmp(lista->isbn, del_isin) != 0){
        i++;
        lista = lista->next;
    }
    if(lista == NULL)
        return -1;
    return i;
}
void findPages(Libri* testa, int pages){
    Libri *lista = testa;
    int superato = FALSE;

    stampaLista(lista);

    lista = ordinaLibriPagine(lista);

    printf("\n\n\n");
    stampaLista(lista);

    while(superato == FALSE && lista != NULL){
        if(lista->nPag > pages)
            printf("\n%s", lista->titolo);
        else
            superato = TRUE;

        lista = lista->next;
    }
    if(lista == NULL)
        printf("\nNessun libro trovato");
}
/*Libri* ordinaLibriISIN(Libri* lista){
    int n = contaNodi(lista);
    int aus;
    Libri *n1, *n2;
    Libri *posmin;

    for (int i = 0; i <= n - 2; i++){
        posmin = posizionaNodo(lista, i);
        n1 = posizionaNodo(lista, i);
        for (int j = i + 1; j <= n - 1; j++)
        {
            n2 = posizionaNodo(lista, j);
            if (strcmp(posmin->isbn, n2->isbn) < 0)
                posmin = n2;
        }
        if (n1 != posmin)
            swapNodes(&lista, n1, posmin);
    }
    return lista;
}*/

Libri* ordinaLibriEditore(Libri* lista){
    int n = contaNodi(lista);
    int aus;
    Libri *n1, *n2;
    Libri *posmin;

    for (int i = 0; i <= n - 2; i++){
        posmin = posizionaNodo(lista, i);
        n1 = posizionaNodo(lista, i);
        for (int j = i + 1; j <= n - 1; j++)
        {
            n2 = posizionaNodo(lista, j);
            if (strcmp(posmin->editore, n2->editore) < 0)
                posmin = n2;
        }
        if (n1 != posmin)
            swapNodes(&lista, n1, posmin);
    }
    return lista;
}

Libri* ordinaLibriPagine(Libri* lista){
    printf("\n\n\n\n");
    int n = contaNodi(lista);
    int aus;
    Libri *n1, *n2;
    Libri *posmin;

    for (int i = 0; i <= n - 2; i++){
        posmin = posizionaNodo(lista, i);
        n1 = posizionaNodo(lista, i);
        for (int j = i + 1; j <= n - 1; j++)
        {
            n2 = posizionaNodo(lista, j);
            if (posmin->nPag > n2->nPag)
                posmin = n2;
        }
        if (n1 != posmin)
            swapNodes(&lista, n1, posmin);
    }
    return lista;
}
void cercaEditore(Libri* testa, Libri* seconda_lista, char* editore){
    Libri* lista = testa;

    lista = ordinaLibriEditore(lista);
    int superato = FALSE;

    while(superato == FALSE && lista != NULL){
        if(strcmp(lista->editore, editore) == 0){
            // bisognerebbe fare lo swap
            printf("\n%s", lista->editore);
        }
    }
}

