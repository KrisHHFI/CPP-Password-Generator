#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

char alphabetLetters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char symbols[29] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '-', '+', '=', '{', '}', '[', ']', '|', ':', ';', '"', '\'', '<', '>', ',', '.', '/', '?'};
std::string generatedPassword = {};
int upperRange;

void randomLetter()
{
    upperRange = 26;
    int randomLetter = rand() % upperRange;
    upperRange = 2;
    int capsOrNot = rand() % upperRange;

    if (capsOrNot == 0)
    {
        char uppercaseLetter = toupper(alphabetLetters[randomLetter]);
        generatedPassword.push_back(uppercaseLetter);
    }
    else
    {
        generatedPassword.push_back(alphabetLetters[randomLetter]);
    }
}

void randomNumber()
{
    upperRange = 10;
    int randomNumber = rand() % upperRange;
    std::string randomNumberChar = std::to_string(randomNumber);
    generatedPassword += randomNumberChar;
}

void randomSymbol()
{
    upperRange = 29;
    int randomSymbol = rand() % upperRange;
    generatedPassword.push_back(symbols[randomSymbol]);
}

int main()
{
    srand((unsigned)time(NULL));

    for (int i = 0; i < 20; i++)
    {
        upperRange = 3;
        int choice = rand() % upperRange;

        if (choice == 0)
        {
            randomLetter();
        }
        else if (choice == 1)
        {
            randomNumber();
        }
        else
        {
            randomSymbol();
        }
    }
    std::cout << "Generated Password: " << generatedPassword << std::endl;
}