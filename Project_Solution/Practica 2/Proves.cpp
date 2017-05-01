#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <vector>
#include "Header.h"
#include <algorithm>
#include <Windows.h>

void addElements(std::string A, std::vector<std::string> Vec) {
	Vec.insert(Vec.end(), A);
}

int main()
{
	std::vector<std::string> elements { { "Air" },{ "Fire" },{ "Earth" },{ "Water" } };
	while (true)
	{
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
		else if (str == "Add" || str == "add" && str2 == "basics" || str2 == "Basics")
		{
			addElements("Air", elements);
			addElements("Fire", elements);
			addElements("Earth", elements);
			addElements("Water", elements);
			system("cls");
		}

		//ADD
		else if (str == "Add" || str == "add")
		{
			b = stoi(str2);
			if (b>elements.size())
				std::cout << "You don't have this element in your own!" << std::endl;
			else {
				b = stoi(str2);
				addElements(elements[b - 1]);
				system("cls");
			}
		}

		//DELETE
		else if (str == "delete" || str == "Delete") {
			b = stoi(str2);
			if (b > elements.size())
				std::cout << "You don't have this element in your own!" << std::endl;

			else {
				elements.erase(elements.begin() + (b - 1));
				system("cls");
			}

		}

		//INFO
		else if (str == "info" || str == "Info") {
			b = stoi(str2);
			if (b > elements.size()) {
				system("cls");
				std::cout << "You don't have this element in your own!" << std::endl;

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


		//HELP
		else if (str == "Help" || str == "help") {
			system("cls");
			//PlayerElements::Comandos();
		}


		if ((str[0] >= '0' && str[0] <= '9') && (str2[0] >= '0' && str2[0] <= '9'))
		{
			a = stoi(str);
			b = stoi(str);

			//COMBINATION
			for (auto it = A.begin(); it != A.end(); ++it) {
				if ((elements[a] == it->first.first && elements[b] == it->first.second) || (elements[b] == it->first.first && elements[a] == it->first.second)) {
					addElements(it->second);
				}
			}
			system("cls");
		}
		else {
			std::cout << "introduce otro comando" << std::endl;
		}

		std::cin.clear();
	}

	return 0;
}
