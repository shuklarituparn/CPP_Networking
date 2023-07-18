//
// Created by rituparn on 18.07.23.
//
#include <iostream>
#include "pwgen_fn.h"

int main(void){
    int passLen;
    std::cout<<"Define Password Lenght: ";
    std::cin>>passLen;
    PasswordGenerator pg;
    std::string password= pg.Generate(passLen);
    std::cout<<"Your password is: "<<password;
}