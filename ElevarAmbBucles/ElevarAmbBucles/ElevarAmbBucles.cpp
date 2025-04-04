// ElevarAmbBucles.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

int main()
{
	int pedra = 1;
	int tisores = 2;
	int paper = 3;
	int jugador;
	int maquina;

	cout << "Tria entre pedra (1), paper(2) o tisores(3)\n";
	cin >> jugador;

	maquina = 1 + rand() % 3;
	cout << "La maquina ha triat: " << maquina << endl;

	if (maquina == jugador) {
		cout << "Has empatat";
	}
	else if (maquina == 1 && jugador == 2)
	{
		cout << "Has pedut";
	}
	else if (maquina == 1 && jugador == 2)
	{
		cout << "Has pedut";
	}
	else if (maquina == 1 && jugador == 2)
	{
		cout << "Has pedut";
	}
	else if (maquina == 1 && jugador == 2)
	{
		cout << "Has pedut";
	}
	else if (maquina == 1 && jugador == 2)
	{
		cout << "Has pedut";
	}
	else if (maquina == 1 && jugador == 2)
	{
		cout << "Has pedut";
	}

}