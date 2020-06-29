#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileSetting
{
private:
	std::string flags[13] = { "-f","-n","-d","-dd","-c","-a","-p","-pa","-ap","-s","-rs","-o" };
public:
	bool isFile(std::fstream& file, std::string fileName);
	int lineCount(std::fstream& file, std::string fileName);
	bool providitedFlags(char *tab[], int argc);

	void flagsMenu();
};