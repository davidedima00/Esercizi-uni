#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 30


int main(){

    char s1[MAX+1]={'\0'};
    char s2[MAX+1]={'\0'};
    int dim1=31,dim2=31; //lunghezza Stringhe s1,s2

    while (dim1>30 || dim1==0){
        printf("INSERISCI STRINGA 1: ");
        gets(s1);
        if (strlen(s1)>MAX){
            printf("\nERRORE: STRINGA TROPPO LUNGA.");
        }else{
            dim1=strlen(s1);
        }
    }

    while (dim2>30 || dim2==0){
        printf("INSERISCI STRINGA 2: ");
        gets(s2);
        if (strlen(s2)>MAX){
            printf("\nERRORE: STRINGA TROPPO LUNGA.");
        }else{
            dim2=strlen(s2);
        }
    }
    printf("LUNGHEZZA PAROLA 1: %d, LUNGHEZZA PAROLA2 2: %d\n",dim1,dim2);
    ////////////////////////////////////////////////////////////////////////////////////////////
    char *stringaTagliata;
    char daTagliare[MAX+1];
    strcpy(daTagliare,s1);
    char nS[MAX+1]={'\0'}; //NUOVA STRINGA CON
     //indice della nuova stringa
     //indice stringa2
    int dimSv=0; //lunghezza della stringa di verifica
    char carattere;

    char stringaVuota[MAX+1]={'\0'};
    int index2=0; //Indice per lo scorrimento della seconda parola
    int index1=0; //Indice per lo scorrimento della prima parola
    int indexTagliata=0; //Indice per lo scorrimento della stringa tagliata da strstr
    for (int index=0;index<=dim1;index++){ //CICLO PER OGNI LETTERA DELLA STRINGA
        if(index == 0){
            stringaTagliata=strstr(daTagliare,s2);
        }
        else{
            stringaTagliata=strstr(s1,s2);
        }
        indexTagliata=dim1-strlen(stringaTagliata)-1;
        for (int j=0;j<=indexTagliata;j++){
                        nS[index2]=s1[index1];
                        index2++;
                        index1++;
                    }

        for (int i=0;i<dim2;i++){
                if (stringaTagliata[i]==s2[i] && i==dim2-1){
                    nS[index2]='*';
                    index2++;
                }
                index1++;
        }
        //printf("%s\n",stringaTagliata);
        printf("NS: %s\n",nS);
        strcpy(s1,stringaTagliata);

    }
    //printf("Nuova stringa: %s\n",nS);
    //printf("%s\n",stringaTagliata);
    //printf("NS: %s",nS);
    getchar();
    return 0;

}
