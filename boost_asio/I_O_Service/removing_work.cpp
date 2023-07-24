//
// Created by rituparn on 24.07.23.
//

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>

int main(void){

    boost::asio::io_service ioService;
    boost::shared_ptr<boost::asio::io_service::work> worker(new boost::asio::io_service::work (ioService));

    //The shared_pointer points to the work

    worker.reset(); //to reset the io_service object when it prepares for a subsequent run() function invocation.
    ioService.run();// as the work was resetted there's nothing to do and hence we see the following line

    std::cout<<"We will not see this line in the terminal :("<<std::endl;

    return 0;
}