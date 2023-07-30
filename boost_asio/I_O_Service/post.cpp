//
// Created by rituparn on 30.07.23.
//
//post function is used to queue all the work of the io_svc object instead of just executing it

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>


boost::mutex global_stream_lock; //creating a global mutex object
void WorkerThread(boost::shared_ptr<boost::asio::io_service> iosvc, int counter) { //worker thread that'll get executed everytime

    global_stream_lock.lock();
    std::cout << counter << ".\n";
    global_stream_lock.unlock();

    iosvc->run();

    global_stream_lock.lock();
    std::cout << "End.\n";
    global_stream_lock.unlock();
}
size_t fac(size_t n) {   //calculating factorial recursively
    if ( n <= 1 ) {
        return n;
    }
    boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
    return n * fac(n - 1);
}
void CalculateFactorial(size_t n) {
    global_stream_lock.lock();
    std::cout << "Calculating " << n << "! factorial" << std::endl;
    global_stream_lock.unlock();
    size_t f = fac(n);

    global_stream_lock.lock();
    std::cout << n << "! = " << f << std::endl;
    global_stream_lock.unlock();
}
int main(void) {
    boost::shared_ptr<boost::asio::io_service> io_svc(new boost::asio::io_service);

    boost::shared_ptr<boost::asio::io_service::work> worker(new boost::asio::io_service::work(*io_svc));
    global_stream_lock.lock();
    std::cout << "The program will exit once all work has finished."<< std::endl;
    global_stream_lock.unlock();
    boost::thread_group threads;
    for(int i=1; i<=5; i++){
        threads.create_thread(boost::bind(&WorkerThread, io_svc, i));
    }

    io_svc->post(boost::bind(CalculateFactorial, 5)); //to gather all the work for the thread
    io_svc->post(boost::bind(CalculateFactorial, 6));
    io_svc->post(boost::bind(CalculateFactorial, 7));
    worker.reset();  //to signal that the work is finished
    threads.join_all();  //joining all the work together
    return 0;
}