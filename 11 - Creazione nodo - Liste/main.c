#include "class.h"

char menu();

int main(void)
{
    char scelta;
    Candidati *testa = NULL;

    char matr[5];
    char cogn[30];
    char reg[30];
    int p1 = 0, p2 = 0, p3 = 0;
    char del_matr[5];

    do
    {
        scelta = menu();
        fflush(stdin);

        switch (scelta){
        case 'A':
        case 'a':
            fflush(stdin);
            testa = loadFromFile(testa, "candidati.csv", "punteggi.csv");
            printf("Totale candidati caricati: %d\n", contaNodi(testa));
            break;
        case 'B':
        case 'b': /* TODO: VISUALIZZA INFO LISTA */
            fflush(stdin);
            showList(testa);
            break;
        case 'C':
        case 'c': /* TODO: NUOVO CANDIDATO MATRICOLA [LLNNN], COGNOME, REGIONE, PUNTI x3 [1-100], MEDIA PUNTI */
            fflush(stdin);

            for(int i = 0; i < 2; i++)
                matr[i] = 'A' + rand() % ('Z'-'A');
            for(int i = 2; i < 5; i++)
                matr[i] = '0' + rand() % ('9'-'0');

            printf("\nInserisci cognome: ");
            scanf("%s", &cogn);
            printf("Inserisci regione: ");
            scanf("%s", &reg);

            //cogn e reg TO UPPER
            for(int i = 0; i < strlen(cogn); i++)
                cogn[i] = toupper(cogn[i]);
            for(int i = 0; i < strlen(reg); i++)
                reg[i] = toupper(reg[i]);

            testa = addOnTail(testa, matr, cogn, reg, rand()%100 + 1, rand()%100 + 1, rand()%100 + 1);

            showList(testa);

            getchar();
            break;
        case 'D':
        case 'd': /* TODO: MIGLIORI CIASCUNA REGIONE (SI RACCOMANDA ORDINAMENTO PER REGIONE) */
            fflush(stdin);

            printf("\nI MIGLIORI PER CIASCUNA REGIONE: \n\n");
            miglioriPerRegione(testa);

            getchar();
            break;
        case 'E':
        case 'e': /* TODO: 3 MIGLIORI IN ASSOLUTO (SI RACCOMANDA ORDINAMENTO PER MEDIA {DESC}) */
            fflush(stdin);

            printf("\nI MIGLIORI IN ASSOLUTO: \n\n");
            miglioriAssoluto(testa);

            getchar();
            break;
        case 'F':
        case 'f': /* TODO: RICERCA MATRICOLA E ELIMIINA NODO */
            fflush(stdin);
            printf("Inserisci matricola della persona da eliminare: ");
            scanf("%s", del_matr);

            testa = eliminaPersona(testa, del_matr);

            getchar();
            break;
        case 'G':
        case 'g': /* TODO: SALVA INFO NODI SU FILE (backup.csv) */
            fflush(stdin);

            stampaSuFile(testa, "backup.csv");

            getchar();
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
        fflush(stdin);
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
