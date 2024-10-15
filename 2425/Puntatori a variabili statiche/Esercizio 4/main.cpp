//Copia di un Array tramite Puntatori
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

void Somma (int *ptrArray, int lunghezza, int array2[5]) {
    //trasferisco i valori del puntatore all'array 2
    for (int i = 0; i < lunghezza; i++){
        array2[i] = *(ptrArray + i);
    }
    return;
}

int main()
{
    int array[] = {10, 10, 10, 10, 10}; //dichiarazione array
    int array2[5] = {}; //dichiarazione array copiatore
    int lunghezza = sizeof(array) / sizeof(array[0]); //dichiarazione lunghezza dell'array
    int *ptrArray = array; //puntatore su array

    Somma(ptrArray, lunghezza, array2); //richiamo funzione

    // for (int i = 0; i < lunghezza; i++) {
    //     cout << array2[i] << endl;
    // }

    return 0;
}