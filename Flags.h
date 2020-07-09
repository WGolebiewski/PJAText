#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <math.h>

class FileSetting
{
private:
	const std::string flags[13] = { "-f","-n","-d","-dd","-c","-a","-p","-pa","-ap","-s","-rs","-o" };
	bool isPalindrome(std::string name);
public:
	bool isFile(std::fstream& file, std::string fileName); // -f and file name
	int wordsCount(std::fstream& file, std::string fileName); // -n
	int digitsInFile(std::fstream& file, std::string fileName); // -d
	int numbersInFile(std::fstream& file, std::string fileName); // -dd
	int characterCount(std::fstream& file, std::string fileName); // -c
	void anagram(std::fstream& file, std::string fileName, int count); // -a
	void palindrome(std::fstream& file, std::string fileName, int count); // -p
	void allWordsSortInFile(std::fstream& file, std::string fileName); // -s
	void allWordsUnsortInFile(std::fstream& file, std::string fileName); // -rs
	bool providitedFlags(char* tab[], int argumentsCount);
	void flagsMenu();
};