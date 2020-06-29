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

int FileSetting::lineCount(std::fstream& file, std::string fileName)
{
	int lineCount = 1;
	std::string line;
	file.open(fileName);
	while (!file.eof())
	{
		getline(file, line);
	}
	for(int i = 0; i < line.size(); i++)
	{
		if (line[i] == 32)
			lineCount++;
	}
	file.close();
	return lineCount;
}

bool FileSetting::providitedFlags(char *tab[], int argc)
{
	bool differenTab;
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (tab[i] == flags[j])
			{
				differenTab = false;
				break;
			}
			else
				differenTab = true;
		}
	}
	return differenTab;
}

void FileSetting::flagsMenu()
{
	std::cout << "==Menu flag==\n==Pamietaj, zeby wybrac flage==\n";
	std::cout << "1. Bez flagi -> wtedy wyswietli Ci sie to menu!\n";
	std::cout << "2. -f -> nastepny argument, musi to byc nazwa pliku!\n";
	std::cout << "3. -n -> wypisuje ilosc lini, ale musi podac przed tym flage -f i nazwe pliku\n";
}