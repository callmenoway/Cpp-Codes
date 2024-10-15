//Modifica di un Array Tramite Puntatori
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

void Somma (int *ptrArray, int lunghezza) {
    //ciclo per moltiplicare x2 ogni contenuto dell'array
    for (int i = 0; i < lunghezza; i++){
        *(ptrArray + i) = *(ptrArray + i) * 2;
    }
    return;
}

int main()
{
    int array[] = {10, 10, 10, 10, 10}; //dichiarazione array
    int lunghezza = sizeof(array) / sizeof(array[0]); //dichiarazione lunghezza dell'array
    int *ptrArray = array; //puntatore su array

    Somma(ptrArray, lunghezza); //richiamo funzione
    
    /*test per verificare la funzionalità

    for (int i = 0; i < lunghezza; i++) {
        cout << *(ptrArray + i);
    }

    */

    return 0;
}