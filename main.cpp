#include <iostream>
#include <fstream>
#include "Flags.h"

int main(int argc, char* argv[])
{
    FileSetting setting;
    std::fstream file;
    if (setting.providitedFlags(argv, argc) == false)
    {
        if ((setting.isFile(file, argv[1])) == true)
        {
            std::cout << "Otworzone pomyslnie plik!";
            std::cout << "Liczba slow: " << setting.lineCount(file, argv[1]);
        }
        else
            std::cout << "Niestety nie udalo sie otworzyc pliku. Sproboj ponwonie";
    }
    else
    {
        setting.flagsMenu();
    }
}