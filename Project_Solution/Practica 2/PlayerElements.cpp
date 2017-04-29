#include "PlayerElements.h"
#include <vector>
#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>

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

	std::string str, str2;
	std::cout << "Element : " << std::endl;

	std::cin >> str;
	getline(std::cin, str2);

	std::size_t space = str2.find(" ");	 
	int a = std::stoi(str2.substr(space + 1));



	//ADD
	if (str == "Add" || str == "add") {
		if (a > elements.size()) {	
			std::cout << "You don't have this element in your own!" << std::endl;
			InputPlayer();			
		}
		else
		{
			addElements(elements[a - 1]);
		}
	}
	
	//DELETE
	else if (str == "delete" || str == "Delete") {
		if (a > elements.size()) {
			std::cout << "You don't have this element in your own!" << std::endl;
			InputPlayer();
		}
		else {
			elements.erase(elements.begin() + (a - 1));
		}
	}
	
	//INFO
	else if (str == "info" || str == "Info") {
		if (a > elements.size()) {
			std::cout << "You don't have this element in your own!" << std::endl;
			InputPlayer();
		}
		else {
			std::string first = "https://es.wikipedia.org/wiki/";
			std::string second = elements[a-1];
			std::string last = first + second;
			LPCSTR url = (LPCSTR)last.c_str();
			ShellExecuteA(nullptr, "open", url, nullptr, nullptr, SW_SHOWNORMAL);
		}
	}			

	//SORT
	else if (str == "sort" || str == "Sort" ) {
		sort(elements.begin(), elements.end());
		printElements();
	}
	
	//CLEAR
	else if (str == "Clear" || str == "clear") {
		elements.erase(unique(elements.begin(), elements.end()), elements.end());
		printElements();
	}
	
	std::cin.clear();
	}	

PlayerElements::~PlayerElements()
{
}
