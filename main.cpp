#include <iostream>
#include <stdlib.h>
//#include <Windows.h>
//#include <system>
#include<unistd.h>   
#include <cstdlib>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

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
    //system("clear");
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

    for (int i = 0; i < nparola; i++) {
        DizionarioTXT << arrayDizionario[i].ita << "-" << arrayDizionario[i].eng << endl;
        cout << arrayDizionario[i].ita << "-" << arrayDizionario[i].eng << endl;
    }
    cout << "Dizionario esportato con successo." << endl;
    DizionarioTXT.close();

    return;
}

// void importDizionario(vocabolario arrayDizionario[], int nparola) {
//     ifstream DizionarioTXT;
//     DizionarioTXT.open("dizionario.txt", ios::in);
//     string line;
//     while (getline(DizionarioTXT, line)) {
//         arrayDizionario[nparola].ita = line.substr(0, line.find("-"));
//         arrayDizionario[nparola].eng = line.substr(line.find("-") + 1, line.length());
//         nparola++;
//     }
//     cout << "Dizionario importato con successo." << endl;
//     DizionarioTXT.close();
//     return;
// }
void importDizionario(vocabolario arrayDizionario[], int nparola) {
    string riga;
    ofstream mioFile;              //file di input x leggere
    mioFile.open("dizionario.txt", ios::in); //apre il file in lettura
    for(int i = 0; i < 1; i++){
    //mioFile>>parola;            //legge caratteri fino allo spazio o fine riga (una parola)
    // getline (mioFile, riga);      //legge un'intera riga fino fine riga
    // getline (cin, riga);
    arrayDizionario[nparola].ita = riga.substr(0, riga.find("-"));
    cout << arrayDizionario[nparola].ita << endl;
    }
    //cout<<parola;               //la visualizza a video
   

    mioFile.close();
    return;
}

int main() {
    const int MAX_ARRAY = 100;
    int selezione, nparola = 0;
    string parola, searchWord, parolaDaSostituire, temp;
    vocabolario arrayDizionario[MAX_ARRAY];
    //menų
    do {
        cout << "1. Aggiungere vocaboli al dizionario\n";
        cout << "2. Visualizzare dizionario\n";
        cout << "3. Modificare o cancellare vocaboli\n";
        cout << "4. Ordinare dizionario\n";
        cout << "5. Esporta dizionario in dizionario.txt\n";
        cout << "6. Importa dizionario da dizionario.txt\n";
        cout << "7. Esci\n";
        cout << "selezione: ";
        cin >> selezione;
        //add vocaboli
        if (selezione == 1) {
            aggiungiVocabolo(nparola, arrayDizionario);
            nparola++;
        }
        //view vocaboli
        else if (selezione == 2) {
            //sleep(3000);
            visualizzaDizionario(nparola, arrayDizionario);
        }
        //del/modify vocaboli
        else if (selezione == 3) {
            editDizionario(nparola, selezione, searchWord, parolaDaSostituire, arrayDizionario);
        }
        //bubble sort vocaboli
        else if (selezione == 4) {
            ordinamentoDizionario(temp, selezione, nparola, arrayDizionario);
        }
        //esporta dizionario file txt
        else if (selezione == 5) {
            exportDizionario(arrayDizionario, nparola);
        }
        //importa dizionario file txt
        else if (selezione == 6) {
            importDizionario(arrayDizionario, nparola);
        }
        
        //nessuno dei casi
        else {
            break;
        }
    } while (true);
    return 0;
}