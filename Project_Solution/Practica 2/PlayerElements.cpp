#include "PlayerElements.h"
#include <iostream>
#include <Windows.h>
#include <algorithm>



PlayerElements::PlayerElements()
{
	elements = { { "Air" },{ "Fire" },{ "Earth" },{ "Water" } };									// Inicialitza el vector elements amb els quatre elements bàsics
	Puntua = { { "Air" },{ "Fire" },{ "Earth" },{ "Water" } };										// Inicialitza el vector elements amb els quatre elements bàsics
	puntuacion = 0;																					// Inicialitza la variable puntuació a 0
}

void PlayerElements::addElements(std::vector<std::string> &Vec ,std::string A) {					//Creem un atribut per afegir elements dins del vector
	Vec.insert(Vec.end(), A);																		//Inserta l'element 
	printElements();																				//Printa els elements
}

void PlayerElements::printElements() {//Creem un atribut per printar els elements del vector

	int i = 0;																						//Declara una variable que utilitzarem per posar els numeros dels elements
	std::cout << "PUNTUACION: " << "!" << puntuacion << "!" << std::endl;							//Imprimeix la puntuació
	for (auto it = elements.begin(); it != elements.end(); ++it) {									//Printa el elements dels vector amb el seu numero	
		std::cout << i + 1 << "-";
		std::cout << elements[i] << std::endl;
		i++;
	}
}

void PlayerElements::InputPlayer(std::unordered_map<std::pair<std::string, std::string>, std::string> A) { //Llegeix el que posa l'usuari 
	std::string str, str2;	//Fem 2 strings el primer sera fins el espai i el segon per el text després de l'espai
	int a;
	int b;
	std::cout << "Element : " << std::endl;
	std::cin >> str; //Guarda tot al primer string

	getline(std::cin, str2);																		//treu del primer string el que hi ha des del primer espai fins al final 
	std::size_t space = str2.find(" ");																//busca l'espai
	str2 = str2.substr(space + 1);																	//treu l'espai

	//SORT																							//Comprova que el str sigui igual a "Sort"
	if (str == "sort" || str == "Sort") {
		sort(elements.begin(), elements.end());														//utilitzem la funció membre "Sort" de vector
		system("cls");
	}

	//CLEAN
	else if (str == "Clean" || str == "clean")														//Comprova que el str sigui igual a "Clean"
	{
		sort(elements.begin(), elements.end());														//utilitzem la funció membre "Sort" per ordenar i evitar un bucle que compari cada element amb la resta
		elements.erase(unique(elements.begin(), elements.end()), elements.end());					//utilitzem la funció membre "unique y erase" per eliminar els elements repetits del vector
		system("cls");
	}

	//ADD BASICS
	else if (str == "Add" || str == "add" && str2 == "basics" || str2 == "Basics")					//Comprova que el str sigui igual a "Add" i str2 sigui igual a "Basics"
	{
		addElements(elements, "Air");																//Afageix els 4 elements basics
		addElements(elements, "Fire");
		addElements(elements, "Earth");
		addElements(elements, "Water");
		system("cls");
	}

	//ADD
	else if (str == "Add" || str == "add")															//Comprova que el str sigui igual a "Add"
	{
		if (str2[0] >= '0' && str2[0] <= '9') {														//Si str2 es un numero fa un cast i podem trballar amb el numero posat
			b = stoi(str2);														
			if (b > elements.size()) {																//Si str2 es mes gran que el vector, imprimeix un missatge
				std::cout << "You don't have this element in your own!" << std::endl;
				Sleep(2000);
			}

			else {																					//Si b esta dins del vector afegeix l'element
				b = stoi(str2);
				addElements(elements, elements[b - 1]);
				system("cls");
			}
		}
		else {																						//Si str2 no es un numero imprimeix un missatge
			system("cls");
			std::cout << str2 << " is not a valid element" << std::endl;
			Sleep(2000);
			system("cls");
		}
	}

	//DELETE
	else if (str == "delete" || str == "Delete") {													//Comprova que el str sigui igual a "Delete"

		if (str2[0] >= '0' && str2[0] <= '9') {														//Si str2 es un numero fa un cast i podem trballar amb el numero posat
			b = stoi(str2);
			if (b > elements.size()) {																//Si str2 es mes gran que el vector, imprimeix un missatge
				std::cout << "You don't have this element in your own!" << std::endl;
				Sleep(2000);
			}
			else {																					//Si b esta dins del vector elimina l'element
				elements.erase(elements.begin() + (b - 1));
				system("cls");
			}

		}
		else{																						//Si str2 no es un numero imprimeix un missatge	
		system("cls");
		std::cout << str2 << " is not a valid element" << std::endl;
		Sleep(2000);
		system("cls");
		}
	}
	

	//INFO
	else if (str == "info" || str == "Info") {												// Comprova que el str sigui igual a "Info"
		if (str2[0] >= '0' && str2[0] <= '9') {												// en el cas que el segon element (str2) sigui igual a un nombre(int)
			b = stoi(str2);																	// Passa str2 de string a int i ho guarda a la variable b
			if (b > elements.size()) {														// Si b és més gran que la mida del vector
				system("cls");
				std::cout << "You don't have this element in your own!" << std::endl;		// Sortirà un missatge que no hi ha l'element que el player ha demanat
				Sleep(2000);
			}
			else {																			// Si b està dins dels valors del vector, 
				std::string first = "https://es.wikipedia.org/wiki/";						// Inicialitza un string amb la primera part de la url de la wikipedia
				std::string second = elements[b - 1];										// Inicialitza un altre string amb la segona part del link ( l'element que el jugador ha demanat )
				std::string last = first + second;											// Amb l'operador '+' ajuntem els dos strings en un per tal de tenir l'URL complet
				LPCSTR url = (LPCSTR)last.c_str();											// Fa un cast de string a LPCSTR
				ShellExecuteA(nullptr, "open", url, nullptr, nullptr, SW_SHOWNORMAL);		// Crida la funció ShellExecuteA();
				system("cls");
			}
		}
		else {																				// EN el cas que srt2 no sigui un nombre(int)
			system("cls");	
			std::cout << str2 << " is not a valid element" << std::endl;					// Printa un missatge avisan-te que l'element que has introduït no és vàlid
			Sleep(2000);
			system("cls");
		}
	}
	
	//HELP
	else if (str == "Help" || str == "help") {												// Comprova que el str sigui igual a "Help"
		system("cls");
		Comandos();																			//Crida l'atribut "Comandos"
	}
	
	else if ((str[0] >= '0' && str[0] <= '9') && (str2[0] >= '0' && str2[0] <= '9'))		//Si no es cap de les anterior y el primer element dels 2 strings es un numero fa un cast
	{
		a = stoi(str);																		//pasa str i str2 a numero
		b = stoi(str2);
		//COMBINATION
		if ((a != b) && ( a < elements.size()+1) && ( b < elements.size()+1) ) {			//Si a es diferent de b i son mes petits de la mida del vector entra
			for (auto it : A) {																//Bucle que va incrementant "it"
				if ((elements[a - 1] == it.first.first) && (elements[b - 1] == it.first.second) ||
					(elements[b - 1] == it.first.first) && (elements[a - 1] == it.first.second)) {//Si "a i b" o "b i a" son la key d'un element del mapa entra al if
					elements.erase(elements.begin() + (a - 1));								//elimina a del vector
					elements.erase(elements.begin() + (b - 2));								//elimina b del vector
					addElements(elements, it.second);										//posa l'element de la posicion on "a i b" o "b i a" coincideixen
					if (std::find(Puntua.begin(), Puntua.end(), it.second) != Puntua.end()) {//Busca si l'element creat esta en el vector puntua
						
					}						
					else {
						addElements(Puntua, it.second);										 //Si no esta, suma 1 a la puntuació
						puntuacion++;
					}	
					break;
				}
			}
		}
		else if (a == b){																	  //Si a es igual a b no et deixa fer la combinació
			system("cls");
			std::cout << "You can't combine the same element!" << std::endl;
			Sleep(2000);
			system("cls");
		}

		system("cls");
	}
	
	else																					  //Si no entra al primer if imprimeix el missatge
	{
		system("cls");
		std::cout << "Try another command" << std::endl;
		Sleep(2000);
		system("cls");
	}

	std::cin.clear();
}

bool PlayerElements::getBool(bool &EndGame) {												  //Fem un bool per a la puntuació
	if (puntuacion < 390) {
		EndGame = true;
	}
	else																					  //El joc acaba quan es igual a 390 combinacions
	{
		EndGame = false;
	}
	return EndGame;
}

void PlayerElements::Comandos() {																//Atribut que imprimeix el missatges
	std::cout << "------------------------------HELP-IN-COMING------------------------------ " << std::endl;
	std::cout << "  Escribe -Sort-	Para ordenar los elementos" << std::endl;
	std::cout << "  Escribe -Clean-	Para eliminar los elementos repetidos" << std::endl;
	std::cout << "  Escribe -Add-		Y un numero para agregar un elemento" << std::endl;
	std::cout << "  Escribe -Add basics-  Para añadir los 4 elementos basicos" << std::endl;
	std::cout << "  Escribe -Delete-	Y un numero para eliminar un elemento" << std::endl;
	std::cout << "  Escribe -Info-	Para tener informacion de un elemento" << std::endl;
	std::cout << "  Escribe -Help-	Para abrir este menu" << std::endl;
	std::cout << "-------------------------------------------------------------------------- " << std::endl;
	std::cout << std::endl;
}

PlayerElements::~PlayerElements()																//Destructor
{
}