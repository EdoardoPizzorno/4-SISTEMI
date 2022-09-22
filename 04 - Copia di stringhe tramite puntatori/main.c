#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[20];
    char s2[20];
    char *ps1, *ps2;

    printf("Inserisci stringa: ");
    scanf("%s",s1);

    ps1=s1;
    ps2=s2;

    do{
        *ps2=*ps1;
        ps2++;
        ps1++;
    }while(*ps1!='\0');

    *ps2='\0';
    printf("Stringa1: %s\nStringa2: %s",s1,s2);

    return 0;
}
