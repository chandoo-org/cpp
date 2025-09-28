#include <iostream>
#include <string>
#include <cmath>

int main()
{
    std::string names[5];
    int expenses[5], totalExp{0};
    float avgExp;

    std::cout <<"---------------------------\n";
    std::cout <<"WELCOME TO EXPENSE SPLITTER\n";
    std::cout <<"---------------------------\n";

    for(int i=1;i<=5;i++)
    {
        std::cout <<"Enter person "<<i<<"'s name: ";
        std::cin >> names[i-1];
        std::cout <<"How much "<<names[i-1]<<" spent? ";
        std::cin >> expenses[i-1];
        totalExp += expenses[i-1];
    }
    avgExp = totalExp / 5;
    
    // printing outputs:
    std::cout <<"\n\n\n---------------------------\n";
    std::cout <<"EXPENSE SPLIT!\n";
    std::cout <<"---------------------------\n";
    std::cout <<"Total spent: "<<totalExp<<", per person: "<<avgExp <<"\n";

    for(int i=1;i<=5;i++)
    {
        float toPay = avgExp - expenses[i-1];

        std::cout <<names[i-1];
        if (toPay<0)
            std::cout << " to get " << abs(toPay);
        else if (toPay>0)
            std::cout << " to pay " << toPay;
        else
            std::cout <<" is all good!";
        std::cout <<"\n";
    }
}