#include <iostream>

int main()
{
    int num{1};

    for(num=1;num<=7;num++)
    {
        std::cout << "NUM: " << num << " NUM2: " << (num*num) << " NUM3: " << (num*num*num) <<"\n";
    }
    //with while

    num = 1;
    while(num<=7)
    {
        std::cout << "while-Num: " << num << "\n";
        num++;
    }

    return 0;
}