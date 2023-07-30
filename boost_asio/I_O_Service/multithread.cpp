//
// Created by rituparn on 24.07.23.
//

#include <iostream>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>


boost::asio::io_service ioService;
int a=0;

void workerThread(){
    std::cout<<++a<<".\n";
    ioService.run();
    std::cout<<"End. \n";
}

int main(){
    boost::shared_ptr<boost::asio::io_service::work> worker(new boost::asio::io_service::work(ioService));

    std::cout<<"Press Enter to exit! "<<std::endl;
    boost::thread_group threads;
    for (int i = 0; i < 5; ++i) {
        threads.create_thread(workerThread);
    }
    std::cin.get();
    ioService.stop();
    threads.join_all();
    return 0;
}

//shared pointer is used to manage the ownership of the worker

//Press enter to exit is displayed first

//the threads are created and the main function waits for the user to enter "ENTER"

