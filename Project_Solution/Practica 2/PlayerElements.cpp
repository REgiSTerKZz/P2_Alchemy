#include "PlayerElements.h"
#include <iostream>
#include <Windows.h>
#include <algorithm>



PlayerElements::PlayerElements() //Inicializamos los valores de elements y la puntuacion
{
	PlayerElements::elements = { {"Air"}, {"Fire"},{"Earth"},{"Water"} };
	puntuacion = 0;
}

void PlayerElements::addElements(std::string A) { //Creamos un atributo que nos ayudara a insertar nuevos elementos cuando lo necesitemos
	elements.insert(elements.end(), A);
	printElements();
}

void PlayerElements::printElements() {//Creamos otro atributo que nos imprimira lo que contiene nuestro vector

	int i = 0;
	std::cout << "PUNTUACION: " <<"!" << puntuacion<< "!" << std::endl;
	for (auto it = elements.begin(); it != elements.end(); ++it) {		// Imprimeix (per poder comprovar)
		std::cout << i+1 << "-";
		std::cout << elements[i]<<std::endl;
		i++;
	}
}	

void PlayerElements::InputPlayer(std::unordered_map<std::pair<std::string, std::string>, std::string> A) {
	std::string str, str2;
	//Desde aqui gestionamos todos los comandos que recibamos por consola

	int a{ -1 };
	int b{ -1 };
	std::cout << "Element : " << std::endl;
	std::cin >> str;//guardamos toda la linea en el primer string

	getline(std::cin, str2);//la segunda parte del primer string la guardamos en el segundo
	std::size_t space = str2.find(" ");//buscamos el espacio
	str2 = str2.substr(space + 1);//y lo extraemos para trabajar mejor
		

		//SORT-Nos aprovechamos de las funciones miembro
		//cuando el usuario nos ponga el comando sort
		//utilizaremos la funcion miembro del mismo nombre
		if (str == "sort" || str == "Sort") {
			sort(elements.begin(), elements.end());
			system("cls");//limpia la pantalla
			printElements();//printa la lista modificada
		}

		//CLEAN-Nos aprovechamos de las funciones miembro
		//cuando el usuario nos ponga el comando clean
		//utilizaremos la funcion miembro del mismo nombre
		else if (str == "Clean" || str == "clean")
		{
			sort(elements.begin(), elements.end());//primero los ordenamos 
			elements.erase(unique(elements.begin(), elements.end()), elements.end());//y despues procedemos a borrar los duplicados
			system("cls");//limpia la pantalla
			printElements();//printa la lista modificada
		}

		//ADD BASICS-Nos aprovechamos de las funciones miembro
		//cuando el usuario nos ponga el comando add basics
		//a�adimos los 4 tipos basicos al vector utilizando el atributo addElement y la FM instert
		else if (str == "Add" || str == "add" && str2 == "basics" || str2 == "Basics" || str2 == "basics " || str2 == "Basics ")
		{			
				addElements("Air");
				addElements("Fire");
				addElements("Earth");
				addElements("Water");
				system("cls");//limpia la pantalla
				printElements();//printa la lista modificada
		}

		//ADD-Nos aprovechamos de las funciones miembro
		//cuando el usuario nos ponga el comando add
		//a�adiremos el elemento que quiera utilizando el atributo addElement y la FM insert
		else if (str == "Add" || str == "add")
		{
			b = stoi(str2);
			if(b>elements.size())//si pone un numero que no tiene en la lista salta este msj
				std::cout << "You don't have this element in your own!" << std::endl;
			else {
				b = stoi(str2);
				addElements(elements[b - 1]);
				system("cls");//limpia la pantalla
				printElements();//printa la lista modificada
			}
		}

		//DELETE-Nos aprovechamos de las funciones miembro
		//cuando el usuario nos ponga el comando delete
		//eliminaremos el elemento mediante la funcion miembro erase
		else if (str == "delete" || str == "Delete") {
			b = stoi(str2);
			if (b > elements.size())//si pone un numero que no tiene en la lista salta este msj
				std::cout << "You don't have this element in your own!" << std::endl;

			else {//si el elemento esta en la lista lo borra
				elements.erase(elements.begin() + (b - 1));
				system("cls");//limpia la pantalla
				printElements();//printa la lista modificada
			}

		}

		//INFO
		else if (str == "info" || str == "Info") {
			b = stoi(str2);
			if (b > elements.size()) {
				std::cout << "You don't have this element in your own!" << std::endl;
				printElements();			
			}
			else {
				std::string first = "https://es.wikipedia.org/wiki/";
				std::string second = elements[b - 1];
				std::string last = first + second;
				LPCSTR url = (LPCSTR)last.c_str();
				ShellExecuteA(nullptr, "open", url, nullptr, nullptr, SW_SHOWNORMAL);
				system("cls");//limpia la pantalla 
				printElements();//printa de nuevo la lista
			}
		}

		
		//HELP-Mediante el atributo creado volvemos a imprimir todos los comandos que hay 
		else if (str == "Help" || str == "help") {
			system("cls");
			PlayerElements::Comandos();
			printElements();
		}


		if ((str[0] >= '0' && str[0] <= '9') && (str2[0] >= '0' && str2[0] <= '9'))
		{
			a = stoi(str);
			b = stoi(str2);

			//COMBINATION
			for (auto it : A) {
				if ((elements[a - 1] == it.first.first) && (elements[b - 1] == it.first.second) || (elements[b - 1] == it.first.first) && (elements[a - 1] == it.first.second)) {
					elements.erase(elements.begin() + (a - 1));
					elements.erase(elements.begin() + (b - 2));					
					addElements(it.second);
					puntuacion++;
					break;
				}
				else {
					std::cout << "You don't have this element in your own!" << std::endl;
					break;
				}

				
			}
			
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

void PlayerElements::Comandos() { //utilizamos este atributo para imprmir mensajes por consola
	std::cout <<"-------------------------------HELP-IN-COMING------------------------------ "<< std::endl;
	std::cout << "Escribe - Sort - para ordenar los elementos" << std::endl;
	std::cout << "Escribe - Clean - para eliminar los elementos repetidos" << std::endl;
	std::cout << "Escribe - Add - y un numero para agregar un elemento" << std::endl;
	std::cout << "Escribe - Add basics - para a�adir los 4 elementos basicos" << std::endl;
	std::cout << "Escribe - Delete - y un numero para eliminar un elemento" << std::endl;
	std::cout << "Escribe - Info - para tener informacion de un elemento" << std::endl;
	std::cout << "Escribe - Help - para abrir este men�" << std::endl;
	std::cout <<"--------------------------------------------------------------------------- "<< std::endl;
	std::cout << std::endl;
}

PlayerElements::~PlayerElements()//destructor de la clase
{
}
