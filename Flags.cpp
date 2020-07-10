#include "Flags.h"

bool FileSetting::isFile(std::fstream& file, std::string fileName)
{
	file.open(fileName);
	if (file)
	{
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}
}

int FileSetting::wordsCount(std::fstream& file, std::string fileName)
{
	unsigned long int wordsCount = 0;
	std::string line;
	file.open(fileName, std::ios::in);
	while (file >> line)
	{
		wordsCount++;
	}
	file.close();
	return wordsCount;
}

int FileSetting::lineCount(std::fstream& file, std::string fileName)
{
	unsigned long int lineCount = 0;
	std::string line;
	file.open(fileName, std::ios::in);
	while (std::getline(file, line))
	{
		lineCount++;
	}
	file.close();
	return lineCount;
}

int FileSetting::digitsInFile(std::fstream& file, std::string fileName)
{
	unsigned long int digitsCount = 0;
	std::string line;
	file.open(fileName, std::ios::in);
	while (file >> line)
	{
		for (int i = 0; i < line.size(); i++)
		{
			if (isdigit(line[i]) == true)
				digitsCount++;
		}
	}
	file.close();
	return digitsCount;
}

int FileSetting::numbersInFile(std::fstream& file, std::string fileName)
{
	unsigned long int numberCount = 0;
	std::string line;
	file.open(fileName, std::ios::in);
	while (file >> line)
	{
		for (int i = 0; i < line.size(); i++)
		{
			if (isdigit(line[i]) == true && isdigit(line[i + 1]) == false)
				numberCount++;
		}
	}
	file.close();
	return numberCount;
}

int FileSetting::characterCount(std::fstream& file, std::string fileName)
{
	unsigned long int charCount = 0;
	std::string line;
	file.open(fileName, std::ios::in);
	while (file >> line)
	{
		for (int i = 0; i < line.size(); i++)
		{
			if (isdigit(line[i]) == false && line[i] != ' ')
				charCount++;
		}
	}
	file.close();
	return charCount;
}

void FileSetting::anagram(std::fstream& file, std::string fileName, int count)
{
	file.open(fileName, std::ios::in);
	std::string line;
	for (int i = 0; i < count; i++)
	{
		file >> line;
		std::sort(line.begin(), line.end());
		std::cout << line << " ";
	}
	file.close();
}

void FileSetting::palindrome(std::fstream& file, std::string fileName, int count)
{
	file.open(fileName, std::ios::in);
	std::string line;
	for (int i = 0; i < count; i++)
	{
		file >> line;
		if (isPalindrome(line) == true)
			std::cout << line << " ";
	}
	file.close();
}

bool FileSetting::isPalindrome(std::string name)
{
	if ((name == std::string(name.rbegin(), name.rend())))
		return true;
	else
		return false;
}

void FileSetting::allWordsSortInFile(std::fstream& file, std::string fileName)
{
	file.open(fileName, std::ios::in);
	std::vector<std::string>words;
	std::string line;
	unsigned long int temp = 0;
	while (file >> line)
	{
		for (int i = 0; i < line.size(); i++)
		{
			if (isdigit(line[i]) == false)
				temp++;
		}
		if (temp == line.size())
			words.push_back(line);
		temp = 0;
	}
	std::sort(words.begin(), words.end());
	for (int i = 0; i < words.size(); i++)
	{
		std::cout << words[i] << " ";
	}
	file.close();
}

void FileSetting::allWordsUnsortInFile(std::fstream& file, std::string fileName)
{
	file.open(fileName, std::ios::in);
	std::vector<std::string>words;
	std::string line;
	int temp = 0;
	while (file >> line)
	{
		for (int i = 0; i < line.size(); i++)
		{
			if (isdigit(line[i]) == false)
				temp++;
		}
		if (temp == line.size())
			words.push_back(line);
		temp = 0;
	}
	std::sort(words.begin(), words.end());
	for (int i = words.size() - 1; i >= 0; i--)
	{
		std::cout << words[i] << " ";
	}
	file.close();
}

bool FileSetting::providitedFlags(char* tab[], int argumentsCount)
{
	for (int i = 0; i < argumentsCount; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (tab[i] == flags[j])
			{
				return true;
			}
			else
				return false;
		}
	}
}

void FileSetting::flagsMenu()
{
	std::cout << "\n======Menu flag======\n-->Pamietaj, zeby wybrac flage<--\n";
	std::cout << "1. Bez flagi -> wtedy wyswietli Ci sie to menu!\n";
	std::cout << "2. -f -> nastepny argument, musi to byc nazwa pliku!\n";
	std::cout << "3. -n -> wypisuje ilosc lini, ale trzeba podac przed tym flage -f i nazwe pliku\n";
	std::cout << "4. -d -> wyswietla liczbe cyfr w pliku zrodlowym, wymagania co do zachowania programu w odniesieniu do tego pliku pozostata te same, co w poprzednich podpunktach. Dotyczy to tez pozostalych podpunktow.";
	std::cout << "5. -dd -> wyswietla liczbe liczb w piku zrodlowym\n";
	std::cout << "6. -c -> wyswietla liczbe znakow w pliku zrodlowym\n";
	std::cout << "7. -a -> po tej fladze trzeba podac liczbe wyswietlanych anagramow\n";
	std::cout << "8. -p -> po tej fladze trzeba podac liczbe wyswietlanych palindromow\n";
	std::cout << "9. -pa lub -ap -> w zaleznosci od kolejnosci dwoch liter wyswietla punkty 7-8 lub 8-7\n";
	std::cout << "10. -s -> wyswietla wszystkie slowa w kolejnosci alfabetycznej\n";
	std::cout << "10. -rs -> wyswietla wszystkie slowa w kolejnosci odwrotnej niz alfabetyczna\n";
	std::cout << "11. -o -> flaga powinna znalezc sie na koncu flag. Wszystkie poprzednie flagi zapisuje do nowego pliku\n";
}