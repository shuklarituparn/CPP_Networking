//
// Created by rituparn on 23.07.23.
//


#include <iostream>
#include <algorithm>
#include <vector>

int main(void){
    int temp;
    std::vector<int> collection;
    std::cout<<"enter the integers (0 to stop): "<<std::endl;

    while (std::cin>>temp){
        if(temp==0)
            break;
        collection.push_back(temp);
    }

    std::sort(collection.begin(), collection.end());
    std::cout<<"The sorted collection is: \n";
    for (auto i:collection) {
        std::cout<<i<<std::endl;

    }


}