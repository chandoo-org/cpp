#include <iostream>
#include <string>

std::string operator +(std::string s1, std::string s2)
{
    std::string retVal{s1};
    retVal.append(" ");
    retVal.append(s2);

    return retVal;
}

std::string operator --(std::string s1)
{
    //overloaded -- operator on strings to calculate the initials or first letter of words
    std::string retVal;
    char prevChar{' '};

    for(char c:s1)
    {
        if (prevChar==' ')
        {
            retVal.push_back(c);
        }
        prevChar = c;
    }

    return retVal;

}

int main()
{
    std::string fName{"Venkata Narayana"}, lName{"Burra"};

    std::string fullName = lName + fName;

    std::cout << fullName<<"\n";

    int a{3};

    a++;
  
    std::cout << --fullName <<"\n";

    return 0;
}