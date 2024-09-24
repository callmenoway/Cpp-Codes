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

struct personaggi{
    string name;
    int level;
    string race; 
    int characterClass;
};

void importPersonaggi(int& localCharacters, personaggi arrayPersonaggi[]){
    ifstream charactersTXT;
    charactersTXT.open("characters.txt", ios::in);

    //caso file non esistente
    if (!charactersTXT) {
        cerr << "Impossibile trovare il file characters.txt";
        return;
    }

    //cercare parole dentro al file.txt e importarle nel dizionario
    string line;
    while (getline(charactersTXT, line)) {
        size_t pos1 = line.find(' ');
        size_t pos2 = line.find(' ', pos1 + 1);
        size_t pos3 = line.find(' ', pos2 + 1);
        if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) {
            arrayPersonaggi[localCharacters].name = line.substr(0, pos1); 
            arrayPersonaggi[localCharacters].level = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
            arrayPersonaggi[localCharacters].race = line.substr(pos2 + 1, pos3 - pos2 - 1);
            arrayPersonaggi[localCharacters].characterClass = stoi(line.substr(pos3 + 1));
            localCharacters++;
        }
    }
    charactersTXT.close();
    system("clear");
}

void ordinaPersonaggi(int localCharacters, personaggi arrayPersonaggi[]){
    for (int i = 0; i < localCharacters - 1; ++i) {
        for (int j = 0; j < localCharacters - i - 1; ++j) {
            if (arrayPersonaggi[j].name > arrayPersonaggi[j + 1].name) {
                personaggi temp = arrayPersonaggi[j];
                arrayPersonaggi[j] = arrayPersonaggi[j + 1];
                arrayPersonaggi[j + 1] = temp;
            }
        }
    }
        //caso vocabolario vuoto
    if (localCharacters == 0) {
        cout << "Nulla da salvare...\n";
        return;
    }else{
        ofstream charactersTXT;
        charactersTXT.open("sorted_characters.txt", ios::out);

        //cercare parole dentro al file.txt e importarle nel dizionario
        for (int i = 0; i < localCharacters; i++) {
            charactersTXT << arrayPersonaggi[i].name << " " << arrayPersonaggi[i].level << " " << arrayPersonaggi[i].race << " " << arrayPersonaggi[i].characterClass << endl;
        }
        cout << "Personaggi esportati con successo.\n" << endl;
        charactersTXT.close();
    }
    //sleep(3000);
    system("clear");
}

void searchPersonaggi(int localCharacters, personaggi arrayPersonaggi[]){
    string searchValue;
    int searchValue1;
    int scelta;
    cout << R"(
        1. Nome
        2. Livello
        3. Razza
        4. Classe
    )" << endl;

    cin >> scelta;

    if (scelta == 1 || scelta == 2) {
        cout << "Inserisci il valore di ricerca: ";
        cin >> searchValue;
    }
    else if (scelta == 3 || scelta == 4) {
        cout << "Inserisci il valore di ricerca: ";
        cin >> searchValue1;
    }
    bool found = false;

    switch (scelta) {
    case 1:
        for (int i = 1; i <= localCharacters; i++) {
            if (arrayPersonaggi[i].name == searchValue) {
                cout << "--------STATS--------" << endl;
                cout << "Nome: " << arrayPersonaggi[i].name << endl;
                cout << "Livello: " << arrayPersonaggi[i].level << endl;
                cout << "Razza: " << arrayPersonaggi[i].race << endl;
                cout << "Classe: " << arrayPersonaggi[i].characterClass << endl;
                found = true;
            }
        }
        break;
    case 2:
        for (int i = 1; i <= localCharacters; i++) {
            if (arrayPersonaggi[i].level == searchValue1) {
                cout << "--------STATS--------" << endl;
                cout << "Nome: " << arrayPersonaggi[i].name << endl;
                cout << "Livello: " << arrayPersonaggi[i].level << endl;
                cout << "Razza: " << arrayPersonaggi[i].race << endl;
                cout << "Classe: " << arrayPersonaggi[i].characterClass << endl;
                found = true;
            }
        }
        break;
    case 3:
        for (int i = 1; i <= localCharacters; i++) {
            if (arrayPersonaggi[i].race == searchValue) {
                cout << "--------STATS--------" << endl;
                cout << "Nome: " << arrayPersonaggi[i].name << endl;
                cout << "Livello: " << arrayPersonaggi[i].level << endl;
                cout << "Razza: " << arrayPersonaggi[i].race << endl;
                cout << "Classe: " << arrayPersonaggi[i].characterClass << endl;
                found = true;
            }
        }
        break;
    case 4:
        for (int i = 1; i <= localCharacters; i++) {
            if (arrayPersonaggi[i].characterClass == searchValue1) {
                cout << "--------STATS--------" << endl;
                cout << "Nome: " << arrayPersonaggi[i].name << endl;
                cout << "Livello: " << arrayPersonaggi[i].level << endl;
                cout << "Razza: " << arrayPersonaggi[i].race << endl;
                cout << "Classe: " << arrayPersonaggi[i].characterClass << endl;
                found = true;
            }
        }
        break;
    default:
        cout << "Selezione non valida.\n";
    }

    if (!found) {
        cout << "Nessun personaggio trovato.\n";
    }

    //sleep(3000);
    //system("clear");
}

void printPersonaggi(int localCharacters, personaggi arrayPersonaggi[]){
    for(int i = 0; i < localCharacters; i++){
        cout << arrayPersonaggi[i].name << " " << arrayPersonaggi[i].level << " " << arrayPersonaggi[i].race << " " << arrayPersonaggi[i].characterClass <<endl;
    }
}

int main(){
    int localCharacters = 0, selezione;
    personaggi arrayPersonaggi[MAX_ARRAY]; //declare all array
    do{
        cout << R"(
            1. Importa personaggi
            2. Ordina personaggi
            3. Ricerca personaggi
            4. Visualizza personaggi
            selezione:
        )" << endl;
        cin >> selezione;
        switch (selezione){
            case 1:
                importPersonaggi(localCharacters, arrayPersonaggi);
                break;
            case 2:
                ordinaPersonaggi(localCharacters, arrayPersonaggi);
                break;
            case 3:
                searchPersonaggi(localCharacters, arrayPersonaggi);
                break;
            case 4:
                printPersonaggi(localCharacters, arrayPersonaggi);
                break;
            default:
                cout << "Selezione non valida" << endl;
                break;
        }
    }while(true);
}