//
// Created by rituparn on 24.07.23.
//


#include <iostream>
#include <boost/asio.hpp>

int main(void){
    boost::asio::io_service ioService;
    boost::asio::io_service::work work(ioService);

    for (int i = 0; i < 5; ++i) {
        ioService.poll();
        std::cout<<"Line: "<<i<<std::endl;
    }
    return 0;
}

//seeing the same output as poll as the poll function doesn't block the rest of the program