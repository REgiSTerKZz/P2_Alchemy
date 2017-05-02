#include "PlayerElements.h"
#include <iostream>
#include <Windows.h>
#include <algorithm>



PlayerElements::PlayerElements()
{
	elements = { { "Air" },{ "Fire" },{ "Earth" },{ "Water" } };
	Puntua = { { "Air" },{ "Fire" },{ "Earth" },{ "Water" } };
	puntuacion = 0;
}

void PlayerElements::addElements(std::vector<std::string> &Vec ,std::string A) {
	Vec.insert(Vec.end(), A);
	printElements();
}

void PlayerElements::printElements() {

	int i = 0;
	std::cout << "PUNTUACION: " << "!" << puntuacion << "!" << std::endl;
	for (auto it = elements.begin(); it != elements.end(); ++it) {		
		std::cout << i + 1 << "-";
		std::cout << elements[i] << std::endl;
		i++;
	}
}

void PlayerElements::InputPlayer(std::unordered_map<std::pair<std::string, std::string>, std::string> A) {
	std::string str, str2;
	int a{ -1 };
	int b{ -1 };
	std::cout << "Element : " << std::endl;
	std::cin >> str;

	getline(std::cin, str2);
	std::size_t space = str2.find(" ");
	str2 = str2.substr(space + 1);

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
	else if (str == "Add" || str == "add" && str2 == "basics" || str2 == "Basics" || str2 == "basics " || str2 == "Basics ")
	{
		addElements(elements, "Air");
		addElements(elements, "Fire");
		addElements(elements, "Earth");
		addElements(elements, "Water");
		system("cls");
	}

	//ADD
	else if (str == "Add" || str == "add")
	{
		if (str[0] >= '0' && str2[0] <= '9') {
			b = stoi(str2);
			if (b > elements.size()) {
				std::cout << "You don't have this element in your own!" << std::endl;
				Sleep(2000);
			}

			else {
				b = stoi(str2);
				addElements(elements, elements[b - 1]);
				system("cls");
			}
		}
		else {
			system("cls");
			std::cout << str2 << " is not a valid element" << std::endl;
			Sleep(2000);
			system("cls");
		}
	}

	//DELETE
	else if (str == "delete" || str == "Delete") {

		if (str[0] >= '0' && str2[0] <= '9') {
			b = stoi(str2);
			if (b > elements.size()) {
				std::cout << "You don't have this element in your own!" << std::endl;
				Sleep(2000);
			}
			else {
				elements.erase(elements.begin() + (b - 1));
				system("cls");
			}

		}
		else{
		system("cls");
		std::cout << str2 << " is not a valid element" << std::endl;
		Sleep(2000);
		system("cls");
		}
	}
	

	//INFO
	else if (str == "info" || str == "Info") {
		if (str[0] >= '0' && str2[0] <= '9') {
			b = stoi(str2);
			if (b > elements.size()) {
				system("cls");
				std::cout << "You don't have this element in your own!" << std::endl;
				Sleep(2000);
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
		else {
			system("cls");
			std::cout << str2 << " is not a valid element" << std::endl;
			Sleep(2000);
			system("cls");
		}
	}
	
	//HELP
	else if (str == "Help" || str == "help") {
		system("cls");
		PlayerElements::Comandos();
	}
	
	if ((str[0] >= '0' && str[0] <= '9') && (str2[0] >= '0' && str2[0] <= '9'))
	{
		a = stoi(str);
		b = stoi(str2);
		//COMBINATION
		if ((a != b) && ( a < elements.size()+1) && ( b < elements.size()+1) ) {
			for (auto it : A) {
				if ((elements[a - 1] == it.first.first) && (elements[b - 1] == it.first.second) || (elements[b - 1] == it.first.first) && (elements[a - 1] == it.first.second)) {
					elements.erase(elements.begin() + (a - 1));
					elements.erase(elements.begin() + (b - 2));
					addElements(elements, it.second);
					if (std::find(Puntua.begin(), Puntua.end(), it.second) != Puntua.end()) {
						
					}						
					else {
						addElements(Puntua, it.second);
						puntuacion++;
					}	
					break;
				}
			}
		}
		else if (a == b){
			system("cls");
			std::cout << "You can't combine the same element!" << std::endl;
			Sleep(2000);
			system("cls");
		}

		system("cls");
	}
	else {
		system("cls");
		std::cout << "Try another command!" << std::endl;
		Sleep(2000);
		system("cls");
	}
	std::cin.clear();
}

bool PlayerElements::getBool(bool &EndGame) {
	if (puntuacion < 390) {
		EndGame = true;
	}
	else
	{
		EndGame = false;
	}
	return EndGame;
}

void PlayerElements::Comandos() {
	std::cout << "------------------------------HELP-IN-COMING------------------------------ " << std::endl;
	std::cout << "  Escribe -Sort-	Para ordenar los elementos" << std::endl;
	std::cout << "  Escribe -Clean-	Para eliminar los elementos repetidos" << std::endl;
	std::cout << "  Escribe -Add-		Y un numero para agregar un elemento" << std::endl;
	std::cout << "  Escribe -Add basics-  Para añadir los 4 elementos basicos" << std::endl;
	std::cout << "  Escribe -Delete-	Y un numero para eliminar un elemento" << std::endl;
	std::cout << "  Escribe -Info-	Para tener informacion de un elemento" << std::endl;
	std::cout << "  Escribe -Help-	Para abrir este menu" << std::endl;
	std::cout << "-------------------------------------------------------------------------- " << std::endl;
	std::cout << std::endl;
}

PlayerElements::~PlayerElements()
{
}