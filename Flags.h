#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>

class FileSetting
{
private:
	std::string flags[13] = { "-f","-n","-d","-dd","-c","-a","-p","-pa","-ap","-s","-rs","-o" };
public:
	bool isFile(std::fstream& file, std::string fileName); // -f i nazwa pliku
	int wordsCount(std::fstream& file, std::string fileName); // -n
	int numbersInFile(std::fstream& file, std::string fileName); // -d
	bool providitedFlags(char *tab[], int argumentsCount);
	void flagsMenu();
};