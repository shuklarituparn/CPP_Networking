//
// Created by rituparn on 25.07.23.
//

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>

boost::mutex global_stream_lock;
void workerThread(const boost::shared_ptr<boost::asio::io_service>& iosvc, int counter){
    global_stream_lock.lock(); //lock function locks the thread till its work is done
    std::cout<<counter<<" Counter.\n";
   global_stream_lock.unlock();

   iosvc->run(); //To start the event loop

    global_stream_lock.lock();
    std::cout<<counter<<"End. \n";
    global_stream_lock.unlock(); //if we lock here it'll not display anything as it'll wait for the thread to do the task
}

int main(){
    boost::shared_ptr<boost::asio::io_service> io_svc(new boost::asio::io_service);


    boost::shared_ptr<boost::asio::io_service::work> worker(new boost::asio::io_service::work(*io_svc));

    std::cout<<"Press Enter to exit! "<<std::endl;
    boost::thread_group threads;
    for (int i = 0; i < 5; ++i) {
        threads.create_thread(boost::bind(&workerThread, io_svc, i));
    }
    std::cin.get();
    io_svc->stop();   //to end the event loop
    threads.join_all();
    return 0;
}
