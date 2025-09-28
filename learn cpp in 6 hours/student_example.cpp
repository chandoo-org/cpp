#include <iostream>
#include <string>

class Student {
    std::string name, courses[4];
    int id;
    bool fee_paid;
public:
    Student(){}
    Student(std::string s, int i):
        name{s}, id{i}
    {}
    void print()
    {
        std::cout <<"Student name: "<<name<<" (ID: "<<id<<")\n";
        std::cout <<"Fee: "<<(fee_paid?"PAID":"NOT PAID")<<"\n";
        std::cout <<"Courses \n";

        for(std::string c:courses)
        {
            std::cout<<c<<"\n";
        }
    }
    void setCourse(int cnum, std::string c)
    {
        courses[cnum] = c;
    }
    void payFee()
    {
        fee_paid = true;
    }
};

int main()
{
    Student s{"Srivalli", 1002};

    s.print();
    s.setCourse(0, "OOPS");
    s.setCourse(1, "DBMS");
    s.setCourse(2, "M2");
    s.payFee();
    s.print();
   
    Student mystudents[100];

/*    Student p{"Pushpa", 1003};
    p.print();
*/

/*
    std::string name, courses[4];
    int id;
    bool fee_paid;

    //Let's make student for subbarao
    name = "Subba Rao";
    id = 1001;
    fee_paid = true;
    courses[0] = "DWH";
    courses[1] = "CompDes";
    courses[2] = "AIML-101";
    courses[3] = "RDBMS-201";

    std::cout <<"Course 1: "<<courses[0];

*/

    return 0;
}