//
// Created by rituparn on 29.07.23.
//
#include <iostream>
#include <functional>

void max(int a,int b,int c)//used to find the maximum of all three elements
{

    if (a > b && a > c)
    {
        std::cout << a<<" is the largest"<<std::endl;
    }
    else if (b > a && b > c)
    {
        std::cout << b << " is the largest " << std::endl;
    }
    else
    {
        std::cout << c << " is the largest" << std::endl;
    }

}
int main()
{
    int x, y, z;
    std::cout << "enter 3 numbers " << std::endl;
    std::cin >> x >> y >> z;


    const auto f=(std::bind(&max, std::placeholders::_1, std::placeholders::_2,std::placeholders::_3));//_1,_2,_3 are the placeholders and contains the value x,y,z respectively and all these variables are binded with the function max
    f(x, y, z);
    return 0;

}
