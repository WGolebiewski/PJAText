#include "flags.h"
#include <iostream>

void flags();
bool isFlag(std::string str);
const std::string flag[] = { "-f", "-n", "-d" , "-dd" , "-c" , "-a" , "-p" , "-pa" , "-ap" , "-s" , "-rs" };

int main(int argc, char* argv[]) {
	std::fstream file;
	std::string fileName;
	Flags setFlag;
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			if (argv[i] == flag[0] && argc >= 2) {
				if (argc == 2) {
					std::cout << "Please enter filename or file path!\n";
				} else {
					fileName = argv[2];
					file.open(fileName, std::ios::in);
					if (file) {
						std::cout << "File successfully opened!";
						i++;
					}
					else {
						std::cout << "File not opened. Check filename or file path!\n";
						break;
					}
					file.close();
				}
			} else if (argv[i] == flag[1]) {
				fileName = argv[2];
				file.open(fileName, std::ios::in);
				std::cout << "\nNumber of lines: " << setFlag.numberOfLines(file);
				file.close();
			} else if (argv[i] == flag[2]) {
				fileName = argv[2];
				file.open(fileName, std::ios::in);
				std::cout << "\nNumber of digits: " << setFlag.numberOfDigits(file);
				file.close();
			} else if (argv[i] == flag[3]) {
				fileName = argv[2];
				file.open(fileName, std::ios::in);
				std::cout << "\nNumber of numbers: " << setFlag.numberOfNumbers(file);
				file.close();
			} else if (argv[i] == flag[4]) {
				fileName = argv[2];
				file.open(fileName, std::ios::in);
				std::cout << "\nNumber of characters: " << setFlag.numberOfCharacters(file);
				file.close();
			} else if (argv[i] == flag[5]) {
				std::cout << "\nAnagrams: ";
				int j = i;
				if (argc >= j + 1) {
					j++;
					while (!isFlag(argv[j])) {
						fileName = argv[2];
						file.open(fileName, std::ios::in);
						setFlag.anagrams(file, argv[j]);
						file.close();
						j++;
						if (j == argc) {
							break;
						}
					}
					i = j - 1;
				} else {
					std::cout << "No arguments!";
				}
			} else if (argv[i] == flag[6]) {
				std::cout << "\nPalindroms: ";
				int j = i;
				if (argc >= j + 1) {
					j++;
					while (!isFlag(argv[j])) {
						fileName = argv[2];
						file.open(fileName, std::ios::in);
						setFlag.palindroms(file, argv[j]);
						file.close();
						j++;
						if (j == argc) {
							break;
						}
					}
					i = j - 1;
				} else {
					std::cout << "No arguments!";
				}
			} else if (argv[i] == flag[7]) {
				std::cout << "\nPalindroms: ";
				int j = i, k = i;
				if (argc >= j + 1) {
					j++;
					while (!isFlag(argv[j])) {
						fileName = argv[2];
						file.open(fileName, std::ios::in);
						setFlag.palindroms(file, argv[j]);
						file.close();
						j++;
						if (j == argc) {
							break;
						}
					}
					i = j - 1;
				} else {
					std::cout << "No arguments!";
				}
				std::cout << "\nAnagrams: ";
				if (argc >= k + 1) {
					k++;
					while (!isFlag(argv[k])) {
						fileName = argv[2];
						file.open(fileName, std::ios::in);
						setFlag.anagrams(file, argv[k]);
						file.close();
						k++;
						if (k == argc) {
							break;
						}
					}
					i = k - 1;
				} else {
					std::cout << "No arguments!";
				}
			} else if (argv[i] == flag[8]) {
				std::cout << "\nAnagrams: ";
				int j = i, k = i;
				if (argc >= j + 1) {
					j++;
					while (!isFlag(argv[j])) {
						fileName = argv[2];
						file.open(fileName, std::ios::in);
						setFlag.anagrams(file, argv[j]);
						file.close();
						j++;
						if (j == argc) {
							break;
						}
					}
					i = j - 1;
				} else {
					std::cout << "No arguments!";
				}
				std::cout << "\nPalindroms: ";
				if (argc >= k + 1) {
					k++;
					while (!isFlag(argv[k])) {
						fileName = argv[2];
						file.open(fileName, std::ios::in);
						setFlag.palindroms(file, argv[k]);
						file.close();
						k++;
						if (k == argc) {
							break;
						}
					}
					i = k - 1;
				} else {
					std::cout << "No arguments!";
				}
			} else if (argv[i] == flag[9]) {
				fileName = argv[2];
				file.open(fileName, std::ios::in);
				std::cout << "\nAll words in alphabetical order: ";
				setFlag.sortsAllWords(file); 
				file.close();
			} else if (argv[i] == flag[10]) {
				fileName = argv[2];
				file.open(fileName, std::ios::in);
				std::cout << "\nAll words in reverse alphabetical order: ";
				setFlag.reverseAlphabeticalOrder(file);
				file.close();
			} else {
				flags();
			}
		}
	} else {
		flags();
	}
}

void flags() {
	std::cout << "\n--- Flags ---\n";
	std::cout << "None flags -> flags menu\n";
	std::cout << "Flag '-f' -> must be first flag and next arument must be filename or file path\n";
	std::cout << "Flag '-n' -> shows how many lines are in the file\n"; 
	std::cout << "Flag '-d' -> shows number of digits are in the file\n"; 
	std::cout << "Flag '-dd' -> shows how many numbers are in the file\n";  
	std::cout << "Flag '-c' -> shows number of characters are in the file\n"; 
	std::cout << "Flag '-a' -> should be the last flag and can be an undefined number of words and shows all anagrams\n"; 
	std::cout << "Flag '-p' -> should be the last flag and can be an undefined number of words and shows all palindroms\n";
	std::cout << "Flag '-pa' -> combines both functions '-p' and '-a'\n"; 
	std::cout << "Flag '-ap' -> combines both functions '-p' and '-a'\n"; 
	std::cout << "Flag '-s' -> sorts all words in alphabetical order\n";
	std::cout << "Flag '-rs' -> is reverse function '-s'\n";
}

bool isFlag(std::string str) {
	for (int i = 0; i < 11; i++)
	{
		if (str == flag[i]) {
			return true;
		}
	}
	return false;
}