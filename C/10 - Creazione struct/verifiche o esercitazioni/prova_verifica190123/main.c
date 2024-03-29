#include "class.h"

char menu();

int main(void)
{
    char scelta;
    Candidati *testa = NULL;

    char matr[6];
    char cogn[10];
    char reg[10];

    srand(time(NULL));

    do
    {
        scelta = menu();
        fflush(stdin);
        switch (scelta)
        {
        case 'A':
        case 'a':
            fflush(stdin);
            testa = loadFromFile(testa, "candidati.csv", "punteggi.csv"); // ESEMPIO DI CARICAMENTO NODI/LISTA DA FILES
            getchar();
            // showList(testa);
            printf("Totale candidati caricati: %d\n", contaNodi(testa));
            break;
        case 'B':
        case 'b': /* TODO: VISUALIZZA INFO LISTA */
            fflush(stdin);
            showList(testa);
            getchar();
            break;
        case 'C':
        case 'c': /* TODO: NUOVO CANDIDATO MATRICOLA [LLNNN], COGNOME, REGIONE, PUNTI x3 [1-100], MEDIA PUNTI */
            for(int i = 0; i < 2; i++)
                matr[i] = 'A' + rand()%('Z' - 'A');
            for(int i = 2; i < 5; i++)
                matr[i] = '0' + rand()%('9' - '0');
            matr[5] = '\0';

            printf("\nInserisci cognome: ");
            scanf("%s", cogn);
            printf("\nInserisci regione: ");
            scanf("%s", reg);

            testa = addOnTail(testa, matr, cogn, reg, rand()%100 + 1, rand()%100 + 1, rand()%100 + 1);

            showList(testa);
            getchar();
            break;
        case 'D':
        case 'd': /* TODO: MIGLIORI CIASCUNA REGIONE (SI RACCOMANDA ORDINAMENTO PER REGIONE) */
            testa = ordinaRegione(testa);
            miglioriPerRegione(testa);
            getchar();
            break;
        case 'E':
        case 'e': /* TODO: 3 MIGLIORI IN ASSOLUTO (SI RACCOMANDA ORDINAMENTO PER MEDIA {DESC}) */
            break;
        case 'F':
        case 'f': /* TODO: RICERCA MATRICOLA E ELIMIINA NODO */
            break;
        case 'G':
        case 'g': /* TODO: SALVA INFO NODI SU FILE (backup.csv) */
            break;
        case 'Q':
        case 'q':
            printf("Arrivederci...");
            break;
        default:
            printf("Scelta non disponibile\n");
            break;
        }
        getchar();
    } while (scelta != 'q' && scelta != 'Q');

    return 0;
}
char menu()
{
    char sc;
    system("@cls||clear");
    printf("--- CANDIDATI (GESTIONE DATI DA FILE) ---\n");
    printf("A. Carica da File\n");
    printf("B. Visualizza Informazioni Lista\n");
    printf("C. Inserisci Nuovo Candidato, regione e punti\n");
    printf("D. Ricerca Migliori Per Ciascuna Regione\n");
    printf("E. Ordina NODI (E NON INFORMAZIONI CONTENUTE IN ESSI) per Media Punteggi (DESC) e mostra 3 migliori\n");
    printf("F. Data la matr del candidato, applicare una ricerca e, se trovato, eliminarlo\n");
    printf("G. Backup - salvare informazioni su file\n");
    printf("Q. Quit\n");
    printf("Scelta -> ");
    scanf("%c", &sc);
    fflush(stdin);
    system("@cls||clear");
    return sc;
}
