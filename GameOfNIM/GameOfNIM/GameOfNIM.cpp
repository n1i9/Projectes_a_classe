#include <iostream>

using namespace std;

int main()
{
    int punts[2];
    string noms[2];
    int nombre;
    int resta;
    bool jugar = true;
    string tornarajugar;

    while (jugar) {
        jugar = false;
        cout << "Benvinguts al joc del NIM" << endl;

        for (int i = 0; i < 2; i++) {
            cout << "Introdueix el jugador " << i + 1 << ": " << endl;
            cin >> noms[i];
            cout << "Intrudeix els punts del jugador " << i + 1 << ": " << endl;
            cin >> punts[i];
        }

        int maxPunts = punts[0];
        string nomMax = noms[0];

        for (int r = 1; r < 2; r++) {
            if (punts[r] > maxPunts) {
                maxPunts = punts[r];
                nomMax = noms[r];
            }
        }

        cout << "El jugador " << nomMax << " amb el nombre " << maxPunts << " comenca a restar" << endl;
        nombre = maxPunts;
        bool bucle = true;
        string jugadorActual = nomMax;

        while (bucle) {
            cout << "Jugador " << jugadorActual << " resta 1 o 2 al nombre: " << nombre << endl;
            cin >> resta;
            nombre = nombre - resta;
            cout << "Ara el nombre es: " << nombre << endl;


            if (nombre <= 0) {
                cout << "El jugador: " << jugadorActual << " ha guanyat!" << endl;
                break;
            }

            if (jugadorActual == noms[0]) {
                jugadorActual = noms[1];
            }
            else {
                jugadorActual = noms[0];
            }

        }
        cout << "Vols tornar a jugar? Escriu SI per a tornar a jugar, escriu NO per a tancar el programa" << endl;
        cin >> tornarajugar;
        if (tornarajugar == "SI") {
            jugar = true;
        }
        else if (tornarajugar == "NO") {
            cout << "Fins aviat!" << endl;
        }
    }
    return (0);
}