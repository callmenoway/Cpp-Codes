//Somma di un Array tramite Puntatori
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

int Somma (int somma, int *ptrArray, int lunghezza) {
    //ciclo per fare la somma dei numeri contenuti nell'array
    for (int i = 0; i < lunghezza; i++){
        somma = somma + *(ptrArray + i);
    }
    return somma;
}

int main()
{
    int array[] = {10, 10, 10, 10, 10}; //dichiarazione array
    int lunghezza = sizeof(array) / sizeof(array[0]); //dichiarazione lunghezza dell'array
    int *ptrArray = array; //puntatore su array
    int somma = 0; //dichiaro la variabile che conterrà la somma

    cout << Somma(somma, ptrArray, lunghezza); //richiamo funzione e print finale del risultato
    
    return 0;
}