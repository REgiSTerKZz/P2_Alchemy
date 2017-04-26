#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>


int main()
{
	std::ifstream combinaciones("elements.dat");
	std::string line;
	int c = 1;
	std::string value;
	std::string key1;
	std::string key2;

	bool signo=false;

	while (!combinaciones.eof()) {
		
		combinaciones >> line;		
		
		if (line == "=" || line =="+")
			signo = true;

		if (c == 1 && signo==false) {
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
		
		
	}
	
	system("pause");

    return 0;
}

