/*
Author: Davide Di Marco
Date: 17/10/2019
Notes:*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    int min,max,nRandom;
    min=0;
    max=0;
    bool indovinato=false;
    char risposta= ' ';

    while (min==0 || max==0){
        printf("Inserisci intervallo di ricerca(min-max, separati da uno spazio): ");
        scanf("%d %d",&min,&max);
        fflush(stdin);
        if (min!=0 && max!=0){
           break;
        }else{
            printf("dati non validi, inseriscili nuovamente\n");
        }
    }
    printf("\nPensa a un numero compreso tra %d e %d\n",min,max);


    while (indovinato!=true){

        nRandom=min+(rand()+time(NULL))%(max+1-min); //genero un numero random tra min e max

        while (risposta!= '<' || risposta!= '>' || risposta!='='){
            printf("\nIl numero pensato e\' minore, maggiore o uguale a %d?(<,>,=): ",nRandom);
            scanf("%c",&risposta);
            fflush(stdin);

            if (risposta=='<'){
                max=nRandom-1;
                printf("%d %d",min,max);
                break;
            }else if (risposta=='>'){
                min=nRandom+1;
                printf("%d %d",min,max);
                break;
            }else if (risposta=='='){
                printf("HO TROVATO IL NUMERO, IL NUMERO DA TE PENSATO E\': %d",nRandom);
                indovinato=true;
                break;
            }else{
                printf("Dato non valido\n");
            }

        }
    }
    return 0;
}
