
/********************************************************************************************************************

Alcune librerie e funzioni potrebbero non essere disponibili su tutti i sistemi operativi.
Per problemi di compatibilità su linux e altri IDE, la funzione sleep() è stata commentata.

********************************************************************************************************************/

#include <iostream>
#include <stdlib.h>
//#include <Windows.h>
#include <unistd.h>   
#include <cstdlib>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
const int MAX_ARRAY = 100;

struct vocabolario {
    string ita;
    string eng;
};


void aggiungiVocabolo(int nparola, vocabolario arrayDizionario[]) {
    cout << "inserire vocabolo in italiano: ";
    cin >> arrayDizionario[nparola].ita;
    cout << "inserire vocabolo in inglese: ";
    cin >> arrayDizionario[nparola].eng;
    cout << "Vocabolo aggiunto con successo!\n" << arrayDizionario[nparola].ita << " - " << arrayDizionario[nparola].eng << endl;
    //sleep(3000);
    system("clear");
    return;
}

void visualizzaDizionario(int nparola, vocabolario arrayDizionario[]) {
    //caso vocabolario vuoto
    if (nparola == 0) {
        cout << "Dizionario vuoto\n";
        return;
    }
    else {
        //print parole vocabolario escludendo possibili parole eliminate
        system("clear");
        for (int i = 0; i < nparola; i++) {
            if (arrayDizionario[i].ita != " " || arrayDizionario[i].eng != " ") {
                cout << arrayDizionario[i].ita << " - " << arrayDizionario[i].eng << endl;
            }
        }
        return;
    }
}

void editDizionario(int nparola, int selezione, string& parolaDaSostituire, string& searchWord, vocabolario arrayDizionario[]) {
    //possibilitā di modificare / eliminare
    system("clear");
    cout << "1. Modificare\n2. Cancellare\n";
    cout << "selezione: ";
    cin >> selezione;
    if (selezione == 1) {
        cout << "parola: ";
        cin >> searchWord;
        //ricarca parola
        for (int i = 0; i < nparola; i++) {
            //caso parola in italiano
            if (searchWord == arrayDizionario[i].ita) {
                cout << "inserire parola con cui sostituire: ";
                cin >> parolaDaSostituire;
                arrayDizionario[i].ita = parolaDaSostituire;
                cout << "parola sostituita con successo!\n";
                //sleep(3000);
                system("clear");
                return;
            }
            //caso parola in inglese
            else if (searchWord == arrayDizionario[i].eng) {
                cout << "inserire parola con cui sostituire: ";
                cin >> parolaDaSostituire;
                arrayDizionario[i].eng = parolaDaSostituire;
                cout << "parola sostituita con successo!\n";
                //sleep(3000);
                system("clear");
                return;
            }
        }
    }
    //caso eliminazione parola
    else if (selezione == 2) {
        cout << "parola: ";
        cin >> searchWord;
        //ricerca parola
        for (int i = 0; i < nparola; i++) {
            //per l'eliminazione assegno alla parola carattere blank
            if (searchWord == arrayDizionario[i].ita || searchWord == arrayDizionario[i].eng) {
                arrayDizionario[i].ita = " ";
                arrayDizionario[i].eng = " ";
                cout << "parola eliminata con successo!\n";
                //sleep(3000);
                system("clear");
            }
            else {
            }
        }
    }
}

void ordinamentoDizionario(string& temp, int selezione, int nparola, vocabolario arrayDizionario[]) {
    cout << "Ordinare per italiano = 1, inglese = 2" << endl;
    cout << "selezione: ";
    cin >> selezione;
    if (selezione == 1) {
        //bubble sort di string caso italiano
        for (int i = 1; i < nparola; i++) {
            for (int j = 0; j < nparola - 1; j++) {
                if (arrayDizionario[j].ita > arrayDizionario[j + 1].ita) {
                    temp = arrayDizionario[j].ita;
                    arrayDizionario[j].ita = arrayDizionario[j + 1].ita;
                    arrayDizionario[j + 1].ita = temp;
                    temp = arrayDizionario[j].eng;
                    arrayDizionario[j].eng = arrayDizionario[j + 1].eng;
                    arrayDizionario[j + 1].eng = temp;
                }
            }
        }
    }
    else if (selezione == 2) {
        //bubble sort di string caso inglese
        for (int i = 1; i < nparola; i++) {
            for (int j = 0; j < nparola - 1; j++) {
                if (arrayDizionario[j].eng > arrayDizionario[j + 1].eng) {
                    temp = arrayDizionario[j].eng;
                    arrayDizionario[j].eng = arrayDizionario[j + 1].eng;
                    arrayDizionario[j + 1].eng = temp;
                    temp = arrayDizionario[j].ita;
                    arrayDizionario[j].ita = arrayDizionario[j + 1].ita;
                    arrayDizionario[j + 1].ita = temp;
                }
            }
        }
    }
    return;
}

void exportDizionario(vocabolario arrayDizionario[],int nparola) {
    ofstream DizionarioTXT;
    DizionarioTXT.open("dizionario.txt", ios::out);

    //cercare parole dentro al file.txt e importarle nel dizionario
    for (int i = 0; i < nparola; i++) {
        DizionarioTXT << arrayDizionario[i].ita << "-" << arrayDizionario[i].eng << endl;
    }
    cout << "Dizionario esportato con successo.\n" << endl;
    DizionarioTXT.close();
    return;
}

void importDizionario(vocabolario arrayDizionario[], int& nparola) {
    ifstream DizionarioTXT;
    DizionarioTXT.open("dizionario.txt", ios::in);

    //caso file non esistente
    if (!DizionarioTXT) {
        cerr << "Impossibile trovare il file dizionario.txt";
        return;
    }

    //cercare parole dentro al file.txt e importarle nel dizionario
    string line;
    while (getline(DizionarioTXT, line)) {
        size_t pos = line.find('-');
        if (pos != string::npos) {
            arrayDizionario[nparola].ita = line.substr(0, pos);
            arrayDizionario[nparola].eng = line.substr(pos + 1);
            nparola++;
        }
    }

    DizionarioTXT.close();
}


int main() {
    //const int MAX_ARRAY = 100;
    int selezione, nparola = 0;
    string parola, searchWord, parolaDaSostituire, temp;
    vocabolario arrayDizionario[MAX_ARRAY];
    //menų
    do {
    cout << R"(
    1. Aggiungere vocaboli al dizionario
    2. Visualizzare dizionario
    3. Modificare o cancellare vocaboli
    4. Ordinare dizionario
    5. Esporta dizionario in dizionario.txt
    6. Importa dizionario da dizionario.txt
    0. Esci
    )";
    cout << "selezione: ";
    cin >> selezione;
    switch(selezione) {
        case 1:
            aggiungiVocabolo(nparola, arrayDizionario);
            nparola++;
            break;
        case 2:
            visualizzaDizionario(nparola, arrayDizionario);
            break;
        case 3:
            editDizionario(nparola, selezione, searchWord, parolaDaSostituire, arrayDizionario);
            break;
        case 4:
            ordinamentoDizionario(temp, selezione, nparola, arrayDizionario);
            break;
        case 5:
            exportDizionario(arrayDizionario, nparola);
            break;
        case 6:
            importDizionario(arrayDizionario, nparola);
            break;
        case 7:
            break;
        default:
            break;
    }
} while (selezione);
    return 0;
}