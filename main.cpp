#include <iostream>
#include "test.h"

int main(int argc, char **argv)
{
    test obj;
    //std::cout << obj.random_num_gen();
    int x = obj.random_num_gen();
    obj.number_guesser_from_comp(x);
    return 0;
}
