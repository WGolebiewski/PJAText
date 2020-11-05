#include "flags.h"
#include <iostream>

int Flags::numberOfLines(std::fstream& file) {
	std::string str;
	while (file >> str) {
		numberLines++;
	}
	file.close();
	return numberLines;
}

int Flags::numberOfDigits(std::fstream& file) {
	std::string str;
	while (file >> str) {
		for (int i = 0; i < str.length(); i++) {
			if (isdigit(str[i])) {
				numberDigits++;
			}
		}
	}
	file.close();
	return numberDigits;
}

int Flags::numberOfNumbers(std::fstream& file) {
	std::string str;
	while (file >> str) {
		for (int i = 0; i < str.length(); i++) {
			if (isdigit(str[i]) && (isdigit(str[i + 1]))) {
				numberNumbers++;
				i = str.length() - 1;
			}
		}
	}
	file.close();
	return numberNumbers;
}

int Flags::numberOfCharacters(std::fstream& file) {
	std::string str;
	while (file >> str) {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ' || str[i] == '\0') {
				i++;
			} else if (!isdigit(str[i])) {
				numberCharacter++;
			}
		}
	}
	file.close();
	return numberCharacter;
}

void Flags::anagrams(std::fstream& file, std::string anagramWord) {
	std::string str;
	while (file >> str) {
		if (isAnagram(anagramWord, str)) {
			std::cout << str << " ";
		}
	}
}

void Flags::palindroms(std::fstream& file, std::string palindromWord) {
	std::string str;
	while (file >> str) {
		if (isPalindrom(palindromWord, str)) {
			std::cout << str << " ";
		}
	}
}

bool Flags::isAnagram(std::string firstWord, std::string secondWord) {
	std::sort(firstWord.begin(), firstWord.end());
	std::sort(secondWord.begin(), secondWord.end());
	if (firstWord == secondWord) {
		return true;
	} else {
		return false;
	}
}

bool Flags::isPalindrom(std::string& firstWord, std::string& secondWord) {
	int dontAsk = 0;
	int lengthFirstWord = firstWord.length(), lengthSecondWord = secondWord.length();
	if (lengthFirstWord == lengthSecondWord) {
		std::string temp = secondWord;
		for (int i = 0; i < lengthFirstWord; i++) {
			if (temp[i] == firstWord[lengthFirstWord - 1 - i]) {
				dontAsk++;
			}
		}
		if (dontAsk == firstWord.length()) {
			return true;
		}
		else {
			return false;
		}
	} else {
		return false;
	}
}

void Flags::sortsAllWords(std::fstream& file) {
	std::vector<std::string>wordsFromFile;
	std::string str;
	while (file >> str) {
		wordsFromFile.push_back(str);
	}
	std::sort(wordsFromFile.begin(), wordsFromFile.end());
	for (int i = 0; i < wordsFromFile.size(); i++) {
		std::cout << wordsFromFile[i] << ' ';
	}
	file.close();
}

void Flags::reverseAlphabeticalOrder(std::fstream& file) {
	std::vector<std::string>wordsFromFile;
	std::string str;
	while (file >> str){
		wordsFromFile.push_back(str);
	}
	std::sort(wordsFromFile.begin(), wordsFromFile.end());
	for (int i = 0; i < wordsFromFile.size(); i++) {
		std::cout << wordsFromFile[wordsFromFile.size()-i-1] << ' ';
	}
	file.close();
}
