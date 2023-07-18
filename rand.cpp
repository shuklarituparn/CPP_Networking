#include<cstdlib>
#include<iostream>
#include <ctime>


int main(){

    int guessNumber;
    std::cout<<"Select a number from 0 to 10: ";
    std::cin>>guessNumber;
    if (guessNumber<0 || guessNumber>10){
        return 1;
    }
    std::srand(std::time(0));
    int randomNumber= (std::rand()%(10+1));

    if (guessNumber== randomNumber){
        std::cout<<"Congratulations you guesses correctly\n";
    }else{
        std::cout<<"The random number was: "<<randomNumber;
    }
}