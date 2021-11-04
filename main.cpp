#include <iostream>
#include "test.h"

int main(int argc, char **argv)
{
    int temp,x;
    std::cout << "\t\t\tHow to Play\n";
    std::cout << "The game requires the player and the computer to choose a 4-digit and all different numbers and" <<
    " the computer and the player has to find them via two types of clues that two sides give each other after each guess." <<
    " If the guess includes a number that are in the digits, the - parameter gains +1, if the guess includes a number that are in" <<
    " the digits AND it stays on the right digit, the + parameter gains +1. With these clues the player" <<
    " and the computer race each other to find the correct number with the least amount of tries." <<
    " Whichever side finds the number with the least amount of guesses wins the game." << std::endl;
    label1:
    std::cout << "Enter 1 for guess computer's number and enter 2 for test the computer decision capability. To exit enter -1." << std::endl;
    std::cin >> temp;

    test obj;
    while (temp != -1){
        switch(temp)
        {
            case 1:
                x = obj.random_num_gen();
                obj.number_guesser_from_comp(x);
                goto label1;
            case 2:
                obj.number_guesser_from_user();
                goto label1;
        }
    }

    return 0;
}
