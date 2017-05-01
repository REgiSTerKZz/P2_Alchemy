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
	int a{ -1 };
	int b{ -1 };

	std::cin >> str;

	getline(std::cin, str2);
	std::size_t space = str2.find(" ");
	str2 = str2.substr(space + 1);

	bool elementos = false;
	
		
	
	 if (str[0] >= '0' && str[0] <= '9' && str2[0] >= '0' && str2[0] <= '9')
	{
		a = stoi(str);
		b = stoi(str);		
	}

		//SORT
		if (str == "sort" || str == "Sort") {
			sort(elements.begin(), elements.end());
			system("cls");
		}

		//CLEAN
		else if (str == "Clean" || str == "clean")
		{
			sort(elements.begin(), elements.end());
			elements.erase(unique(elements.begin(), elements.end()), elements.end());
			system("cls");
		}

		//ADD BASICS
		if (str == "Add" || str == "add" && str2 == "basics" || str2 == "Basics") 
		{			
				addElements("Aire");
				addElements("Fuego");
				addElements("Tierra");
				addElements("Agua");
				system("cls");
		}

		//ADD
		if (str == "Add" || str == "add")
		{
			b = stoi(str2);
			if (b > elements.size()) {
				std::cout << "You don't have this element in your own!" << std::endl;
				elementos = true;
			}
			else {
				b = stoi(str2);
				addElements(elements[b - 1]);
				system("cls");
			}
		}

		//DELETE
		else if (str == "delete" || str == "Delete") {
			b = stoi(str2);
			if (b > elements.size()) {
				std::cout << "You don't have this element in your own!" << std::endl;
				elementos = true;
			}

			else {
				elements.erase(elements.begin() + (b - 1));
				system("cls");
			}

		}

		//INFO
		else if (str == "info" || str == "Info") {
			b = stoi(str2);
			if (b > elements.size()) {
				std::cout << "You don't have this element in your own!" << std::endl;
				elementos = true;
			}
			else {
				std::string first = "https://es.wikipedia.org/wiki/";
				std::string second = elements[b - 1];
				std::string last = first + second;
				LPCSTR url = (LPCSTR)last.c_str();
				ShellExecuteA(nullptr, "open", url, nullptr, nullptr, SW_SHOWNORMAL);
				system("cls");
			}
		}

		

		else if (str == "Help" || str == "help")
			PlayerElements::Comandos();		

		

		/*else {
			std::cout << "introduce otro comando" << std::endl;
			elementos = true;
		}*/

	

		

		std::cin.clear();
	}




void PlayerElements::Comandos() {
	std::cout << "Escribe -Sort- para ordenar los elementos" << std::endl;
	std::cout << "Escribe -Clean- para eliminar los elementos repetidos" << std::endl;
	std::cout << "Escribe -Add- y un numero para agregar un elemento" << std::endl;
	std::cout << "Escribe -Add basics- para añadir los 4 elementos basicos" << std::endl;
	std::cout << "Escribe -Delete- y un numero para eliminar un elemento" << std::endl;
	std::cout << "Escribe -Info- para tener informacion de un elemento" << std::endl;
	std::cout << "Escribe -Help- para abrir este menú" << std::endl;
}

PlayerElements::~PlayerElements()
{
}
