//
// Created by rituparn on 23.07.23.
//
#include <boost/random/random_device.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <iostream>

int main(void){

    int guessNumber;
    std::cout<<"Enter a random number: ";
    std::cin>>guessNumber;

    if (guessNumber<0 || guessNumber>10){
        return 1;
    }
    boost::random::random_device  rng;
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


//g++ -Wall -ansi -std=c++17 main.cpp -o main -lboost_random compiling with boost, need to mention the lib at the end