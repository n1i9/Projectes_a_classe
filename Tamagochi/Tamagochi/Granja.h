#pragma once
#include <iostream>
#include <vector>

class Granja
{
public:
	Granja() {} //Constructor de la granja
	void crearTamagochi(const string& nom); //Variable per a crear el tamagochi
	void llistarTamagochis() const; //Variable per a fer una llista dels tamagochis
	Varis& seleccionarTamagochi(int index); //Variable per a seleccionar els tamagochis
	int getNombreTamagochis() const; //Variable per a agafar i posar el nom dels tamagochis a les funcions de la granja
private:
	vector<Varis> tamagochis; //Vector dels tamagochis de varis
};