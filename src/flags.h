#ifndef FLAGS_H_
#define FLAGS_H_
#include <fstream>
#include <ctype.h>
#include <algorithm>
#include <vector>

class Flags
{
protected:
	bool isAnagram(std::string firstWord, std::string secondWord);
	bool isPalindrom(std::string& firstWord, std::string& secondWord);
private:
	int numberLines = 0;
	int numberDigits = 0;
	int numberNumbers = 0;
	int numberCharacter = 0;
public:
	int numberOfLines(std::fstream& file);
	int numberOfDigits(std::fstream& file);
	int numberOfNumbers(std::fstream& file);
	int numberOfCharacters(std::fstream& file);
	void anagrams(std::fstream& file, std::string anagramWord);
	void palindroms(std::fstream& file, std::string alindromWord);
	void sortsAllWords(std::fstream& file);
	void reverseAlphabeticalOrder(std::fstream& file);
};

#endif