#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <iterator>
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
	std::ifstream combinaciones("elements.dat");
	std::string line;

	while (!combinaciones.eof()) {				// Comprova que no hagi arribat al final de l'arxiu
	
		getline(combinaciones, line);
		std::size_t equal = line.find("=");
		std::string value = line.substr(0, equal);			// Crea un substring des del principi fins a l'=
		std::string keys = line.substr(equal + 1);			// String de les dues keys
		std::size_t plus = keys.find("+");
		std::string key1 = keys.substr(0, plus);
		std::string key2 = keys.substr(plus + 1);
		
		delUnnecessary(value);
		delUnnecessary(key1);
		delUnnecessary(key2);
		/*std::vector<char> buffval (value.begin(), value.end());	// Em passa el String a un vector de chars
		std::vector<char> buffkey1 (key1.begin(), key1.end());
		std::vector<char> buffkey2 (key2.begin(), key2.end());
		
		// Aixo passa el vector a string un altre cop
		std::string valu(buffval.begin(), buffval.end());
		std::cout << valu << std::endl;
		*/
		/*
		for (std::vector<char>::iterator it = buffer.begin(); it != buffer.end(); ++it) {		// iterador para cada elemento del vector

		}
		*/

	}
		/*
		
		if (line == "=" || line == "+")
			signo = true;

		if (c == 1 && signo == false) {
			value = line;
			c++;
			std::cout << value << std::endl;
		}
		else if (c == 2 && signo == false) {
			key1 = line;
			std::cout << key1 << std::endl;
			c++;
		}
		else if (c == 3 && signo == false) {
			key2 = line;
			std::cout << key2 << std::endl;
			c = 1;
		}
		signo = false;
		*/

	system("pause");

	return 0;
}



std::string delUnnecessary(std::string &str)
{
	int size = str.length();
	for (int j = 0; j <= size; j++)
	{
		for (int i = 0; i <= j; i++)
		{
			if (str[i] == ' ' && str[i + 1] == ' ')
			{
				str.erase(str.begin() + i);
			}
			else if (str[0] == ' ')
			{
				str.erase(str.begin());
			}
			else if (str[i] == '\0' && str[i - 1] == ' ')
			{
				str.erase(str.end() - 1);
			}
		}
	}
	return str;
}