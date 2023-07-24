//
// Created by rituparn on 24.07.23.
//

#include <boost/bind/bind.hpp>
#include <iostream>

void cubeVolume(float f){
    std::cout<<"Volume of the cube is: "<<f*f*f<<std::endl;
}

int main(void){
    boost::bind(&cubeVolume, 4.23f) (); //calling the function with the argument using boost bind

}