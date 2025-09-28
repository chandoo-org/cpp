#include <iostream>

int main()
{
    // this is a simple bot. It asks for your name and temperature. 
    // then it will great you
    std::string name;
    float degrees, f_temp;

    std::cout << "Welcome. My name is Chitti, the bot\n" ;
    std::cout <<"What is your name? ";
    std::cin >> name;
    std::cout << "How hot is it today? ";
    std::cin >> degrees;

    f_temp = (degrees * 9/5) + 32;
    
    std::cout<<"Hello "<<name<<"\n";
    std::cout << "Current temperature is " << degrees <<"C." << "\n";
    std::cout << "Temperature in F is " << f_temp <<"F."<< "\n";

    if (degrees <30)
    {
        //what to do if the temperature is under 30
        std::cout << "abba 🥶, challaga vundey...\n";
    }
    else
    {
        //what to do if the temperature is more than 30
        std::cout << "baboi 😲, vediga vundey...\n";
    }
    return 0;
}