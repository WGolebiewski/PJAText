#include "Flags.h"

int to_num(const char* p);

int main(int argc, char* argv[])
{
    FileSetting setting;
    std::fstream file;
    static const std::string flags[11] = { "-f","-n","-d","-dd","-c","-a","-p","-pa","-ap","-s","-rs"};
    if (argc == 1)
        setting.flagsMenu();
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if (argv[i] == flags[0])
            {
                if (argc == 2)
                    std::cout << "\nMusisz podac nazwe pliku!";
                else
                {
                    if ((setting.isFile(file, argv[2])) == true)
                    {
                        std::cout << "\nOtworzono plik!";
                        i++;
                    }
                    else
                        std::cout << "\nNie znaleziono takiego pliku";
                }
            }
            else if (argv[i] == flags[1])
            {
                std::cout << "\nLiczba slow: " << setting.wordsCount(file, argv[2]);
            }
            else if (argv[i] == flags[2])
            {
                std::cout << "\nLiczba cyfr: " << setting.digitsInFile(file, argv[2]);
            }
            else if (argv[i] == flags[3])
            {
                std::cout << "\nLiczba liczb: " << setting.numbersInFile(file, argv[2]);
            }
            else if (argv[i] == flags[4])
            {
                std::cout << "\nLiczba znakow: " << setting.characterCount(file, argv[2]);
            }
            else if (argv[i] == flags[5])
            {
                if (i + 1 < argc)
                {
                    int result = to_num(argv[i + 1]);
                    if ((result >= 0) && (result <= setting.wordsCount(file, argv[2])))
                    {
                        i++;
                        std::cout << "\nAnagramy: ";
                        setting.anagram(file, argv[2], result);
                    }
                    else
                    {
                        i++;
                        std::cout << "\nAnagramy: Podano zla wartosc!";
                    }
                }
                else
                {
                    int result = 0;
                    if ((result >= 0) && (result <= setting.wordsCount(file, argv[2])))
                    {
                        i++;
                        std::cout << "\nAnagramy: ";
                        setting.anagram(file, argv[2], result);
                    }
                    else
                    {
                        i++;
                        std::cout << "\nAnagramy: Podano zla wartosc!";
                    }

                }
            }
            else if (argv[i] == flags[6])
            {
                if (i + 1 < argc)
                {
                    int result = to_num(argv[i + 1]);
                    if ((result >= 0) && (result <= setting.wordsCount(file, argv[2])))
                    {
                        i++;
                        std::cout << "\nPalindromy: ";
                        setting.palindrome(file, argv[2], result);
                    }
                    else
                    {
                        i++;
                        std::cout << "\nPalindromy: Podano zla wartosc!";
                    }
                }
                else
                {
                    int result = 0;
                    if ((result >= 0) && (result <= setting.wordsCount(file, argv[2])))
                    {
                        i++;
                        std::cout << "\nPalindromy: ";
                        setting.palindrome(file, argv[2], result);
                    }
                    else
                    {
                        i++;
                        std::cout << "\nPalindromy: Podano zla wartosc!";
                    }

                }
            }
            else if (argv[i] == flags[7])
            {
                // I think that is good solution
                if (i + 1 < argc)
                {
                    int result = to_num(argv[i + 1]);
                    if ((result >= 0) && (result <= setting.wordsCount(file, argv[2])))
                    {
                        i++;
                        std::cout << "\nPalindromy: ";
                        setting.palindrome(file, argv[2], result);
                        std::cout << "\nAnagramy: ";
                        setting.anagram(file, argv[2], result);
                    }
                    else
                    {
                        i++;
                        std::cout << "\nPalindromy i anagramy: Podano zla wartosc!";
                    }
                }
                else
                {
                    int result = 0;
                    if ((result >= 0) && (result <= setting.wordsCount(file, argv[2])))
                    {
                        i++;
                        std::cout << "\nPalindromy: ";
                        setting.palindrome(file, argv[2], result);
                        std::cout << "\nAnagramy: ";
                        setting.anagram(file, argv[2], result);
                    }
                    else
                    {
                        i++;
                        std::cout << "\nPalindromy i anagramy: Podano zla wartosc!";
                    }

                }
            }
            else if (argv[i] == flags[8])
            {
                int result = to_num(argv[i + 1]);
                // I think that is good solution
                if (i + 1 < argc)
                {
                    int result = to_num(argv[i + 1]);
                    if ((result >= 0) && (result <= setting.wordsCount(file, argv[2])))
                    {
                        i++; 
                        std::cout << "\nAnagramy: ";
                        setting.anagram(file, argv[2], result);
                        std::cout << "\nPalindromy: ";
                        setting.palindrome(file, argv[2], result);
                    }
                    else
                    {
                        i++;
                        std::cout << "\nAnagramy i palindromy: Podano zla wartosc!";
                    }
                }
                else
                {
                    int result = 0;
                    if ((result >= 0) && (result <= setting.wordsCount(file, argv[2])))
                    {
                        i++;
                        std::cout << "\nAnagramy: ";
                        setting.anagram(file, argv[2], result);
                        std::cout << "\nPalindromy: ";
                        setting.palindrome(file, argv[2], result);
                    }
                    else
                    {
                        i++;
                        std::cout << "\nAnagramy i palindromy: Podano zla wartosc!";
                    }

                }
            }
            else if (argv[i] == flags[9])
            {
                std::cout << "\nPosortowane: ";
                setting.allWordsSortInFile(file, argv[2]);
            }
            else if (argv[i] == flags[10])
            {
                std::cout << "\nNie poosortowane: ";
                setting.allWordsUnsortInFile(file, argv[2]);
            }
            else
                setting.flagsMenu();
        }
    }
}

int to_num(const char* p)
{
    int result = 0;
    const int len = strlen(p);
    for (int i = 0; *p; p++, i++)
    {
        result += (*p - '0') * pow(10, len - i);
    }
    return result / 10;
}