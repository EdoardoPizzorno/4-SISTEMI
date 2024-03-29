#include "class.h"

char menu();

int main(void)
{
    char scelta;
    Candidati *testa = NULL;
    Candidati *plista;

    char matr[6];
    char cogn[30];
    char reg[30];
    int p1 = 0, p2 = 0, p3 = 0;

    do
    {
        scelta = menu();
        fflush(stdin);


        switch (scelta)
        {
        case 'A':
        case 'a':
            fflush(stdin);
            testa = loadFromFile(testa, "candidati.csv", "punteggi.csv");
            printf("Totale candidati caricati: %d\n", contaNodi(testa));
            break;
        case 'B':
        case 'b': /* TODO: VISUALIZZA INFO LISTA */
            fflush(stdin);
            testa = loadFromFile(testa, "candidati.csv", "punteggi.csv");
            showList(testa);
            break;
        case 'C':
        case 'c': /* TODO: NUOVO CANDIDATO MATRICOLA [LLNNN], COGNOME, REGIONE, PUNTI x3 [1-100], MEDIA PUNTI */
            fflush(stdin);
            int i=0;
            srand(time(NULL));
             //printf("\nInserisci matricola: ");
            //scanf("%s", &matr);

            for(i=0; i<2; i++)
                matr[i]+='A'+rand()%('Z'-'A');
            for(i=2; i<5; i++)
                matr[i]+='0'+rand()%('9'-'0');
            matr[5]='\0';

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
            testa = ordinaMedia(testa);
            showList(testa);
            plista = testa;
            printf("MIGLIORI 3\n");
            for(i=0; i<3; i++)
            {
                printf("%s (%s): %.2f media\n", plista->cognome, plista->matricola, plista->media);
                plista = plista->next;
            }
            getchar();
            break;
        case 'F':
        case 'f': /* TODO: RICERCA MATRICOLA E ELIMIINA NODO */
            fflush(stdin);
            printf("Inserisci matricola da eliminare: ");
            gets(matr);
            if(strlen(matr)>5)
                printf("Matricola non valida\n");
            else
                testa = delByMatr(testa, matr);
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
