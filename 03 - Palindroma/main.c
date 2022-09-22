#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[20];
    char *inizio;
    char *fine;

    printf("Inserisci la prima parola: ");
    scanf("%s",s1); //la scanf prende la stringa fino allo spazio, la gets prende tutta la stringa

    inizio=s1;
    fine=s1+((strlen(s1))-1);

    while((inizio<fine) && (*inizio == *fine)){
        inizio++;
        fine--;
    }
    if(inizio<fine) //significa che siamo usciti prima del dovuto
        printf("\nStringa NON palindroma");
    else printf("\nStringa palindroma");
    return 0;
}
