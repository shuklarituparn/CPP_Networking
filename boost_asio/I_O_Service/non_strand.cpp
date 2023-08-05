//
// Created by rituparn on 05.08.23.
//

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include<boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>

boost::mutex global_stream_lock;

void WorkerThread(boost::shared_ptr<boost::asio::io_service> iosvc, int counter){
    global_stream_lock.lock();
    std::cout<<"Thread "<<counter<<"Start. \n";
    global_stream_lock.unlock();

    iosvc->run();   //commenting out this would stop the print function from being executed

    global_stream_lock.lock();
    std::cout<<"Thread "<<counter<<"End. \n";
    global_stream_lock.unlock();

}

void print(int  number){
    std::cout<<"Number: "<<number<<std::endl;
}

int main(){
    boost::shared_ptr<boost::asio::io_service> io_svc (new boost::asio::io_service );
    boost::shared_ptr<boost::asio::io_service::work> worker (new boost::asio::io_service::work(*io_svc));

    global_stream_lock.lock();
    std::cout<<"The program will exit once the work is done. \n";
    global_stream_lock.unlock();

    boost::thread_group threads;
    for (int i = 0; i < 5; ++i) {
        threads.create_thread(boost::bind(&WorkerThread, io_svc, i));
    }
    boost::this_thread::sleep(boost::posix_time::milliseconds(500));
    io_svc->post(boost::bind(&print, 1));
    io_svc->post(boost::bind(&print, 2));
    io_svc->post(boost::bind(&print, 3));
    io_svc->post(boost::bind(&print, 4));
    io_svc->post(boost::bind(&print, 5));

    worker.reset();
    threads.join_all();
    return 0;
}