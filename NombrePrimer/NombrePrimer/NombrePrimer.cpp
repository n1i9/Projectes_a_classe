#include <iostream> //Llibreria bàsica
#include <cmath> //Llibreria que he posar ja que és necessaria per a calcular l'arrel quadrada

using namespace std; //Permet posar funcions sense std davant

int main() { //Variable principal
    int numero; //Variable on el jugador posa el numero que vol
    bool esPrimer = true; //Variable per a dir si si o si no es primer

    cout << "Determinacio de numero primer, introdueix un nombre: "; //Demana a l'usuari introduïr un nombre
    cin >> numero; //L'usuari introdueix un nombre

    if (numero <= 1) { //Si aquest nombre és igual o més petit a 1, directament no és primer
        esPrimer = false; //La variable que diu si es primer, es posa en fals
    }
    else if (numero == 2) { //Si directament l'usuari posa 2, indica que si es primer, ja que es l'unic parell primer
        esPrimer = true; //La variable que diu si es primer, es posa en true
    }
    else if (numero % 2 == 0) { //Calcula si és un número doble ja que el divideix entre 2 i si el residu és 0, és parell per tant no es primer
        esPrimer = false; //La variable que diu si es primer, es posa en fals
    }
    else { //Si no és ni parell ni és el 2 ni es igual o més petit a 1, segueix calculant
        double sqrt_of_n = sqrt(numero); //Variable double per a fer l'arrel quadrada del nombre

        for (int i = 3; i <= sqrt_of_n; i += 2) { //Bucle per a calcular l'arrel quadrada del nombre indroduït per a l'usuari
            if (numero % i == 0) { //Si el numero entre el resultat de l'arrel quadrada dona 0
                esPrimer = false; //La variable que diu si es primer, es posa en fals
                break; //Trenca el bucle
            }
        }
    }
    if (esPrimer) { //Si la variable esPrimer es true
        cout << "El nombre " << numero << " Si es primer." << endl; //Indica a l'usuari que el numero si es primer
    }
    else { //Si la variable esPrimer es false
        cout << "El nombre " << numero << " No es primer." << endl; //Indica a l'usuari que el numero no es primer
    }
    return 0; //Marca el final del programa
}