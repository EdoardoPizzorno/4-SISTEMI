#include "pizzorno.h"

int main(void)
{
    Libri *testa = NULL;
    Libri *seconda_lista = NULL;
    char scelta = ' ';

    testa = loadFromFile(testa, "Libri.csv");
    printf("Libri caricati: %d\n", contaNodi(testa));
    getchar();

    char del_isin[14];
    int n_pagine = 0;
    int pos = 0;
    char editore[15];

    do
    {
        menu(&scelta);

        switch (scelta)
        {
        case 'A':
        case 'a':
            stampaLista(testa);
            getchar();
            break;
        case 'B':
        case 'b':
            fflush(stdin);
            printf("Inserisci ISIN da eliminare: ");
            scanf("%s", del_isin);
            stampaLista(testa);

            pos = findIsin(testa, del_isin);

            if(pos != -1){
                testa = eliminaNodo(testa, pos);
                printf("\nRecord eliminato\n\n");
                getchar();
            }else{
                printf("\nISIN non trovato\n\n");
                getchar();
            }
            stampaLista(testa);
            getchar();
            break;
        case 'C':
        case 'c':
            fflush(stdin);
            printf("Inserisci il numero di pagine: ");
            scanf("%i", n_pagine);

            findPages(testa, n_pagine);

            getchar();
            break;
        case 'D':
        case 'd':
            fflush(stdin);
            printf("Inserisci editore: ");
            scanf("%s", editore);
            cercaEditore(testa, seconda_lista, editore);
            break;
        case 'Q':
        case 'q':
            printf("Arrivederci...\n");
            break;
        default:
            printf("Scelta non disponibile\n");
            getchar();
            break;
        }
    } while (scelta != 'q' && scelta != 'Q');
    return 0;
}
void menu(char *scelta)
{
    system("@cls||clear");
    printf("---LIBRERIA---\n");
    printf("A. Visualizza Libri\n");
    printf("B. Cerca ISIN ed elimina nodo se esiste\n");
    printf("C. Visualizza libri le cui pagine sono superiori a valore in input (Ordinamento per # pagine DESC)\n");
    printf("D. Caricare, in una seconda lista, tutti i libri appartenenti ad un editore dato in input e visualizzarla\n");
    printf("Q. Quit\n");
    printf("Scelta -> ");
    scanf("%c", scelta);
    getchar();
    system("@cls||clear");
}
