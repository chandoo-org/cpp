#include <iostream>

int main()
{
    int marks, att;
    // letter grade caluclation:
    /*  Marks <40 or attendance under 60 = F
        Marks > 85 and attendance above 80 = A
        Marks > 70 and attendance above 60 = B
        Marks > 50 and attendance above 60 = C
        Marks > 40 and attendace above 60 = D
    */
    std::cout <<"How many marks did you get? ";
    std::cin >> marks;
    
    std::cout <<"What is your attendance? ";
    std::cin >> att;

    char letterGrade;

    if(marks<40 ||att<60)
        letterGrade = 'F';
    else if(marks>85 && att>80)
        letterGrade = 'A';
    else if (marks >70)
        letterGrade = 'B';
    else if (marks>50)
        letterGrade = 'C';
    else
        letterGrade = 'D';

    std::cout << "You got the grade " << letterGrade <<"\n";
    

    
    /*
    if (marks>85)
        letterGrade = 'A';
    else if (marks >70)
        letterGrade = 'B';
    else if (marks >50)
        letterGrade = 'C';
    else if (marks >40)
        letterGrade = 'D';
    else
        letterGrade = 'F';
    */
    //std::cout << "You got the grade " << letterGrade <<"\n";

    return 0;
}