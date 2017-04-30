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
	str2 = str2.substr(space + 1);
	int a = stoi(str2);

	//ADD
	if (str == "Add" || str == "add") {

		if (str2 == "basics" || str2=="Basics")
		{
			for (size_t i = 0; i < 4; i++)
			{
				addElements(elements[i]);
			}
		}
		else
		{
			addElements(elements[a-1]);
		}		
	}
	
	//DELETE
	else if (str == "delete" || str == "Delete") {
		if (a > elements.size()) {
			std::cout << "You don't have this element in your own!" << std::endl;
			
		}
		else {
			elements.erase(elements.begin() + (a - 1));
		}
	}
	
	//INFO
	else if (str == "info" || str == "Info") {
		if (a > elements.size()) {
			std::cout << "You don't have this element in your own!" << std::endl;
			
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
		
	}
	
	//CLEAN
	else if (str == "Clean" || str == "clean") {
		elements.erase(unique(elements.begin(), elements.end()), elements.end());
	}

	else if (str != "Add" && str != "add" && str != "delete" && str != "Delete" && str != "info" && str != "Info" && str != "sort" && str != "Sort" && str != "Clean" && str != "clean")
	{
		int numero = stoi(str);

		for (size_t i = 0; i < numero; i++)
		{
			str = elements[i];
			
		}
		std::cout << str << std::endl;
	}	
}	

PlayerElements::~PlayerElements()
{
}
