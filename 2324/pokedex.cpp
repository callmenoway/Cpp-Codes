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

const int MAX_ARRAY = 10;

//definizione array pokemon
struct pokemon {
    string name;
    string type;
    int level;
    int exp;
};

//funzione che cattura un nuovo pokemon
void captureNewPokemon(int& localPokemon, pokemon arrayPokedex[]) {
    cout << "Inserire nome pokemon: ";
    cin >> arrayPokedex[localPokemon].name ;
    cout << "Inserire tipo pokemon: ";
    cin >> arrayPokedex[localPokemon].type;
    cout << "Inserire livello pokemon: ";
    cin >> arrayPokedex[localPokemon].level;
    cout << "Inserire esperienza pokemon: ";
    cin >> arrayPokedex[localPokemon].exp;
    cout << "Pokemon aggiunto con successo!\n";
    localPokemon++;
    //sleep(3000);
    system("clear");
}

//funzione che mostra il pokedex
void showPokedex(int localPokemon, pokemon arrayPokedex[]) {
    //caso vocabolario vuoto
    if (localPokemon == 0) {
        cout << "Pokedex vuoto\n";
    }
    else {
        //print parole vocabolario escludendo possibili parole eliminate
        system("clear");
        for (int i = 0; i < localPokemon; i++) {
            cout << arrayPokedex[i].name << " - " << arrayPokedex[i].type << " - " << arrayPokedex[i].level << " - " << arrayPokedex[i].exp << endl;
        }
    }
}

//funzione che salva il pokedex su file.txt
void savePokedex(int localPokemon, pokemon arrayPokedex[]) {
    //caso vocabolario vuoto
    if (localPokemon == 0) {
        cout << "Nulla da salvare...\n";
        return;
    }else{
        ofstream pokedexTXT;
        pokedexTXT.open("pokedex.txt", ios::out);

        //cercare parole dentro al file.txt e importarle nel dizionario
        for (int i = 0; i < localPokemon; i++) {
            pokedexTXT << arrayPokedex[i].name << "-" << arrayPokedex[i].type << "-" << arrayPokedex[i].level << "-" << arrayPokedex[i].exp << endl;
        }
        cout << "Pokedex esportato con successo.\n" << endl;
        pokedexTXT.close();
    }
    //sleep(3000);
    system("clear");
}

//funzione che carica il pokedex da file.txt
void loadPokedex(int& localPokemon, pokemon arrayPokedex[]) {
    ifstream pokedexTXT;
    pokedexTXT.open("pokedex.txt", ios::in);

    //caso file non esistente
    if (!pokedexTXT) {
        cerr << "Impossibile trovare il file pokedex.txt";
        return;
    }

    //cercare parole dentro al file.txt e importarle nel dizionario
    string line;
    while (getline(pokedexTXT, line)) {
        size_t pos1 = line.find('-');
        size_t pos2 = line.find('-', pos1 + 1);
        size_t pos3 = line.find('-', pos2 + 1);
        if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) {
            arrayPokedex[localPokemon].name = line.substr(0, pos1);
            arrayPokedex[localPokemon].type = line.substr(pos1 + 1, pos2 - pos1 - 1);
            arrayPokedex[localPokemon].level = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
            arrayPokedex[localPokemon].exp = stoi(line.substr(pos3 + 1));
            localPokemon++;
        }
    }
    pokedexTXT.close();
    system("clear");
}

//funzione che ordina il pokedex in base al nome
void orderPokedex(int localPokemon, pokemon arrayPokedex[]) {
    for (int i = 0; i < localPokemon - 1; ++i) {
        for (int j = 0; j < localPokemon - i - 1; ++j) {
            if (arrayPokedex[j].name > arrayPokedex[j + 1].name) {
                pokemon temp = arrayPokedex[j];
                arrayPokedex[j] = arrayPokedex[j + 1];
                arrayPokedex[j + 1] = temp;
            }
        }
    }
    system("clear");
}

//funzione che elimina un pokemon
void deletePokemon(pokemon arrayPokedex[], int& localPokemon) {
    int eliminazione;
    cout << "Quale pokemon vorresti eliminare?";
    cout << "selezione: ";
    cin >> eliminazione;
    for (int i = eliminazione; i <= localPokemon; i++) {
        arrayPokedex[i].name = arrayPokedex[i + 1].name;
        arrayPokedex[i].type = arrayPokedex[i + 1].type;
        arrayPokedex[i].level = arrayPokedex[i + 1].level;
        arrayPokedex[i].exp = arrayPokedex[i + 1].exp;
    }
    localPokemon--;
    system("clear");
}

//funzione che cerca un pokemon
void findPokemon(pokemon arrayPokedex[], int localPokemon) {
    string searchValue;
    int searchValue1;
    int scelta;
    cout << R"(
        1. Nome
        2. Tipo
        3. Punti Lotta
        4. Esperienza
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
        for (int i = 1; i <= localPokemon; i++) {
            if (arrayPokedex[i].name == searchValue) {
                cout << "--------POKEMON STATS--------";
                cout << "Nome: " << arrayPokedex[i].name << endl;
                cout << "Tipo: " << arrayPokedex[i].type << endl;
                cout << "Punti Lotta: " << arrayPokedex[i].level << endl;
                cout << "Punti esperienza: " << arrayPokedex[i].exp << endl;
                found = true;
            }
        }
        break;
    case 2:
        for (int i = 1; i <= localPokemon; i++) {
            if (arrayPokedex[i].type == searchValue) {
                cout << "--------POKEMON STATS--------";
                cout << "Nome: " << arrayPokedex[i].name << endl;
                cout << "Tipo: " << arrayPokedex[i].type << endl;
                cout << "Punti Lotta: " << arrayPokedex[i].level << endl;
                cout << "Punti esperienza: " << arrayPokedex[i].exp << endl;
                found = true;
            }
        }
        break;
    case 3:
        for (int i = 1; i <= localPokemon; i++) {
            if (arrayPokedex[i].level == searchValue1) {
                cout << "--------POKEMON STATS--------";
                cout << "Nome: " << arrayPokedex[i].name << endl;
                cout << "Tipo: " << arrayPokedex[i].type << endl;
                cout << "Punti Lotta: " << arrayPokedex[i].level << endl;
                cout << "Punti esperienza: " << arrayPokedex[i].exp << endl;
                found = true;
            }
        }
        break;
    case 4:
        for (int i = 1; i <= localPokemon; i++) {
            if (arrayPokedex[i].exp == searchValue1) {
                cout << "--------POKEMON STATS--------";
                cout << "Nome: " << arrayPokedex[i].name << endl;
                cout << "Tipo: " << arrayPokedex[i].type << endl;
                cout << "Punti Lotta: " << arrayPokedex[i].level << endl;
                cout << "Punti esperienza: " << arrayPokedex[i].exp << endl;
                found = true;
            }
        }
        break;
    default:
        cout << "Selezione non valida.\n";
    }

    if (!found) {
        cout << "Nessun Pokemon trovato nel pokedex.\n";
    }

    //sleep(3000);
    system("clear");
}

int main() {
    pokemon arrayPokedex[MAX_ARRAY];
    int selezione, localPokemon = 0;

    do{
        //cout << "local pokemon = " << localPokemon << endl;
        cout << R"(
            1. Aggiungi nuovo pokemon
            2. Visualizza pokedex
            3. Salva pokedex
            4. Carica pokedex
            5. Ordina pokedex
            6. Elimina pokemon
            7. Cerca pokemon
            8. Esci
        )" << endl;
        cout << "selezione: ";
        cin >> selezione;

        switch (selezione) {
            case 1:
                captureNewPokemon(localPokemon, arrayPokedex);
                break;
            case 2:
                showPokedex(localPokemon, arrayPokedex);
                break;
            case 3:
                savePokedex(localPokemon, arrayPokedex);
                break;
            case 4:
                loadPokedex(localPokemon, arrayPokedex);
                break;
            case 5:
                orderPokedex(localPokemon, arrayPokedex);
                break;
            case 6:
                deletePokemon(arrayPokedex, localPokemon);
                break;
            case 7:
                findPokemon(arrayPokedex, localPokemon);
                break;
            case 8:
                exit(0);
                break;
            default:
                cout << "Selezione non valida\n";
                break;
        }
    }while(true);

    return 0;
}