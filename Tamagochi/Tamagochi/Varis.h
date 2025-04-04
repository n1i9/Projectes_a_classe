#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Varis
{
public:
	void NomTamag(); //Funció del nom del tamagochi
	void Jugar(); //Funció de jugar
	void Nim(); //Joc del Nim
	void Endevinalles(); //Endevinalles
	void Jocmisterios(); //Joc misteriós
	void Factorial(); //Nombre factorial
	void Primer(); //Nombre primer
	void menjar(); //Donar de menjar al tamagochi
	void aigua(); //Aigua
	void parlar(); //Parlar amb el tamagochi
	void dormir(); //Enviar a dormir al tamagochi
	void musica(); //Posar-li música al tamagochi
	void stats(); //Veure les estadístiques
	void correctorstats(); //Variable que controla que les estadístiques no siguin inferiors a 0 i superiors a 10
	void minutsahores(); //Passa de minuts a hores
	void setNomTamag(string nom); //Estableix nom al tamagochi
	string getNomTamag() const; //Posa nom al gamagochi

	Varis(const string& nom) : nomTamag(nom) {} //Constructor del tamagochi
	Varis() : nomTamag("") {} //Constructor del nom del tamagochi

private:
	int gana = 5; //Gana per defecte
	int sed = 5; //Sed per defecte
	int aburriment = 5; //Aburriment per defecte
	int son = 5; //Son per defecte
	int anim = 5; //Ànims per defecte
	int hora = 0; //Variable d'hores
	double minut = 0; //Variable de minuts
	int dia = 0; //Variable per a contar dies
	int setmana = 0; //Variable per a contar setmanes
	int mes = 0; //Variable per a contar mesos
	string nomtamagochi = "Sense nom"; //Nom del tamagochi
	string nomTamag; //Estableix el nom al gamagochi
};