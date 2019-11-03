/*
Author: Davide Di Marco
Date: 01/11/2019
Note: occorrenza di una sottostringa in una stringa principale.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 30

int main()
{

    char s1[MAX+1];
    char s2[MAX+1];

    char stringaVuota[30]; //STRINGA CONTENENTE IL TESTO DELLA VERIFICA
    char nS[MAX+1]={'0'}; //STRINGA CREATA SOSTITUITA CON GLI '*'
    char carattere;

    int dim1=0;//Lunghezza stringa s1
    int dim2=0; //Lunghezza stringa s2
    int index=0; //Indice del while

    do{
        if (dim1>30){
        printf("\nERRORE: STRINGA TROPPO LUNGA");
        }
        printf("INSERISCI STRINGA: ");
        gets(s1);
        dim1=0;
        index=0;
        while (s1[index]!='\0'){
            dim1+=1;
            if (dim1>30){ //Stringa troppo lunga
                break;
            }
            index++;
        }
    }while (dim1>30);

    do{
        if (dim2>30){
            printf("ERRORE: STRINGA TROPPO LUNGA\n");
        }
        printf("\nINSERISCI OCCORRENZA DA RICERCARE: ");
        gets(s2);
        printf("\n");
        dim2=0;
        index=0;
        while (s2[index]!='\0'){
            dim2+=1;
            index++;
        }
    }while (dim2>30);

    if (dim2>dim1){
            printf("LA STRINGA 2 E' PIU\' LUNGA DELLA STRINGA 1");
            exit(1);
    }
    printf("RICERCO LE OCCORRENZE DI \'%s\' NELLA STRINGA \'%s\' e le sostituisco con \'*\'",s2,s1);
    int index1=0; //indice della nuova stringa
    int index3=0; //indice stringa2
    int dimSv=0; //lunghezza dimensione della stringa di verifica
    bool occor=false;

    for (int index=0;index<=dim1;index++){ //CICLO PER OGNI LETTERA DELLA STRIG
        carattere=s1[index];

        if (carattere==s2[index3]){
            stringaVuota[index3]=carattere;
            index3++;
            dimSv++;
            if (dimSv==dim2 || carattere=='*'){
                nS[index1]='*';
                index1++;
                dimSv=0;
                index3=0;
                for (int k=0;k<30;k++){
                    stringaVuota[k]='\0';
                }
                occor=true;
            }
        }
        else{
            nS[index1]=carattere;
            index1++;
        }
    }
    if (occor==false){ //LA STRINGA E' VUOTA
        printf("\n\nNON CI SONO OCCORRENZE");
    }else{
    printf("\n\nNUOVA STRINGA: %s\n",nS);
    }
    getchar();
    return 0;
}
