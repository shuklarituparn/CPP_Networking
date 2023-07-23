//
// Created by rituparn on 23.07.23.
//


#include <boost/lexical_cast.hpp>
#include <string>
#include <iostream>


int main(void){

    try {
        std::string str;
        std::cout<<"Please enter the first number: ";
        std::cin>>str;
        int n1= boost::lexical_cast<int>(str);
        std::cout<<"Enter the second number: ";
        std::cin>>str;
        int n2= boost::lexical_cast<int>(str);
        std::cout<<"The sum of the two numbers are: ";
        std::cout<<n1+n2<<"\n";
        return 0;
    }
    catch (const boost::bad_lexical_cast &e) {
        std::cerr<<e.what()<<"\n";
        return 1;
    }
}

//So basically taking the input in form of string and then giving int. NICE!