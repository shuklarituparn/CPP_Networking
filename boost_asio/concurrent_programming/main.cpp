//
// Created by rituparn on 24.07.23.
//


#include <boost/chrono.hpp>
#include <boost/thread.hpp>
#include <iostream>

void Print1(){
    for (int i = 0; i < 5; ++i) {
        boost::this_thread::sleep_for(boost::chrono::milliseconds(500));
        std::cout<<"[Print1] Line: "<<i<<"\n";
    }
}

void Print2(){
    for (int i = 0; i < 5; ++i) {
        boost::this_thread::sleep_for(boost::chrono::milliseconds(500));
        std::cout<<"[Print2] Line: "<<i<<"\n";
    }
}

int main(void){
    boost::thread_group threads;
    threads.create_thread(Print1);
    threads.create_thread(Print2);
    threads.join_all();
}


/*
 * The output that we get from this progran
[Print1] Line: 0
[Print2] Line: 0
[Print1] Line: 1
[Print2] Line: 1
[Print1] Line: 2
[Print2] Line: 2
[Print1] Line: 3
[Print2] Line: 3
[Print2] Line: 4
[Print1] Line: 4

 */