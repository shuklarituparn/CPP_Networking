//
// Created by rituparn on 18.07.23.
//
#include "pwgen_fn.h"

std::string PasswordGenerator::Generate(int passWordLength) {
    int randomNumber;
    std::string Password;
    std::srand(std::time(0));
    for (int i = 0; i < passWordLength; ++i) {
        randomNumber=std::rand()%94+33;
        Password+= (char) randomNumber;

    }
    return Password;

}