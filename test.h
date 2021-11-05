#ifndef TEST_H
#define TEST_H

class test
{
public:
    test(); //ctor
    int last_index,current_index, place_holder, smallest_value, temp;
    int first_digit[10],second_digit[10],third_digit[10],fourth_digit[10], hint_plus[10], hint_minus[10];
    int number_guesser_from_user();        //number guessing function
    int random_num_gen();                  //random number generator for guessing game
    int number_guesser_from_comp(int);     //
};




#endif
