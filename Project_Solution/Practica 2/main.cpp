#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <vector>
#include "Header.h"
#include "PlayerElements.h"
#include <Windows.h>



std::unordered_map<std::pair<std::string, std::string>, std::string> readElemets(std::unordered_map<std::pair<std::string, std::string>, std::string> &A) {
	std::ifstream combinaciones("elements.dat");
	std::string line;

	while (!combinaciones.eof()) {								// Comprova que no hagi arribat al final de l'arxiu
		getline(combinaciones, line);							// Agafa la linea sencera fins al "\n"

		std::size_t equal = line.find("=");
		std::string value = line.substr(0, equal - 1);			// Crea un substring des del principi fins a l'=
		std::string keys = line.substr(equal + 1);				// String de les dues keys
		std::size_t plus = keys.find("+");
		std::string key1 = keys.substr(1, plus - 2);			// Separa les keys per el signe "+"
		std::string key2 = keys.substr(plus + 2);


		A.insert({ { { key1 } ,{ key2 } },{ value } });		// Omplo l'unordered_map
	}
	return A;
}


int main()
{
	bool EndGame = true;
	std::unordered_map<std::pair<std::string, std::string>, std::string> mapa;
	readElemets(mapa);
	PlayerElements Alchemy;
	Alchemy.Comandos();
	while (EndGame == true)
	{
		Alchemy.printElements();
		Alchemy.InputPlayer(mapa);
		Alchemy.getBool(EndGame);
	}

	std::cout << "   CONGRATULATIONS!" << std::endl;
	std::cout << "YOU FINISHED ALCHEMY!" << std::endl;
	Sleep(5000);
	return 0;
}