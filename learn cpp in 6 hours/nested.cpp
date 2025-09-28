#include <iostream>
#include <cmath>

int main()
{
    int num{1};
    int temp, num_power;

    //print the number, its square, cube, 4th and 5th multiples for the first 9 numbers
    for(num=1;num<=9;num++)
    {
        num_power = 1;
        for(temp=1;temp<=5;temp++)
        {
            //std::cout << num*temp << " ";
            //num_power = num_power * num;
            //std::cout << num_power << " ";
            std::cout << pow(num, temp) << " ";
        }
        std::cout <<"\n";
    }
    
    return 0;
}