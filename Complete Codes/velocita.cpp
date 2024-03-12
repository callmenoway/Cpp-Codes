/********************************************************************************************************************

Alcune librerie e funzioni potrebbero non essere disponibili su tutti i sistemi operativi.
Per problemi di compatibilità su linux e altri IDE, alcune funzioni potrebbero essere commentate.

********************************************************************************************************************/
#ifdef __unix__

    #define OS_Windows 0
    #include <iostream>
    #include <stdlib.h>
    #include <cstdlib>
    #include <cstring>
    #include <unistd.h>
    #include <fstream>
    #include <chrono>

#elif defined(_WIN32) || defined(WIN32)

    #define OS_Windows 1
    #include <iostream>
    #include <windows.h>
    #include <stdlib.h>
    #include <cstdlib>
    #include <cstring>
    #include <unistd.h>
    #include <fstream>
    #include <chrono>

#endif

using namespace std;
using namespace std::chrono;

//funzione per pulire la console che posso richiamare quando voglio
void clearConsole() {
    if(OS_Windows)
        system("cls");
    else if(!OS_Windows)
        system("clear");
} 

void inputnumero(long long& N){
    cout << "Inserire un numero: ";
    cin >> N;
    return;
}

void calcolaSommaFor(long long N){
    long long temp = 0;
    auto start = high_resolution_clock::now();
    for(int i = 1; i <=N; i++){
        temp = temp + i;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
     
    cout << "Tempo di esecuzione ciclo FOR: " << duration.count() << " microsecondi" << endl;
    //cout << temp << endl;
}

void calcolaSommaFormula(long long N){
    long long temp = 0;
    auto start = high_resolution_clock::now();
    temp = (N*(N + 1))/2;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
     
    cout << "Tempo di esecuzione FORMULA: " << duration.count() << " microsecondi" << endl;
    //cout << temp << endl;
}

int main() {
    long long N;
    inputnumero(N);
    calcolaSommaFor(N);
    calcolaSommaFormula(N);
    return 0;
}