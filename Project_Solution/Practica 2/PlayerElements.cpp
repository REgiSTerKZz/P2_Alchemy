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
	int a = -1;
	int b = -1;
	std::cout << "Element : " << std::endl;

	std::cin >> str;
	if (str == "clean" || str == "sort") {
		//SORT
		if (str == "sort" || str == "Sort") {
			sort(elements.begin(), elements.end());
		}

		//CLEAN
		if (str == "Clean" || str == "clean") {
			elements.erase(unique(elements.begin(), elements.end()), elements.end());
		}
	}
	else {
		getline(std::cin, str2);
		std::size_t space = str2.find(" ");
		str2 = str2.substr(space + 1);

		if (str != "add" && str != "delete" && str != "info" && str != "sort" && str != "clean") {
			a = std::stoi(str);
		}
		if (str2 != "basics") {
			b = std::stoi(str2);
		}
		//ADD
		if (str == "Add" || str == "add") {

			if (str2 == "basics" || str2 == "Basics")
			{
				for (size_t i = 0; i < 4; i++)
				{
					addElements(elements[i]);
				}
			}
			else
			{
				addElements(elements[b - 1]);
			}
		}

		//DELETE
		else if (str == "delete" || str == "Delete") {
			if (b > elements.size()) {
				std::cout << "You don't have this element in your own!" << std::endl;

			}
			else {
				elements.erase(elements.begin() + (b - 1));
			}
		}

		//INFO
		else if (str == "info" || str == "Info") {
			if (b > elements.size()) {
				std::cout << "You don't have this element in your own!" << std::endl;
			}
			else {
				std::string first = "https://es.wikipedia.org/wiki/";
				std::string second = elements[b - 1];
				std::string last = first + second;
				LPCSTR url = (LPCSTR)last.c_str();
				ShellExecuteA(nullptr, "open", url, nullptr, nullptr, SW_SHOWNORMAL);
			}
		}
	}
}	

PlayerElements::~PlayerElements()
{
}
