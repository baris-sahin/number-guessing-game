#include "test.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

test::test() //ctor
{
    last_index = -1;
    current_index = 0;
    smallest_value = 123;
}

int test::number_guesser_from_user()
{
    /* initialize random seed: */
    place_holder = last_index;
    srand (time(NULL));
    while(hint_plus[last_index] != 4)
    {
        label2:
        if(smallest_value == 10000){
            std::cout << "Something wrong with given answer" << std::endl;
        }
        if(current_index == 0 || (rand()%10) != 9){ // %90 chance random number will be choosen
            label5:
            first_digit[current_index] = rand()%10;
            if (first_digit[current_index] == 0) { goto label5;} //to make sure first digit is not 0
            second_digit[current_index] = rand()%10;
            third_digit[current_index] = rand()%10;
            fourth_digit[current_index] = rand()%10;
        }
        else{ //%10 chance smallest value possible
            temp=smallest_value;
            first_digit[current_index] =  temp/1000 % 10;
            second_digit[current_index] =  temp/100 % 10;
            third_digit[current_index] =  temp/10 % 10;
            fourth_digit[current_index] =  temp % 10;
            smallest_value++;
        }

            //Checking if digits are repated or not. If repated, reroll.
        if ((first_digit[current_index]==second_digit[current_index]||first_digit[current_index]==third_digit[current_index]||first_digit[current_index]==fourth_digit[current_index])
         || (second_digit[current_index]==third_digit[current_index]||second_digit[current_index]==fourth_digit[current_index]) || (third_digit[current_index]==fourth_digit[current_index]))
        {
            goto label2;
        }
        label3:
        //If newly created number's digit value is same with one of old guessed number's digits, it might be one of the minus hints.
        if(first_digit[current_index]==second_digit[last_index] || first_digit[current_index]==third_digit[last_index] || first_digit[current_index]==fourth_digit[last_index]){
            hint_minus[current_index] = hint_minus[current_index] + 1;
        }//If newly created number's digit value is same with old guessed number's corresponding digit, it might be of the pluses.
        if(first_digit[current_index]==first_digit[last_index]){
            hint_plus[current_index]=hint_plus[current_index]+1;
        }
        //Rinse and repeat for every digit.
        if(second_digit[current_index]==first_digit[last_index] || second_digit[current_index]==third_digit[last_index]||second_digit[current_index]==fourth_digit[last_index]){
            hint_minus[current_index]=hint_minus[current_index]+1;
        }
        if(second_digit[current_index]==second_digit[last_index]){
            hint_plus[current_index]=hint_plus[current_index]+1;
        }
        if(third_digit[current_index]==second_digit[last_index]||third_digit[current_index]==first_digit[last_index]||third_digit[current_index]==fourth_digit[last_index]){
            hint_minus[current_index]=hint_minus[current_index]+1;
        }
        if(third_digit[current_index]==third_digit[last_index]){
            hint_plus[current_index]=hint_plus[current_index]+1;
        }
        if(fourth_digit[current_index]==second_digit[last_index]||fourth_digit[current_index]==third_digit[last_index]||fourth_digit[current_index]==first_digit[last_index]){
            hint_minus[current_index]=hint_minus[current_index]+1;
        }
        if(fourth_digit[current_index]==fourth_digit[last_index]){
            hint_plus[current_index]=hint_plus[current_index]+1;
        }
        //Start checking difference between new and old hints after the first round.
        while(last_index>=0){
            //If last generated number is can not satisfy the hint condition, try again.
             if (hint_plus[current_index]!=hint_plus[last_index]||hint_minus[current_index]!=hint_minus[last_index]){
                 hint_plus[current_index]=hint_minus[current_index]=0;
                 last_index=place_holder;
                 goto label2;
             }
             last_index=last_index-1;
             hint_plus[current_index]=hint_minus[current_index]=0;
             goto label3;
        }
        //If satisfies, increase the indexes and assign to use for next loop's check values.
        last_index=place_holder+1; place_holder=last_index; smallest_value=1023;
        label4:
        std::cout << "\nI guess " << first_digit[current_index] << second_digit[current_index] << third_digit[current_index] << fourth_digit[current_index] << "\n + : ";
        first_digit[last_index]=first_digit[current_index];
        second_digit[last_index]=second_digit[current_index];
        third_digit[last_index]=third_digit[current_index];
        fourth_digit[last_index]=fourth_digit[current_index];
        std::cin >> hint_plus[last_index];
        if (hint_plus[last_index] < 0 || hint_plus[last_index] > 4){
            std::cout << "Please check your answer it is not within the bound.";
            goto label4;
        }
        if (hint_plus[last_index] != 4){
            std::cout << "- :";
            std::cin >> hint_minus[last_index];
        }
        current_index=current_index+1;
        if (hint_plus[last_index]==4){
            std::cout << "I won in " << current_index << " tries" << std::endl;
        }
    }
    return 0;
}

int test::random_num_gen()
{
   srand(time(NULL));

   bool digitUsed[10] = {0};// to keep track of which digits have been used
   const int numDigits = 4;// this can be as high as 10

   // 1st digit
   int x = rand()%10;// x will be the 4 digit number
   digitUsed[x] = true;

   for(int i = 1; i < numDigits; ++i )
   {
       int digit = 0;
       do// until unique digit generated
       {
           digit = rand()%10;
       }while( digitUsed[digit] );

       digitUsed[digit] = true;// mark this digit as used now
       x *= 10;// put a zero on the end
       x += digit;// becomes last digit
   }
	return x;
}

int test::number_guesser_from_comp(int random_num)
{
    int guess_counter = 0, p,m,n, i_fd, i_td, i_sd, i_ld, fd, sd, td, ld; //guess counter
    p = 0; //plus counter
    m = 0; //minus counter
    n = 0; //temp value for incoming guess
    // randomly genarated numbers digits
    ld = random_num%10;
    td = (random_num/10)%10;
    sd = (random_num/100)%10;
    fd = (random_num/1000)%10;

    while(p != 4){
        label1:
        std::cout << std::endl << "Guess: ";
        std::cin >> n;
        if (n < 1023 || n > 9876){ //to make sure given guess is within border.
            std::cout << "Your input is out of bound. Please try again." << std::endl;
            goto label1;
        }
        i_ld =  n % 10;        //fourth digit
        i_td = (n/10)%10;      //third digit
        i_sd = (n/100)%10;     //second digit
        i_fd = (n/1000)%10;    //first digit
        if(i_fd == i_sd || i_fd==i_td || i_fd==i_ld || i_sd==i_td || i_sd==i_ld || i_td==i_ld){ //to make sure input's digits are unique
            std::cout << "Your input contains repeated digits. Please try again.";
            goto label1;
        }
        //Checking for each digit
        m = 0; p = 0;
		if(i_fd==sd||i_fd==td||i_fd==ld){ //first digit
		m=m+1;
		}else if(i_fd==fd){
        p=p+1;
        }
        if(i_sd==fd||i_sd==td||i_sd==ld){ //second digit
		m=m+1;
		}else if(i_sd==sd){
        p=p+1;
        }
        if(i_td==fd||i_td==sd||i_td==ld){ //third digit
		m=m+1;
		}else if(i_td==td){
        p=p+1;
        }
        if(i_ld==fd||i_ld==sd||i_ld==td){ //last digit
		m=m+1;
		}else if(i_ld==ld){
        p=p+1;
        }
        guess_counter++;
        std::cout << "+:  " << p << " | -: " << m << std::endl;
    }
    std::cout << "Congratulations, you found it! And it only took " << guess_counter << " tries!" << std::endl;
            std::cout <<   "    ,,,,," << std::endl;
        std::cout <<  "   _|||||_ "<< std::endl;
        std::cout << "  {~*~*~*~}"<< std::endl;
        std::cout <<"__{*~*~*~*}__ "<< std::endl;
        std::cout <<"`-------------`"<< std::endl;
    return 0;
}
