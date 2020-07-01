#include <iostream>
#include <fstream>
#include "Flags.h"

int main(int argc, char* argv[])
{
    FileSetting setting;
    std::fstream file;
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
                std::cout << "\nLiczba slow: " << setting.lineCount(file, argv[2]);
                std::cout << "\nLiczba cyfr: " << setting.numbersInFile(file, argv[2]);
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