//
// Created by rituparn on 23.07.23.
//

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <iostream>

int main(void){

    int guessNumber;
    std::cout<<"Enter a random number: ";
    std::cin>>guessNumber;

    if (guessNumber<0 || guessNumber>10){
        return 1;
    }
    boost::random::mt19937 rng;
    boost::random::uniform_int_distribution<> ten(0,10);
    int randomNumber=ten(rng);
    if (guessNumber==randomNumber){
        std::cout<<"Congratulations, "<<guessNumber<< " is your lucky number \n";
    }
    else{
        std::cout<<"Sorry, I am thinking about the number "<<randomNumber<<"\n";

    }
    return 0;

}

//The problem in this code is that it generates only one random number, 8 to be precise