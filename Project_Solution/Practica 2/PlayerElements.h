#pragma once
#include <vector>
#include <string>
#include <unordered_map>

template<>
struct std::hash<std::pair<std::string, std::string>>
{
	size_t operator()(const std::pair<std::string, std::string> & p) const {
		return ((hash<std::string>()(p.first) ^ (hash<std::string>()(p.second) << 1) >> 1));
	}
};

class PlayerElements
{
private:
	std::vector<std::string> elements;
	int puntuacion;
public:
	
	PlayerElements();
	void PlayerElements::addElements(std::string A);
	void PlayerElements::printElements();
	void PlayerElements::InputPlayer(std::unordered_map<std::pair<std::string, std::string>, std::string> A);
	void PlayerElements::Comandos();
	bool PlayerElements::getBool(bool EndGame);
	~PlayerElements();
};

