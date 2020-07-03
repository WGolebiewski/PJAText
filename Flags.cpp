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

int FileSetting::numbersInFile(std::fstream& file, std::string fileName)
{
	int digitsNumber = 0;
	std::string line;
	file.open(fileName, std::ios::in);
	while (file >> line)
	{
		for (int i = 0; i < line.size(); i++)
		{
			if (isdigit(line[i]) == true)
				digitsNumber++;
		}
	}
	file.close();
	return digitsNumber;
}

bool FileSetting::providitedFlags(char *tab[], int argumentsCount)
{
	bool differenTab;
	for (int i = 1; i < argumentsCount; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (tab[i] == flags[j])
			{
				return false;
			}
			else
				return true;
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