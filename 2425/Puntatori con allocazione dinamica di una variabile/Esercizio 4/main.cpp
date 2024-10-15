// Gestione di Studenti
#include <iostream>

using namespace std;

const int MAX_ARRAY = 5;

struct studente {
    string nome;
    int eta;
};

void inserimentoStudenti(studente *gestionale) {
    for (int i = 0; i < MAX_ARRAY; i++)
    {
        cout << "Inserire il nome dello studente numero " << i << ": ";
        cin >> (gestionale + i)->nome;
        cout << "Inserire l\'eta\' dello studente numero " << i << ": ";
        cin >> (gestionale + i)->eta;
    }
}

void stampa(studente *gestionale) {
    for (int i = 0; i < MAX_ARRAY; i++)
    {
        cout << "Nome: " << (gestionale + i)->nome << endl;
        cout << "Eta\': " << (gestionale + i)->eta << endl;
        cout << endl;
    }
}

int main() {
    studente *gestionale = new studente[MAX_ARRAY];

    inserimentoStudenti(gestionale);
    stampa(gestionale);

    delete [] gestionale;
    return 0;
}