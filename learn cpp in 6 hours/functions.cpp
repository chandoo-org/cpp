#include <iostream>
#include <string>

void doubleIt(int& thisNum){
    thisNum = thisNum*2;
    std::cout<<"Doubled in function: "<<thisNum <<"\n";
}
void doubleIt(double& thisNum){
    thisNum = thisNum*2;
}

void doubleIt(std::string& thisTxt){
    thisTxt.append(thisTxt);
}

int main()
{
    int x{23};
    double num{12.9};
    std::string name{"Subba"};

    std::cout<<"Before x: "<<x<<"\n";
    doubleIt(x);
    std::cout<<"After x: "<<x<<"\n";
    
    std::cout<<"Before num: "<<num<<"\n";
    doubleIt(num);
    std::cout<<"After num: "<<num<<"\n";

    std::cout<<"Before name: "<<name<<"\n";
    doubleIt(name);
    std::cout<<"After name: "<<name<<"\n";

    return 0;
}