//
// Created by rituparn on 24.07.23.
//

#include <boost/bind.hpp>
#include <iostream>

void func(){
    std::cout<<"Binding Function"<<std::endl;
}

int main(void){
    boost::bind(&func);
    return 0;
}

/*

 int main(void){
    boost::bind(&func);
    return 0;
}   //No output as we created a function invocation without calling it
 *
 *
 */

