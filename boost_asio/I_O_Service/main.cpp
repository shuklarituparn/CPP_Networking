//
// Created by rituparn on 24.07.23.
//
#include <boost/asio.hpp>
#include <iostream>

int main(void){

    boost::asio::io_service io_svc;
    io_svc.run();

    std::cout<<"We'll see this line in the console window: "<<std::endl;

    return 0;
}

//io service used to access operating system resources, run() statement blocks the next block of code from executing till its finished


//Here we see the line as we didn't give any argument to the run function