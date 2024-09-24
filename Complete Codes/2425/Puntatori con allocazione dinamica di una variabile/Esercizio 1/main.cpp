//Allocazione Dinamica di una Variabile
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    int *a = new int;

    *a = 10;

    cout << *a;

    delete a;

    return 0;
}