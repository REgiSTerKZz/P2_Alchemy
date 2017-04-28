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
	printElements();
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
	std::string str2;
	std::cout << "Element : " << std::endl;

	std::cin >> str;
	getline(std::cin, str2);

	std::size_t space = str2.find(" ");	 
	int a = std::stoi(str2.substr(space + 1));

	

	if (str == "Add" || str == "add") {
		if () {

		}
		addElements(elements[a-1]);	
	}
	
	if (str == "delete")
		elements.pop_back();		
	
	std::cin.clear();
	}	

PlayerElements::~PlayerElements()
{
}
