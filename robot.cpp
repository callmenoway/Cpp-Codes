/********************************************************************************************************************

Alcune librerie e funzioni potrebbero non essere disponibili su tutti i sistemi operativi.
Per problemi di compatibilità su linux e altri IDE, la funzione sleep() è stata commentata.

********************************************************************************************************************/

#include <iostream>
#include <stdlib.h>
//#include <Windows.h>
#include <unistd.h>   
#include <cstdlib>
#include <vector>

using namespace std;

// const int MAX_ARRAY=100;

struct Robot{
    string nome;
    int velocita;
    int resistenza;
    string abilitaSpeciale;
};  

void dichiarazioneRobot(vector<Robot> listarobot, int numero, string temp, int abilita){
    cout << "inserire numero robot partecipanti: ";
    cin >> numero;
    for(int i = 1; i <= numero; i++){
        cout << "inserire il nome del robot " << i << ": " << endl;
        cin >> temp;
        cout << "Selezionare l'abilita' del robot " << i << ": " << endl;
        cout << "1. Velocita' " << "2. Resistenza " << endl;
        cin >> abilita;
        struct Robot r = { temp, rand()%100, rand()%100, to_string(abilita) };
        listarobot.push_back(r);
    }
    for(int i = 0; i < listarobot.size(); i++){
        cout << listarobot[i].nome << " " << listarobot[i].velocita << " " << listarobot[i].resistenza << " " << listarobot[i].abilitaSpeciale << endl;
    }
}

int main(){
    int randomability, sommabilityv = 100, sommabilityr = , numero, abilita, turni = 3;
    string temp;
    vector<Robot> listarobot;
    dichiarazioneRobot(listarobot, numero, temp, abilita);
    for(int i = 0; i < turni; i++){
        randomability = rand()%numero;
        listarobot[randomability].velocita =
    }
}