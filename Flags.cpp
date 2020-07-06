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
	int wordsCount = 0;
	std::string line;
	file.open(fileName, std::ios::in);
	while (file >> line)
	{
		wordsCount++;
	}
	file.close();
	return wordsCount;
}

int FileSetting::digitsInFile(std::fstream& file, std::string fileName)
{
	int digitsCount = 0;
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

int FileSetting::numberInFile(std::fstream& file, std::string fileName)
{
	int numberCount = 0;
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
	int charCount = 0;
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
		std::cout << std::string(line.rbegin(), line.rend()) << " ";
	}
	file.close();
}

void FileSetting::palindrome(std::fstream& file, std::string fileName, int count)
{
	file.open(fileName, std::ios::in);
	std::string line;
	for(int i = 0; i < count;i++)
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

void FileSetting::launchFlags(std::string flagsName, int argumentsCount)
{
	//switch case!
}

bool FileSetting::providitedFlags(char *tab[], int argumentsCount)
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
	std::cout << "4. -d -> wyswietla liczbe cyfr w w pliku zrodlowym, Wymagania co do zachowania programu w odniesieniu do tego pliku pozostata te same, co w poprzednich podpunktach. Dotyczy to tez pozostalych podpunktow.";

}