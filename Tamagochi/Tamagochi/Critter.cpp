#include "Varis.h"
#include "Granja.h"
#include <iostream>

using namespace std;

void Varis::NomTamag() {
	cout << "Introdueix el nom que li vols posar al tamagochi" << endl;
	cin >> nomtamagochi;
	cout << "Una nova criatura ha nascut, ha nascut: " << nomtamagochi << endl;
}
void Varis::Jugar() {
    aburriment -= 4;
    gana += 2;
    son += 2;
    anim += 3;
    hora += 1;
    correctorstats();
    int Joc;
	cout << "Quin joc vols jugar? tria el joc per a jugar:" << endl;
	cout << "1. Nim" << endl;
	cout << "2. Endevinalles" << endl;
    cout << "3. Encertar el numero misterios" << endl;
	cout << "4. Joc de calcul: Nombre factorial" << endl;
	cout << "5. Joc de calcul: Nombre primer" << endl;
    cin >> Joc;
    switch (Joc) {
    case 1:
        Nim();
        break;
    case 2:
        Endevinalles();
        break;
    case 3:
        Jocmisterios();
        break;
    case 4:
        Factorial();
        break;
    case 5:
        Primer();
        break;
    }
}
void Varis::Nim() {
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
}
void Varis::Endevinalles(){
    cout << "1. No es bou i porta banyes, no es paraigua i surt quan plou." << endl;
    cout << "2. Te braços coll i punys, i no té mans, cap ni ulls." << endl;
    cout << "3. Una tallada de melo de nit s'hi fa veure i de dia no." << endl;
    cout << "Vols saber les respostes?" << endl;
    string saberresposta;
    cin >> saberresposta;
    if (saberresposta == "si" || saberresposta == "Si") {
        cout << "1. El cargol" << endl;
        cout << "2. La camisa" << endl;
        cout << "3. La lluna" << endl;
    }
    else {
        cout << "Entesos, entenc que ja saps les respostes" << endl;
    }
}
void Varis::Jocmisterios(){
    int numerocorrecte; int resposta; int intents = 0; bool continuar = true; srand(time(0)); //Definició de variables
    numerocorrecte = 0 + rand() % 100; //Generació d'un número random
    cout << "Benvingut al joc d'adivinar el numero\n"; //Dona la benvinguda a l'usuari
    while (continuar == true) { //Bucle while que si no s'ha encertat el número encara, s'executa
        cout << "Introdueix un numero:\n"; //Demana un número a l'usuari
        cin >> resposta; //L'usuari introdueix la resposta
        ++intents; //Es suma 1 intent a cada número que dona l'usuari
        if (resposta > numerocorrecte) { cout << "Mes baix!"; } // Si el número de l'usuari es menys, diu que el número és més baix
        else if (resposta < numerocorrecte) { cout << "Mes alt!"; } //Si el número es més alt, ho indica a l'usuari
        else if (resposta == numerocorrecte) {
            cout << "Has edivinat el numero!\n" << "Has necessitat: " << intents << " Intents";
            continuar = false;
        } //Si la resposta es correcte, indica el numero d'intents. També para el bucle
    }

}
void Varis::Factorial() {
    int numero;
    cout << "Calculadora de nombre factorial, introdueix un nombre" << endl;
    cin >> numero;
    int resultat = 1;

    for (int i = 1; i <= numero; ++i) {
        resultat *= i;
    }
    cout << "El nombre factorial de: " << numero << " Es: " << resultat << endl;
    }
void Varis::Primer(){
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

}
void Varis::menjar() {
    cout << "Que li vols donar de menjar al " << nomtamagochi << " ?" << endl;
    cout << "1. Un platan" << endl;
    cout << "2. Una pastanaga" << endl;
    cout << "3. Un plat d'spaguettis" << endl;
    cout << "4. Un pastis" << endl;
    cout << "5. Un bistec" << endl;
    cout << "6. Una pizza" << endl;
    cout << "7. Una hamburguesa" << endl;
    int triarmenjar;
    cin >> triarmenjar;
    switch (triarmenjar) {
    case 1:
        cout << "Has alimentat al " << nomtamagochi << " amb un platan" << endl;
        gana -= 1.5;
        son += 2;
        sed += 3;
        anim += 1.5;
        minut += 15;
        correctorstats();
        break;
    case 2:
        cout << "Has alimentat al " << nomtamagochi << " amb una pastanaga" << endl;
        gana -= 1.2;
        son += 2;
        sed += 3;
        anim += 1.5;
        minut += 15;
        correctorstats();
        break;
    case 3:
        cout << "Has alimentat al " << nomtamagochi << " amb un plat d'spaguettis" << endl;
        gana -= 3;
        son += 2;
        sed += 3;
        anim += 1.5;
        minut += 30;
        correctorstats();
        break;
    case 4:
        cout << "Has alimentat al " << nomtamagochi << " amb un pastis" << endl;
        gana -= 2;
        son += 2;
        sed += 3;
        anim += 1.5;
        minut += 15;
        correctorstats();
        break;
    case 5:
        cout << "Has alimentat al " << nomtamagochi << " amb un bistec" << endl;
        gana -= 4;
        son += 2;
        sed += 3;
        anim += 1.5;
        minut += 45;
        correctorstats();
        break;
    case 6:
        cout << "Has alimentat al " << nomtamagochi << " amb una pizza" << endl;
        gana -= 4.5;
        son += 2;
        sed += 3;
        anim += 2;
        hora += 1;
        correctorstats();
        break;
    case 7:
        cout << "Has alimentat al " << nomtamagochi << " amb una hamburguesa" << endl;
        gana -= 3.5;
        son += 2;
        sed += 3;
        anim += 1.5;
        hora += 1;
        correctorstats();
        break;
    }
}
void Varis::aigua() {
    cout << "Li has donat aigua al " << nomtamagochi << endl;
    sed -= 2;
    gana += 2;
    aburriment += 2;
    minut += 5;
    correctorstats();
}
void Varis::parlar() {
    cout << nomtamagochi << ": Sabies que hi ha 8 planetes en el sistema solar? La terra es situa en el planeta numero 3 partint des del sol" << endl;
    cout << nomtamagochi << ": Sabies que el cotxe mes car del mon es va vendre per $143M ? Aquest cotxe era un Mercedes-Benz 300 SLR Uhlenhaut Coupe de l'any 1955" << endl;
    cout << nomtamagochi << ": El meu menjar preferit es la pizza, m'encanta" << endl;
    cout << nomtamagochi << ": M'agrada la tecnologia i els videojocs, el meu videojoc preferit es el GTA V!" << endl;
    cout << nomtamagochi << ": Gracies per escoltar-me" << endl;
    aburriment -= 3;
    sed += 2;
    anim += 2;
    hora += 1;
    correctorstats();
}
void Varis::dormir() {
    cout << nomtamagochi << " ha anat a dormir..." << endl;
    cout << nomtamagochi << " ja s'ha despertat" << endl;
    son -= 3.5;
    gana += 1.5;
    anim -= 2.5;
    hora += 8;
    correctorstats();
}
void Varis::musica() {
    cout << nomtamagochi << " ha escoltat musica i li ha agradat molt!" << endl;
    aburriment -= 3;
    son += 2;
    sed += 2;
    hora += 1;
    correctorstats();
}
void Varis::stats() {
    minutsahores();
    cout << "Les meves estadistiques son:" << endl;
    cout << "Gana: " << gana << endl;
    cout << "Set: " << sed << endl;
    cout << "Aburriment: " << aburriment << endl;
    cout << "Son: " << son << endl;
    cout << "Estat d'anim: " << anim << endl;
    cout << "Ha passat " << minut << " minuts, " << hora << " hores, " << dia << " dies, " << setmana << " setmanes, " << mes << " mesos des de que " << nomtamagochi << " ha nascut" << endl;
}
void Varis::correctorstats() {
    if (gana > 10) { gana = 10; }
    else if (gana < 0) { gana = 0; }
   
    if (sed > 10) { sed = 10; }
    else if (sed < 0) { sed = 0; }
    
    if (aburriment > 10) { aburriment = 10; }
    else if (aburriment < 0) { aburriment = 0; }
    
    if (son > 10) { son = 10; }
    else if (son < 0) { son = 0; }

    if (anim > 10) { anim = 10; }
    else if (anim < 0) { anim = 0; }
}
void Varis::minutsahores() {
    while (minut >= 60) {
        if (minut >= 60) {
            minut -= 60;
            hora += 1;
        }
    }
    while (hora >= 24) {
        if (hora >= 24) {
            hora -= 24;
            dia += 1;
        }
    }
    while (dia >= 7) {
        if (dia >= 7) {
            dia -= 7;
            setmana += 1;
        }
    }
    while (setmana >= 4) {
        if (setmana >= 4) {
            setmana -= 4;
            mes += 1;
        }
    }
}
void Varis::setNomTamag(string nom) {
    nomtamagochi = nom;
}
string Varis::getNomTamag() const {
    return nomtamagochi;
}
void Granja::crearTamagochi(const string& nom) {
    Varis nouTamagochi;
    nouTamagochi.setNomTamag(nom);
    tamagochis.push_back(nouTamagochi);
    cout << "Tamagochi " << nom << " creat i afegit a la granja!" << endl;
}
void Granja::llistarTamagochis() const {
    if (tamagochis.empty()) {
        cout << "Encara no hi ha tamagochis a la granja." << endl;
        return;
    }
    cout << "Llista de tamagochis disponibles:" << endl;
    for (size_t i = 0; i < tamagochis.size(); ++i) {
        cout << i + 1 << ". " << tamagochis[i].getNomTamag() << endl;
    }
}
Varis& Granja::seleccionarTamagochi(int index) {
    if (index < 1 || index > tamagochis.size()) {
        throw std::out_of_range("Index fora de rang!");
    }
    return tamagochis[index - 1];
}
int Granja::getNombreTamagochis() const {
    return tamagochis.size();
}