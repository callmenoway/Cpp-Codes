//Allocazione Dinamica di un Array
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAX_ARRAY = 5;

int inserimentoDati (int *a, int somma) {
    for (int i = 0; i < MAX_ARRAY; i++) {
        cout << "Inserisci valore: ";
        cin >> *(a + i);
        cout << endl;
        somma = somma + *(a + i);
    }
    return somma;
}

int main()
{
    int *a = new int[MAX_ARRAY];
    int somma = 0;

    cout << inserimentoDati(a, somma);

    return 0;
}