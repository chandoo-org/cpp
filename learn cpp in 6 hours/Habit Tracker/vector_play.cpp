#include <vector>
#include <iostream>
#include <string>

int main()
{
    std::vector<int> nums;

    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(9);

    for(int& x:nums)
    {
        std::cout<<"Number is "<<x<<"\n";
        x = x+1;
    }
    

    std::vector<std::string> texts;

    texts.push_back("Hello!");
    texts.push_back("Are you there?");
    texts.push_back("When are you picking up!!");
    texts.push_back("I'm waiting!!!");
    
    for(auto s:texts)
    {
        std::cout<<"Message is "<<s<<"\n";
    }

    for(int x:nums)
    {
        std::cout<<"Number is "<<x<<"\n";
    }
    return 0;
}