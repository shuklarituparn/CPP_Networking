//
// Created by rituparn on 24.07.23.
//

#include <iostream>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/bind/bind.hpp>




void workerThread(const boost::shared_ptr<boost::asio::io_service>& iosvc, int counter){  //takes an ioservice shared pointer and an integer counter
   std::cout<<"Counter "<<".\n";
   iosvc->run();
   std::cout<<"End. \n";
}

int main(){
    boost::shared_ptr<boost::asio::io_service> io_svc(new boost::asio::io_service); //shared pointer to manage the io_service

    //initiate the io_service object in the shared_ptr to make it copyable to the workerThread function
    boost::shared_ptr<boost::asio::io_service::work> worker(new boost::asio::io_service::work(*io_svc)); //helps exiting early

    std::cout<<"Press Enter to exit! "<<std::endl;
    boost::thread_group threads;
    for (int i = 0; i < 5; ++i) {
        threads.create_thread(boost::bind(&workerThread, io_svc, i));
    }
    std::cin.get();
    io_svc->stop();
    threads.join_all();
    return 0;
}

//shared pointer is used to manage the ownership of the worker

//Press enter to exit is displayed first

//the threads are created and the main function waits for the user to enter "ENTER"

