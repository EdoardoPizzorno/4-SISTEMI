#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 30

typedef struct studente{
    int matr;
    char nome[MAX];
    float inf, sis, tpsit;
} Studenti;

Studenti* creaNodo();
void stampaNodo(Studenti* nodo);

int main()
{
    Studenti *nodo = NULL;

    nodo = creaNodo();

    stampaNodo(nodo);

    return 0;
}

void stampaNodo(Studenti* p){
    printf("STAMPA STUDENTE\n");
    printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f", p->matr, p->nome, p->inf, p->sis, p->tpsit);
}

Studenti* creaNodo(){
    Studenti *pStu;

    int matricola;
    char nominativo[MAX];
    float info, sist, tpsi;

    printf("Matricola --> ");
    scanf("%d", &matricola);

    getchar();
    printf("Nome --> ");
    gets(nominativo);

    getchar();
    printf("Informatica --> ");
    scanf("%f", &info);
    printf("Sistemi --> ");
    scanf("%f", &sist);
    printf("Informatica --> ");
    scanf("%f", &tpsi);

    pStu = (Studenti*)malloc(sizeof(Studenti));

    pStu->matr = matricola;
    strcpy(pStu->nome, nominativo);
    pStu->inf = info;
    pStu->sis = sist;
    pStu->tpsit = tpsi;

    return pStu;
}
