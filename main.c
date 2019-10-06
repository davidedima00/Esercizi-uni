/*
Author: Davide Di marco
Date: 04/10/2019
Note: Il seguente programma stampa a video il valore minimo, massimo delle variabili l'occupazione in memoria
      per ogni tipo di dato ed infine il numero di caratteri stampati da ogni funzione printf

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main()
{

    /*Dichiaro e inizializzo tutti i tipi di variabili possibili con CHAR*/
    char carattere='$';
    unsigned char uChar=184;
    signed char sChar=-26;


   /*Dichiaro e inizializzo tutti i tipi di variabili possibili con INT*/
    int vInt=1045;
    unsigned int uInt=12456;
    signed int sInt=-25;

    /*Dichiaro e inizializzo tutti i tipi di variabili possibili con SHORT*/
    short int shortInt=10;
    unsigned short int usInt=1254;
    signed short int ssInt=-82;

    /*Dichiaro e inizializzo tutti i tipi di variabili possibili con LONG*/
    long int lInt=37894657;
    unsigned long int ulInt =12345699;
    signed long int slInt= -2067894558;


    /*Dichiaro e inizializzo tutti i tipi di variabili possibili con DOUBLE*/
    float vFloat=1.2134541345f;
    double vDouble=1.256789178f;
    long double lDouble=1.23545899654f;


    int carStampati; //dichiaro una variabile per inserire allinterno i caratteri stampati dal printf

    /*STAMPO LE COMBINAZIONI PER IL TIPO CHAR*/
    carStampati=printf("TYPE: %-19s | VALUE: %15c | ALLOCATED: %2d byte | MAX_VALUE: %012d | MIN_VALUE: %012d","CHAR",carattere,sizeof(char),CHAR_MAX,CHAR_MIN);
    printf(" | CHARS PRINTED: %-03d\n",carStampati);

    carStampati=printf("TYPE: %-19s | VALUE: %15c | ALLOCATED: %2d byte | MAX_VALUE: %12d | MIN_VALUE: %12d","UNSIGNED CHAR",uChar,sizeof(unsigned char),UCHAR_MAX,0);
    printf(" | CHARS PRINTED: %-03d\n",carStampati);

    carStampati=printf("TYPE: %-19s | VALUE: %15c | ALLOCATED: %2d byte | MAX_VALUE: %12d | MIN_VALUE: %12d","SIGNED CHAR",sChar,sizeof(signed char),SCHAR_MAX,SCHAR_MIN);
    printf(" | CHARS PRINTED: %-03d\n",carStampati);



    carStampati=printf("TYPE: %-19s | VALUE: %15d | ALLOCATED: %2d byte | MAX_VALUE: %12d | MIN_VALUE: %12d","INT",vInt,sizeof(int),INT_MAX,INT_MIN);
    printf(" | CHARS PRINTED: %-03d\n",carStampati);

    carStampati=printf("TYPE: %-19s | VALUE: %15u | ALLOCATED: %2d byte | MAX_VALUE: %12u | MIN_VALUE: %12d","UNSIGNED INT",uInt,sizeof(unsigned int),UINT_MAX,0);
    printf(" | CHARS PRINTED: %-03d\n",carStampati);

    carStampati=printf("TYPE: %-19s | VALUE: %15i | ALLOCATED: %2d byte | MAX_VALUE: %12d | MIN_VALUE: %12d","SIGNED INT",sInt,sizeof(signed int),INT_MAX,INT_MIN);
    printf(" | CHARS PRINTED: %-03d\n",carStampati);

    carStampati=printf("TYPE: %-19s | VALUE: %15d | ALLOCATED: %2d byte | MAX_VALUE: %12d | MIN_VALUE: %12d","SHORT INT",shortInt,sizeof(short int),SHRT_MAX,SHRT_MIN);
    printf(" | CHARS PRINTED: %-03d\n",carStampati);

    carStampati=printf("TYPE: %-19s | VALUE: %15u | ALLOCATED: %2d byte | MAX_VALUE: %12u | MIN_VALUE: %12u","UNSIGNED SHORT INT",usInt,sizeof(unsigned short int),USHRT_MAX,0);
    printf(" | CHARS PRINTED: %-03d\n",carStampati);

    carStampati=printf("TYPE: %-19s | VALUE: %15d | ALLOCATED: %2d byte | MAX_VALUE: %12d | MIN_VALUE: %12d","SIGNED SHORT INT",ssInt,sizeof(signed short int),SHRT_MAX,SHRT_MIN);
    printf(" | CHARS PRINTED: %-03d\n",carStampati);

    carStampati=printf("TYPE: %-19s | VALUE: %15d | ALLOCATED: %2d byte | MAX_VALUE: %12d | MIN_VALUE: %12d","LONG INT",lInt,sizeof(long int),LONG_MAX,LONG_MIN);
    printf(" | CHARS PRINTED: %-03d\n",carStampati);

    carStampati=printf("TYPE: %-19s | VALUE: %15u | ALLOCATED: %2d byte | MAX_VALUE: %12u | MIN_VALUE: %12d","UNSIGNED LONG INT",ulInt,sizeof(unsigned long int),ULONG_MAX,0);
    printf(" | CHARS PRINTED: %-03d\n",carStampati);

    carStampati=printf("TYPE: %-19s | VALUE: %15d | ALLOCATED: %2d byte | MAX_VALUE: %12d | MIN_VALUE: %12d","SIGNED LONG INT",slInt,sizeof(signed long int),LONG_MAX,LONG_MIN);
    printf(" | CHARS PRINTED: %-03d\n",carStampati);


    carStampati=printf("TYPE: %-19s | VALUE: %16.8f| ALLOCATED: %2d byte | MAX_VALUE: %12.4e | MIN_VALUE: %12.4e","FLOAT",vFloat,sizeof(float),FLT_MAX,FLT_MIN);
    printf(" | CHARS PRINTED: %-03d\n",carStampati);

    carStampati=printf("TYPE: %-19s | VALUE: %16.8lf| ALLOCATED: %2d byte | MAX_VALUE: %12.4e | MIN_VALUE: %12.4e","DOUBLE",vDouble,sizeof(double),DBL_MAX,DBL_MIN);
    printf(" | CHARS PRINTED: %-03d\n",carStampati);























    return 0;
}
