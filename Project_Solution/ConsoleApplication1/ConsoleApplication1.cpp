#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>


int main()
{
	std::ifstream combinaciones("elements.dat");
	char line[250];
	int c = 1;
	std::string value;
	std::string key1;
	std::string key2;

	char control;
	while (!combinaciones.eof()) {
		
		combinaciones >> line;		
		
		if (c == 1) {
			value = line;
			c++;
		}
		else if (c == 2) {
			key1 = line;
			c++;
		}
		else if (c == 3) {
			key2 = line;
			c = 1;
		}
		else if (line == "=" || line == "+")
			c = c;
		std::cout << value << std::endl;
	}
	
	system("pause");

    return 0;
}

