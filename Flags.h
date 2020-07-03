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
	bool isFile(std::fstream& file, std::string fileName); // -f and file name
	int wordsCount(std::fstream& file, std::string fileName); // -n
	int digitsInFile(std::fstream& file, std::string fileName); // -d
	int numberInFile(std::fstream& file, std::string fileName); // -dd
	int characterCount(std::fstream& file, std::string fileName);
	bool providitedFlags(char *tab[], int argumentsCount);
	void flagsMenu();
};