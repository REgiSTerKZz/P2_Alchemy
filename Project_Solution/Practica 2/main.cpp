#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <iterator>


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
	std::string value;
	std::string key1;
	std::string key2;
	bool signo = false;
	std::vector<char> val;

	while (!combinaciones.eof()) {				// Comprova que no hagi arribat al final de l'arxiu
	
		getline(combinaciones, line);
		std::vector<char> buffer(line.begin(), line.end());	// Em passa el String a un vector de chars
		for (std::string::iterator it = line.begin(); it != line.end(); ++it) {
			do {										//esto de aqui no funciona, hay que hacer el for para que leea char por char y que controle si es un = o no
				val.push_back(*it);
			} while (*it != '=');
			std::string valu(val.begin(), val.end());
			std::cout << valu << std::endl;
		}
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
