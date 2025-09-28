#include <iostream>

void printThermo(int t);

int main()
{
    int temp;
    std::cout <<"What is the temperature? ";
    std::cin >> temp;

    printThermo(temp);

    int temps[5];

    std::cout << "Enter temperatures for next 5 days: ";
    std::cin >> temps[0] >> temps[1]>> temps[2]>> temps[3]>> temps[4];
    
    for(int i = 0;i<5;i++)
        printThermo(temps[i]);
    

    return 0;
}


void printThermo(int t)
{
    // BOX SYMBOLS: ▮▯ 
    // Emojis: 🥶☺️🥵
    for(int i = 1;i<=50;i++)
        std::cout << ((i<=t)?"▮":"▯");
    if (t<=18)
        std::cout <<" 🥶";
    else if (t<27)
        std::cout <<" ☺️";
    else
        std::cout <<" 🥵";
    std::cout <<"\n";
}