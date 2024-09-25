// Copia di un Array con Allocazione Dinamica
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAX_ARRAY = 5;

void inserimentoDati (int array1[]) {
    for (int i = 0; i < MAX_ARRAY; i++) {
        cout << "Inserisci valore: ";
        cin >> *(array1 + i);
        cout << endl;
    }
}

void copia(int array1[], int array2[]) {
    for (int i = 0; i < MAX_ARRAY; i++) {
        *(array2 + i) = *(array1 + i);
    }
}

int main() {
    int *array1 = new int[MAX_ARRAY];

    int *array2 = new int[MAX_ARRAY];

    inserimentoDati(array1);

    copia(array1, array2);

    // for (int i = 0; i < MAX_ARRAY; i++) {
    //     cout << *(array2 + i) << endl;
    // }
    
    delete array1;
    delete array2;

    return 0;
}