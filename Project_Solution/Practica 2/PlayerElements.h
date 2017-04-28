#pragma once
#include <vector>
#include <string>

class PlayerElements
{
private:
	std::vector<std::string> elements;
public:
	
	PlayerElements();	
	void PlayerElements::addElements(std::string A);
	void PlayerElements::printElements();
	void PlayerElements::InputPlayer();
	~PlayerElements();
};

