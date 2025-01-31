#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

int main()
{
    int random;
    string usuari;
    int pedra;
    int paper;
    int tisores;
    int numeros;
    bool jugar = 1;
    int tornarajugar;

    while (jugar == true) {
    system("cls");
    srand(time(0));
    cout << "Benvingut al joc de Pedra, Paper i Tisores!\n";
    cout << "Selecciona un element per a jugar (La primera lletra en majuscula)\n";
    cin >> usuari;
    random = rand() % 3;
    string eleccio[3] = { "Pedra", "Paper", "Tisores"};
    cout << "El programa ha triat: " << eleccio[random];
    cout << "\nTu havies triat: " << usuari<<endl;

    if (usuari == eleccio[random]) {
        cout << "Has empatat!\n";
    }
    else if ((usuari == "Pedra" && eleccio[random] == "Tisores") ||
        (usuari == "Paper" && eleccio[random] == "Pedra") ||
        (usuari == "Tisores" && eleccio[random] == "Paper")) {
        cout << "Has guanyat!\n";
    }
    else {
        cout << "Has perdut!\n";
    }
    jugar == false;
    cout << "Vols tornar a jugar? Selecciona 1 per a tornar a jugar\n";
    cin >> tornarajugar;
    if (tornarajugar == 1) {
        jugar = true;
    }
    else {
        jugar = false;
    }
    }
}
