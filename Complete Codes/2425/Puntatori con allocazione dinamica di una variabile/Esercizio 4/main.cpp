// Gestione di Studenti
#include <iostream>

using namespace std;

const int MAX_ARRAY = 5;

struct studente {
    string nome;
    int eta;
};

void inserimentoStudenti(studente *ptr) {
    for (int i = 0; i < MAX_ARRAY; i++)
    {
        cout << "Inserire il nome dello studente numero " << i << ": ";
        cin >> (studente + i)->nome;
    }
    
}

int main() {
    studente *ptr = new studente[MAX_ARRAY];

    inserimentoStudenti(ptr);

    return 0;
}