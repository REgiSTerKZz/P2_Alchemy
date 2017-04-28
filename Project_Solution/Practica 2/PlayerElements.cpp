#include "PlayerElements.h"
#include <vector>
#include <iostream>
#include <string>


PlayerElements::PlayerElements()
{
	PlayerElements::elements = { {"Aire"}, {"Fuego"},{"Tierra"},{"Agua"} };
}

void PlayerElements::addElements(std::string A) {
	elements.insert(elements.end(), A);
}

void PlayerElements::printElements() {
	for (int i = 0; i <= elements.max_size(); i++) {
		std::cout << elements[i] << std::endl;
	}
}	

void PlayerElements::InputPlayer() {
	std::string str;
	std::cout << "Element : " << std::endl;
	getline(std::cin, str);
	for (auto it = elements.begin(); it != elements.end(); it++) {
		if (*it == str) {
			addElements(str);
		}
	}
}

PlayerElements::~PlayerElements()
{
}
