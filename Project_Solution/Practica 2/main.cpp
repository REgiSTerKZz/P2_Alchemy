#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include "Header.h"



int main()
{
	/*

	CODE INSTRUCCIONS
	--------------------------------------------------------------------------------------------------------------
	Llegeix una linea de l'arxiu elements.dat i ho passa a un string (line),
	Es passa l'String a un vector de chars per llegir char a char.
	Anem afegint els chars que llegeixi a un vector fins que arriba a un "=".
	si passa aixo, canviem el vector i ho repetin fins a un "+".
	El tercer vector arribara fins al "\n"
	
	Un cop tinguem els res vectors separats, eliminarem els espais en blanc,
	(un for del final cap al principi que elimini els espais propers als signes de split)
	un cop hageuem tret els espais passarem els vectors a strings;
	.........
	std::vector<char> v;
	std::string str(v.begin(),v.end());
	.........
	Quan ja tinguem els tres Strings els passarem a les posicions del unordered map per tal d'organitzarlos.
	--------------------------------------------------------------------------------------------------------------
	
	*/
	std::ifstream combinaciones("elements.dat", std::ios::in|std::ios::beg);
	std::string line;

	while (!combinaciones.eof()) {				// Comprova que no hagi arribat al final de l'arxiu

		getline(combinaciones, line);
		std::size_t equal = line.find("=");
		std::string value = line.substr(0, equal - 1);			// Crea un substring des del principi fins a l'=
		std::string keys = line.substr(equal + 1);			// String de les dues keys
		std::size_t plus = keys.find("+");
		std::string key1 = keys.substr(1, plus - 1);
		std::string key2 = keys.substr(plus + 2);


		std::cout << value << std::endl;
		std::cout << key1 << std::endl;
		std::cout << key2 << std::endl;
	
	}
	return 0;
}

std::string delUnnecessary(std::string &str)
{
	int size = str.length();
	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j <= j; i++)
		{
			if (str[i] == ' ' && str[j] != ' ') {
				str.erase(0, i);
			}
		}
	}
	return str;
}