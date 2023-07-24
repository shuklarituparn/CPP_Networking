//
// Created by rituparn on 24.07.23.
//

#include <boost/bind/bind.hpp>
#include <iostream>
#include <string>

class TheClass{
public:
    void identity(std::string name, int age, float height){
        std::cout<<"Name: "<<name<< std::endl;
        std::cout<<"Age: "<<age<<" years old"<<std::endl;
        std::cout<<"Height: "<<height<<" inch"<<std::endl;
    }
};

int main(){
    TheClass cls;
    boost::bind(&TheClass::identity, &cls,"John", 25,68.89f)(); //passing the class and function, obj, and rest of the argument
    return 0;
}