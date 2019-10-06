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
    int addizione,sottrazione,divisione,moltiplicazione,modulo;

    addizione=a+b; //operatore +
    sottrazione=a-(-b);  //operatore - e operatore inversione di segno di b
    divisione=a/b;   //operatore /
    moltiplicazione=a*b; //operatore *
    modulo=a%b; //restituisce il resto della divisione tra a e b

    float divisioneF;
    divisioneF=-c/b; // il risultato della divisione in questo caso ha la virgola e con il segno di c
    printf("%f",divisioneF);
    a++; //incrementa di 1 il valore di a
    b--; //decrementa di 1 il valore di b
    a+=2; //incrementa di 2 il valore di a
    a-=2;//decrementa di 2 il valore di a
    a*=2; // moltiplica per 2 a e assegna ad a il risultato
    a/=2; //divide per 2 a e assegna ad a il risultato
    a%=2; //ottiene il resto della divisione a/2 e assegna ad a il risultato ottenuto
    b=a++; //assegna a b il valore di a e poi incrementa di 1 il valore di a
    b=a--; //assegna a b il valore di a e poi decrementa di 1 il valore di a


    return 0;
}
