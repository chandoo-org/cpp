#include <iostream>

int main()
{
    float degrees, f_temp;
    
    std::cout <<"What is the temperatature in C? ";
    std::cin >> degrees;

    f_temp = (degrees * 9/5) + 32;
    std::cout << "Current temperature is " << degrees <<"C." << "\n";
    std::cout << "Temperature in F is " << f_temp <<"F."<< "\n";

    return 0;
}