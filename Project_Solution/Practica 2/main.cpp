#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include "Header.h"
#include "PlayerElements.h"
#include <Windows.h>



std::unordered_map<std::pair<std::string, std::string>, std::string> readElemets(std::unordered_map<std::pair<std::string, std::string>, std::string> &A) {
	std::ifstream combinaciones("elements.dat");
	std::string line;															// Crea un string per guardar cada linea de l'arxiu elements.dat

	while (!combinaciones.eof()) {												// Comprova que no hagi arribat al final de l'arxiu
		getline(combinaciones, line);											// Agafa la linea sencera fins al "\n"

		std::size_t equal = line.find("=");
		std::string value = line.substr(0, equal - 1);							// Crea un substring des del principi fins a l'=
		std::string keys = line.substr(equal + 1);								// String de les dues keys
		std::size_t plus = keys.find("+");
		std::string key1 = keys.substr(1, plus - 2);							// Separa les keys per el signe "+"
		std::string key2 = keys.substr(plus + 2);


		A.insert({ { { key1 } ,{ key2 } },{ value } });							// Omplo l'unordered_map
	}
	return A;
}


int main()
{
	bool EndGame = true;														// Declara una variable bool per comprovar si el joc segueix funcionant
	std::unordered_map<std::pair<std::string, std::string>, std::string> mapa;	// Declara l'unordered_map que contindrà les possibles combinacions
	readElemets(mapa);															// Llegeix i inicialitza l'unordered_map amb els valors d'elements.dat
	PlayerElements Alchemy;														// Crea un objecte de la classe PlayerElements
	Alchemy.Comandos();															// Crida l'atribut de la classe Comandos(); per imprimir les instruccions
	while (EndGame == true)														// Comença el bucle per mantenir el joc funcionant
	{
		Alchemy.printElements();												// Crida la funció printElements de la classe PlayerElements
		Alchemy.InputPlayer(mapa);												// Crida la funció InputPLayer de la classe PlayerElements
		Alchemy.getBool(EndGame);												// Crida la funció getBool de la classe PlayerElements
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "       CONGRATULATIONS!" << std::endl;						// En cas que el jugador acabi el joc, printarà un missatge que feliciti al player
	std::cout << "    YOU FINISHED ALCHEMY!" << std::endl;
	Sleep(5000);
	return 0;
}