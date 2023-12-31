#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>
boost::mutex global_stream_lock;
void WorkerThread(boost::shared_ptr<boost::asio::io_service>iosvc, int counter) {
    global_stream_lock.lock();
    std::cout << "Thread " << counter << " Start.\n";
    global_stream_lock.unlock();
    try {
        iosvc->run();
        global_stream_lock.lock();
        std::cout << "Thread " << counter << " End.\n";
        global_stream_lock.unlock();
    }
    catch (std::exception &ex) {
        global_stream_lock.lock();
        std::cout << "Message: " << ex.what() << ".\n";
        global_stream_lock.unlock();
    }
}

void ThrowAnException(boost::shared_ptr<boost::asio::io_service> iosvc, int counter){
    global_stream_lock.lock();
    std::cout<<"Throw Exception: "<<counter<<"\n";
    global_stream_lock.unlock();
    throw(std::runtime_error("The Exception !!!"));
}
int main(void) {
    boost::shared_ptr<boost::asio::io_service> io_svc(new boost::asio::io_service);
    boost::shared_ptr<boost::asio::io_service::work> worker(new boost::asio::io_service::work(*io_svc));
    global_stream_lock.lock();
    std::cout << "The program will exit once all work has finished.\n";
    global_stream_lock.unlock();
    boost::thread_group threads;
    for(int i=1; i<=2; i++)
        threads.create_thread(boost::bind(&WorkerThread, io_svc, i));
    io_svc->post(boost::bind(&ThrowAnException, io_svc, 1));
    io_svc->post(boost::bind(&ThrowAnException, io_svc, 2));
    io_svc->post(boost::bind(&ThrowAnException, io_svc, 3));
    io_svc->post(boost::bind(&ThrowAnException, io_svc, 4));
    io_svc->post(boost::bind(&ThrowAnException, io_svc, 5));
    threads.join_all();
    return 0;
}