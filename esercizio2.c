/*
author: Davide Di marco
date: 06/10/2019
notes:
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    /*Utilizzo degli operatori aritmetici*/
    int a=10;
    int b=5;
    float c=2.1678;
    printf("a=%d,b=%d,c=%f\n",a,b,c);
    printf("Operatore: + ->  %d+%d=%d\n",a,b,a+b); //addizione
    printf("Operatore: - ->  %d-%d=%d\n",a,b,a-b); //sottrazione
    printf("Operatore: / ->  %d/%d=%d\n",a,b,a/b); //divisione, vale anche per i float e il segno del risultato è
    printf("Operatore: * ->  %d*%d=%d\n",a,b,a*b); //moltiplicazione
    printf("Operatore: %% ->  %d%%%d=%d\n",a,b,a%b); //modulo della divisione
    printf("Operatore: ++a (Incremento e assegnazione) -> %d \n",++a); //incrementa a e assegna ad a il valore incrementato
    printf("Operatore: --a (Decremento e assegnazione) -> %d \n",--a); //decrementa a e assegna ad a il valore decrementato
    printf("Operatore: a++ (assegnazione e incremento) -> %d \n",a++);
    printf("Operatore: a-- (assegnazione e decremento) -> %d \n",a--);
    printf("----------Operatori compatti----------\n");
    printf("Operatore: += -> a+=2 = %d \n",a+=2); //assegna ad a il valore di a+2
    printf("Operatore: -= -> a-=2 = %d \n",a-=2); //assegna ad a il valore a-2
    printf("Operatore: *= -> a*=2 = %d \n",a*=2); //assegna ad a il valore di a*2
    printf("Operatore: /= -> a/=2 = %d \n",a/=2); //assegna ad a il valore di a/2
    printf("Operatore: %%= -> a%%=2 = %d \n",a%=2); //assegna ad a il valore di a%2 (resto della divisione a/)

    /* Utilizzo degli operatori relazionali e logici tramite costrutto if */

    int temp=1000;

    if (temp>-100 && temp<100 ){
        if (temp>=0 && temp<=3){
            printf("Pericolo ghiaccio!\n");
        }
        else if (temp>3 && temp!=50)
        {
            printf("No pericolo ghiaccio!\n");
        }
        else if (temp==50){
            printf("Sei nel deserto del Sahara");
        }
    }
    else
    {
       printf("Temperatura non valida\n");
    }

    //PROVA OPERATORE OR
    char carattere='a';
    if (carattere=='a' || carattere=='e' || carattere=='i' || carattere=='o' || carattere=='u'){ //se è la lettera a,e,i,o,u allora
        printf("Il carattere e\' una vocale\n");
    }

    //PROVA OPERATORE NOT
    int opNOT=1;
    printf("%d\n",opNOT);
    opNOT=!opNOT;
    printf("%d\n",opNOT);
    //PROVO AD ASSEGNARE UN VALORE TROPPO ALTO AD UNA VARIABILE DI TIPO INT
    int valueInt=9999999999999999999; //overflow, il comportamento è indefinito
    printf("Valore della variabile (errato): %d\n",valueInt);
    //Assegno ad una variabile char un numero con la virgola
    char valueChar= 1.254;
    printf("Valore della variabile char (errato): %c\n",valueChar);


    getchar();
    return 0;
};
