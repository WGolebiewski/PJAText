#include <iostream>
#include <fstream>
#include "Flags.h"

int main(int argc, char* argv[])
{
    FileSetting setting;
    std::fstream file; 
    int temp = 0;
    if (argc == 4)
        temp = std::atoi(argv[3]);
    if (argc == 1)
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
                std::cout << "\nPalindromy: " << setting.palindrome(file, argv[2], temp);
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