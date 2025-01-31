#include <iostream>

using namespace std;

int Nil(int Factorial);

int main() {
	int numero;
	int resultat = 1;

	cout << "Calculadora de nombre factorial, introdueix un nombre\n";
	cin >> numero;
	resultat = Nil(numero);
	cout << "El nombre factorial de: " << numero << " Es: " << resultat << endl;
}

int Nil(int Factorial) {

	int resultat = 1;
	for (int i = 1; i <= Factorial; ++i) {
		resultat *= i;
	}
	return resultat;
}