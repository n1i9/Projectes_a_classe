#include "Varis.h" //Arxiu .h on hi ha la classe varis
#include "Granja.h" //Arxiu .h on hi ha la classe granja
#include <iostream>

using namespace std;

int main() { //Funci� main
	Granja granja; //Crea l'objecte granja de la classe que tinc que �s granja
	bool jugar = true; //Variable booleana per a jugar

	while (jugar) { //Bucle que indica a l'usuari les opcions principals de crear o seleccionar un critter
	cout << "Benvingut a la granja de tamagochis!" << endl; //Dona la benvinguda a l'usuari
	cout << "Quina accio vols fer?" << endl; //Pregunta a l'usuari quina acci� vol fer
	cout << "1.Crear un nou tamagochi" << endl; //Crea un nou tamagochi
	cout << "2.Seleccionar un tamagochi" << endl; //Selecciona un tamagochi ja existent
	cout << "3.Sortir" << endl; //Sortir del programa directament
	int opcio1; //Creo opci� 1 que serveix per recollir que ha seleccionat l'usuari
	cin >> opcio1; //L'usuari tria que vol fer
	
	switch (opcio1) { //Switch d'opcions principals
	case 1: { //Opci� 1 la qual serveix per a crear un nou tamagochi
		cout << "Posa el nom del tamagochi: " << endl; //Demana a l'usuari un nom al tamagochi nou
		string nom; //Creo la variable nom amb string
		cin >> nom; //L'usuari posa el nom del tamagochi
		granja.crearTamagochi(nom); //Es crida la funci� de crear un tamagochi amb el nom que ha escollit l'usuari
		break; //Es trenca el bucle i per tant, torna a la llista d'opcions anteriors
	}
	case 2: //Opci� 2 la qual serveix per a seleccionar quin tamagochi vol l'usuari
		granja.llistarTamagochis(); //Es crida la funci� de llistar els tamagochis existents
		if (granja.getNombreTamagochis() == 0) { //Si no hi ha cap tamagochi creat
			cout << "Encara no hi ha tamagochis a la granja." << endl; //Indica que no hi ha tamagochis creats de moment a la granja
			break;
		}
		cout << "Selecciona el tamagochi pel seu numero: " << endl; //Demana a l'usuari quin tamagochi vol fer servir
		int seleccio; //Creo la variable de selecci� per a que l'usuari trii quin tamagochi vol
		cin >> seleccio; //L'usuari introdueix el n�mero de tamagochi que vol fer servir
		try { //Bucle per a les accions que far� l'usuari amb el tamagochi
			Varis& tamagochiSeleccionat = granja.seleccionarTamagochi(seleccio); //S'agafa el tamagochi seleccionat per l'usuari
			cout << "Has seleccionat el tamagochi: " << tamagochiSeleccionat.getNomTamag() << endl; //S'indica el tamagochi seleccionat

			bool interactuar = true; //Variable per a activar el while d'accions a fer amb el tamagochi
			while (interactuar) { //Llista d'opcions per a fer amb el tamagochi
				cout << "***************************************" << endl;
				cout << "Tria l'accio que vols fer al tamagochi:" << endl; //Demana a l'usuari quina acci� vol fer amb l'usuari
				cout << "Opcio 1: Donar-li menjar" << endl; //Opci� 1 Menjar
				cout << "Opcio 2: Donar-li aigua" << endl; //Opci� 2 Aigua
				cout << "Opcio 3: Jugar amb el tamagochi" << endl; //Opci� 3 Jugar
				cout << "Opcio 4: Parlar amb el tamagochi" << endl; //Opci� 4 Parlar
				cout << "Opcio 5: Enviar a dormir el tamagochi" << endl; //Opci� 5 Dormir
				cout << "Opcio 6: Posar-li musica al tamagochi" << endl; //Opci� 6 M�sica
				cout << "Opcio 7: Consultar les estadistiques" << endl; //Opci� 7 Estad�stiques
				cout << "Opcio 8: Tancar el tamagochi" << endl; //Opci� 8 Tancar el tamagochi
				int accio; //Variable per a recollir l'elecci� de l'usuari
				cin >> accio; //L'usuari introdueix l'acci� que vol fer amb el tamagochi
				cout << "***************************************" << endl;
				switch (accio) { //Switch on s'executa l'acci� que ha triat l'usuari
				case 1:
					tamagochiSeleccionat.menjar(); //Crida la funci� de menjar amb el tamagochi seleccionat
					break;
				case 2:
					tamagochiSeleccionat.aigua(); //Crida la funci� de beure aigua amb el tamagochi seleccionat
					break;
				case 3:
					tamagochiSeleccionat.Jugar(); //Crida la funci� de jugar amb el tamagochi seleccionat
					break;
				case 4:
					tamagochiSeleccionat.parlar(); //Crida la funci� de parlar amb el tamagochi seleccionat
					break;
				case 5:
					tamagochiSeleccionat.dormir(); //Crida la funci� de dormir amb el tamagochi seleccionat
					break;
				case 6:
					tamagochiSeleccionat.musica(); //Crida la funci� de m�sica amb el tamagochi seleccionat
					break;
				case 7:
					tamagochiSeleccionat.stats(); //Crida la funci� de veure les estad�stiques del tamagochi seleccionat
					break;
				case 8:
					interactuar = false; //Tancar la llista d'accions
					break;
				}
			}
		}
		catch (const out_of_range& e) { //Si no s'ha pogut fer el try per algun error
			cout << "Ha donat error: " << e.what() << endl; //Indica que ha donat error
		}
		break;
	case 3:
		cout << "Tancant el tamagochi... Fins aviat!" << endl; //Tanca el tamagochi directament �s a dir el programa
		jugar = false; //Tanca el programa
		break;
	}
}
	return 0;
}