//
// Created by rituparn on 24.07.23.
//

#include <boost/bind.hpp>
#include <iostream>

void func(){
    std::cout<<"Binding Function "<<std::endl;
}

int main(){
    boost::bind(&func)();
    return 0;
}
