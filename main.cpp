#include <iostream>
#include <fstream>
#include "Flags.h"

int main(int argc, char* argv[])
{
    FileSetting setting;
    std::fstream file; 
    int temp = 0, temp2 = 0;
    if (argc >= 5)
    {
        temp = std::atoi(argv[3]);
        temp2 = std::atoi(argv[4]);
    }
    if (argc <= 1)
    {
        setting.flagsMenu();
    }
    else
    {
        if (setting.providitedFlags(argv, argc) == false)
        {
            if ((setting.isFile(file, argv[2])) == true)
            {
                std::cout << "Otworzone pomyslnie plik!";
                std::cout << "\nLiczba slow: " << setting.wordsCount(file, argv[2]);
                std::cout << "\nLiczba cyfr: " << setting.digitsInFile(file, argv[2]);
                std::cout << "\nLiczba liczb: " << setting.numberInFile(file, argv[2]);
                std::cout << "\nLiczba liter: " << setting.characterCount(file, argv[2]);
                if (temp > setting.wordsCount(file, argv[2]))
                {
                    std::cout << "\nAnagramy: podano za duza liczbe!";
                }
                else if (temp < 0)
                {
                    std::cout << "\nAnagramy: podano za mala liczbe!";
                }
                else
                {
                    std::cout << "\nAnagramy: "; setting.anagram(file, argv[2], temp);
                }
                if (temp2 > setting.wordsCount(file, argv[2]))
                {
                    std::cout << "\nPalindromy: Nie mozesz podac wiekszej ilosci niz jest w pliku!";
                }
                else if (temp2 > 0)
                {
                    std::cout << "\nPalindromy: podano za mala liczbe!";
                }
                else
                {
                    std::cout << "\nPalindromy: "; setting.palindrome(file, argv[2], temp2);
                }
                std::cout << "\nPosortowane: "; setting.allWordsSortInFile(file, argv[2]);
                std::cout << "\nNie posortowane: "; setting.allWordsUnsortInFile(file, argv[2]);
            }
            else
                std::cout << "Niestety nie udalo sie otworzyc pliku. Sproboj ponwonie";
        }
        else
        {
            setting.flagsMenu();
        }
    }
}