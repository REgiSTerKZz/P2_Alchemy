#include "PlayerElements.h"
#include <vector>
#include <iostream>
#include <string>


PlayerElements::PlayerElements()
{
	PlayerElements::elements = { {"Aire"}, {"Fuego"},{"Tierra"},{"Agua"} };
	puntuacion = 0;
}

void PlayerElements::addElements(std::string A) {
	elements.insert(elements.end(), A);
}

void PlayerElements::printElements() {
	int c = 1;
	int i = 0;
	for (auto it = elements.begin(); it != elements.end(); ++it) {		// Imprimeix (per poder comprovar)
		std::cout << c << "-";
		std::cout << elements[i]<<std::endl;
		c++;
		i++;
	}
}	

void PlayerElements::InputPlayer() {
	std::string str;
	std::cout << "Element : " << std::endl;
	

	while (puntuacion<390) {
		getline(std::cin, str);

		if()
		

		if (str == "delete")
			elements.pop_back();

		system("cls");
		printElements();
	}	
}

PlayerElements::~PlayerElements()
{
}
