//
// Created by rituparn on 24.07.23.
//


//non concurrent program- using the resource to compile one thing and then moving to other

#include <iostream>

void Print1(void){

    for (int i = 0; i < 5; ++i) {
        std::cout<<"[Print1] Line: "<<i<<std::endl;
    }
}

void Print2(void){

    for (int i = 0; i < 5; ++i) {
        std::cout<<"[Print2] Line: "<<i<<"\n";
    }
}

int main(void){
    Print1();
    Print2();
    return 0;
}