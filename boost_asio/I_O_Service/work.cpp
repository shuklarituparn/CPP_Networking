//
// Created by rituparn on 24.07.23.
//

//In this program giving some work for the io_service function to do

#include <boost/asio.hpp>
#include <iostream>

int main(void){
    boost::asio::io_service ioService;
    boost::asio::io_service::work worker(ioService);

    ioService.run();
    std::cout<<"We will not see this line in the terminal: "<<std::endl;

    return 0;
}

// g++ -Wall -ansi -std=c++17 work.cpp -o work

//didn't need to use -lboost here