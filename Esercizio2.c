//Author: Davide Di marco | Filippo Venturini | Riccardo Leonelli
//Date(Deadline): 13-10-2019
//Notes: Esercizio 2
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Utilizzo degli operatori aritmetici*/
    int a=10;
    int b=5;
    float c=2.1678;
    printf("----------Operatori Aritmetici----------\n");
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
    printf("\n----------Operatori compatti----------\n");
    printf("Operatore: += -> a+=2 = %d \n",a+=2); //assegna ad a il valore di a+2
    printf("Operatore: -= -> a-=2 = %d \n",a-=2); //assegna ad a il valore a-2
    printf("Operatore: *= -> a*=2 = %d \n",a*=2); //assegna ad a il valore di a*2
    printf("Operatore: /= -> a/=2 = %d \n",a/=2); //assegna ad a il valore di a/2
    printf("Operatore: %%= -> a%%=2 = %d \n",a%=2); //assegna ad a il valore di a%2 (resto della divisione a/)

    /* Utilizzo degli operatori relazionali e logici tramite costrutto if */
    printf("\n----------Operatori AND, >, <, >=, <=, ==----------\n");
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
    printf("\n----------Operatore OR----------\n");
    char carattere='a';
    if (carattere=='a' || carattere=='e' || carattere=='i' || carattere=='o' || carattere=='u'){ //se è la lettera a,e,i,o,u allora
        printf("Il carattere e\' una vocale\n");
    }

    //PROVA OPERATORE NOT
    printf("\n----------Operatore NOT----------\n");
    int opNOT=1;
    printf("%d\n",opNOT);
    opNOT=!opNOT;
    printf("%d\n",opNOT);
    //PROVO AD ASSEGNARE UN VALORE TROPPO ALTO AD UNA VARIABILE DI TIPO INT
    printf("\n----------Overflow----------\n");
    int valueInt=9999999999999999999; //overflow, il comportamento è indefinito
    printf("Valore della variabile (Errato): %d\n",valueInt);
    //Assegno ad una variabile char un numero con la virgola
    printf("\n----------Assegnamento di un tipo non appropriato----------\n");
    char valueChar= 1.254;
    printf("Valore della variabile char (Errato): %c\n",valueChar);

    //OPERATORI BITWISE &,|,^,<<,>>,~

    printf("\n----------Operatori BITWISE----------\n");

    int n1=24,n2=12;
    int n3;

    n3=n1<<2; //sposta i bit di 2 spazi a sinistra, aggiungendo a destra degli 0
    printf("Numero iniziale: %d Numero finale: %d\n",n1,n3);
    n3=n1>>2; //sposta i bit di 2 spazi a destra, aggiungendo a sinistra degli 0
    printf("Numero iniziale: %d Numero finale: %d\n",n1,n3);
    n3=~n1; //inverte i bit 0 con 1 e 1 con 0
    printf("Numero iniziale: %d Numero finale: %d\n",n1,n3);
    n3=n1 & n2;
    printf("n1 & n2 (AND)- Numero finale: %d\n",n3);
    n3=n1 | n2;
    printf("n1 | n2 (OR)- Numero finale: %d\n",n3);
    n3=n1 ^ n2;
    printf("n1 ^ n2 (XOR)- Numero finale: %d\n",n3);



    //Side effects
    printf("\n----------Side effects----------\n");
    int p = 3;
    int x = p*p++; //Sia l'assegnamento che il post-incremento hanno side effects e provocano un risultato indefinito
    printf("Valore di x indefinito: x = %d\n", x);

    //Conversione implicita
    printf("\n----------Conversione Implicita----------\n");
    int numInt = 50;
    double numDouble = numInt; //Assegnamento di un valore intero ad una variabile double
    printf("Valore int automaticamente convertito in double e assegnato:\nnumInt = %d, numDouble = %e\n\n",numInt, numDouble); //Print dei risultati

    float numFloat = (float)numInt; //Casting di numInt in float
    printf("Valore int convertito in float con un cast:\nnumFloat = %f", numFloat);


    getchar();
    return 0;
}
