//Scambio di Valori con Puntatori
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

void scambioValori (int *ptr1, int *ptr2) {
    //dichiarazione della variabile temporanea per effettuare lo scambio di variabile
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    return;
}

int main()
{
    //dichiarazione variabili
    int var1 = 0;
    int var2 = 1;

    //dichiarazione puntatori (e assegnazione sulle relative variabili)
    int *ptr1 = & var1;
    int *ptr2 = & var2;

    scambioValori(ptr1, ptr2); //richiamo funzione per scambiare i due puntatori

    cout << *ptr1 << *ptr2; //test per verificare se lo scmabio è avvenuto con successo

    return 0;
}