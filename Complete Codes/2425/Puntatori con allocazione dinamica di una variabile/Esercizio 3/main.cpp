// Copia di un Array con Allocazione Dinamica
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAX_ARRAY = 5;

void inserimentoDati (int *ptr1) {
    for (int i = 0; i < MAX_ARRAY; i++) {
        cout << "Inserisci valore: ";
        cin >> *(ptr1 + i);
        cout << endl;
    }
}

void copia(int *ptr1, int *ptr2) {
    for (int i = 0; i < MAX_ARRAY; i++) {
        *(ptr2 + i) = *(ptr1 + i);
    }
}

int main() {
    int array1[MAX_ARRAY];
    int *ptr1 = array1;

    int array2[MAX_ARRAY];
    int *ptr2 = array2;

    inserimentoDati(ptr1);

    copia(ptr1, ptr2);

    // for (int i = 0; i < MAX_ARRAY; i++) {
    //     cout << *(ptr2 + i) << endl;
    // }
    
    delete ptr1;
    delete ptr2;

    return 0;
}