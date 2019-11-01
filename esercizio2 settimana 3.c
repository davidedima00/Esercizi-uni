/*
Author: Davide Di Marco
Date: 01/11/2019
Note: occorrenza di una sottostringa in una stringa principale.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int main()
{

    char s1[MAX+1];
    char s2[MAX+1];
    char stringaVuota[30];

    char nS[MAX+1]={'0'};


    char carattere;

    printf("Inserisci stringa 1: ");
    gets(s1);
    printf("Inserisci stringa 2: ");
    gets(s2);

    int dim1=0;
    int index=0;

    while (s1[index]!='\0'){
        dim1+=1;
        index++;
    }


    int dim2=0;
    index=0;
    while (s2[index]!='\0'){
        dim2+=1;
        index++;
    }
    printf("Lungehzza parola1: %d, lunghezza parola2: %d\n",dim1,dim2);


    printf("RICERCO LE OCCORRENZE DI \'%s\' NELLA STRINGA \'%s\'",s2,s1);
    int index1=0; /**indice della nuova stringa**/
    int index3=0; /**indice stringa2*/
    int dimSv=0;

    for (int index=0;index<dim1;index++){
        carattere=s1[index];
        if (carattere==s2[index3]){
            stringaVuota[index3]=carattere;
            index3++;
            dimSv++;
            if (dimSv==dim2){
                nS[index1]='*';
                index1++;
                dimSv=0;
                index3=0;
                for (int k=0;k<30;k++){
                    stringaVuota[k]='\0';
                }
            }
        }
        else{
            nS[index1]=carattere;
            index1++;
        }
        //scopro la dimensione della stringa vuota
    }
    printf("\n%s",nS);


    return 0;
}
