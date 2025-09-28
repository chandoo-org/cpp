#include <iostream>
#include <fstream>

int main()
{
    std::ofstream myfile{"sample-file.txt"};

    std::cout <<"Writing the lines to the file \n";

    myfile << "Hello Bagunnara?\n";
    myfile << "Mee C++ journey ela jaruguthondi?\n";
    
    myfile.close();

    std::ifstream myfile2{"another-file.txt"};

    std::string fileContent{};

    while(std::getline(myfile2, fileContent))
        std::cout << fileContent <<"\n";
    

    return 0;
}