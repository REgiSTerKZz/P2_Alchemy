#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <vector>
#include "Header.h"


int main()
{
	std::unordered_map<std::pair<std::string, std::string>, std::string> mapa;
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


		mapa.insert({{ {key1 } , { key2 } }, { value }});
	}

	
	std::cout << std::endl;
	return 0;
}
