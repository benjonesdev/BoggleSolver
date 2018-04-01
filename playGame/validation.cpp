#include "validation.hpp"
#include <cstdlib>
#include <ctime>
//if current letter is on one of the four corner
//next move can be

int validation(int min, int max)
{
    int p;
    do
    {
        std::cout << "Please enter a valid number from " << min << " to " << max << std::endl;
        std::cin >> p;
        while(std::cin.fail())
        {
            std::cout <<"Please enter integer number! \n";
            std::cin.clear();
            std::cin.ignore();
            std::cin >> p;
        }
    }while(!std::cin.fail() && (p < min || p >max));
    
    return p;
}

char validationChar()
{
    char decision;
    std::cout <<"Please enter your choice! Y or N \n";
    std::cin >> decision;
    while(std::cin.fail())
    {
        std::cout <<"Please reenter your decision! Y or N please\n";
        std::cin.clear();
        std::cin.ignore();
        std::cin >> decision;
    }
    return decision;
}


