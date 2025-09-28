#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class habit {
private:
    std::string title;
    std::string category;
    int habit_count;

public:
    habit(std::string h, std::string c)
        :title{h}, category{c}, habit_count{0}
    { std::cout <<"new habit with "<<title<<" in "<<category<<" created!\n"; }
    habit(std::string h)
        :title{h}, category{"other"}, habit_count{0}
    { std::cout <<"new habit with "<<title<<" in default(other) category created!\n"; }
    habit()
    {}
    habit(std::string h, std::string c, int count)
        :title{h}, category{c}, habit_count{count}
    {}

    void setHabit(std::string h, std::string c)
    {
        title = h;
        category = c;
    }
    std::string getHabit()
    {
        return title;
    }
    void trackHabit()
    {
        habit_count++;
    }
    void printHabit()
    {
        std::cout<<title<<" ("<<category<<"): "<<habit_count<<" times.\n";
    }

    std::string printHabitForFile()
    {
        std::string retval;

        retval.append(title);
        retval.append("\n");
        retval.append(category);
        retval.append("\n");
        retval.append(std::to_string(habit_count));
        retval.append("\n");

        return retval;
    }

    habit& operator++(int)
    {
        habit_count++;

        return *this;
    }

};

class habit_tracker
{
    //this class contains habit(s) and all the necessary functions for dealing with them
private:
    std::vector<habit> myHabits;
public:
    habit_tracker() {}
    void addHabit(std::string h, std::string c){
        habit newHabit{h,c};
        myHabits.push_back(newHabit);
    }
    void addHabit(std::string h){
        habit newHabit{h};
        myHabits.push_back(newHabit);
    }
    habit& getHabit(int pos){
        return myHabits[pos];
    }

    habit& operator [](int index){
        return myHabits[index];
    }
    
    void saveHabits(std::string fileName){
        std::ofstream myfile{fileName};

        if (!myfile)
        {
           // file could not be created or opened
           std::cerr <<  "Problem with the file "<<fileName<<". Cannot open it. \n";
           return;
        }
        for(habit h:myHabits){
            myfile << h.printHabitForFile();
        }        
        myfile.close();
    }

    int loadHabits(std::string fileName)
    {
        std::ifstream myfile(fileName);

        if(!myfile)
        {
            //file could not be opened
            std::cerr <<  "Problem with the file "<<fileName<<". Cannot open it. \n";
            return -1;
        }

        std::string line{};
        std::string h, c;
        int count, lineNum{0};

        while(std::getline(myfile, line))
        {
            int t = lineNum % 3;

            switch (t)
            {
            case 0:
                /* code */
                h = line;
                break;
            case 1:
                c = line;
                break;
            default:
                count = std::stoi(line);
                habit newH{h,c,count};

                myHabits.push_back(newH);
                break;
            }
            lineNum++;
        }
        myfile.close();
        return 0;
    }
    
    void printHabits()
    {
        //prints all the habits on the screen in a neat format
        int lNum{1};

        for(habit h:myHabits){
            std::cout<<lNum++<<". ";
            h.printHabit();
        }
    }
    int size()
    {
        return myHabits.size();
    }
};

void clearScreen();

int showMainMenu()
{
    clearScreen();
    
    std::cout<<YELLOW<<"\n\nWELCOME TO HABIT TRACKER\n";
    
    std::cout<<"------------------------------\n";
    std::cout<<"  (1). Add a Habit\n";
    std::cout<<"  (2). Track a Habit\n";
    std::cout<<"  (3). Show Habits\n";
    std::cout<<"\n" << std::endl;
    std::cout<<CYAN<<"  (9). QUIT\n" <<std::endl;
    std::cout<<YELLOW<<"------------------------------\n\n\n";
    std::cout <<RESET<<std::endl;
    std::cout<<"Enter your choice: ";
   
    int choice{9};

    std::cin >> choice;

    return choice;
}

void clearScreen() {
#ifdef _WIN32 // Check if compiling on Windows
    system("cls"); // Windows clear screen command
#else // Assume Unix-like system
    system("clear"); // Unix-like clear screen command
#endif
}

void addHabitScreen(habit_tracker& ht)
{
    // adds a new habit to the given habit tracker. 
    // Function exits when the user no longer wants to add habits
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush the buffer
    clearScreen();
    std::cout<<"\n\nADD HABIT SCREEN\n";
    std::cout <<"Type 0 any time to go back to MAIN MENU\n";
    std::cout <<"------------------------------\n\n"<<std::endl;

    
    
    std::string h{}, c;
    
    while(h!="0")
    {
        std::cout<<"Enter the habit (or type 0 to go back): ";

        std::getline(std::cin, h); //read a line of input to h
        if(h=="0" || h.size()==0)
            break;
        std::cout<<"Enter the habit category: ";
        std::getline(std::cin, c); //read a line of input to h

        //let's add the habit to the ht

        ht.addHabit(h,c);
    }
    return;

}

void trackHabitScreen(habit_tracker &ht)
{
    //tracks a habit from all the habits in the given habit tracker
    
    int hNum{-1};
    std::string msg{""};

    while(hNum!=0)
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush the buffer
        clearScreen();
        std::cout<<YELLOW<<"\n\nTRACK HABIT SCREEN\n";
        std::cout <<"Type 0 any time to go back to MAIN MENU\n";
        std::cout <<"------------------------------\n\n"<<RESET<<std::endl;
        
        ht.printHabits();
        if (msg!="")
        {
            std::cout<<GREEN<<msg<<RESET<<std::endl;
            msg = "";
        }
        
        std::cout<<YELLOW<<"Which habit have you done today? ";
        std::cin >> hNum;
        if (hNum>=1 && hNum<=ht.size())
        {
            //this is valid habit number, let's track it.
            ht[hNum-1]++; //why is this hNum-1, not hNum? think!
            msg = "Habit [" + (ht[hNum-1].getHabit()) + "] tracked successfully!";
        }
        else if (hNum!=0)
        {
            //invalid choice. Set message and continue
            msg = "Incorrect Choice. Try again!";
        }
    }

}

void showHabitScreen(habit_tracker &ht)
{
    //shows all habits in the given habit tracker
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush the buffer
    clearScreen();
    std::cout<<YELLOW<<"\n\nSHOW HABIT SCREEN\n";
    
    std::cout <<"------------------------------\n\n"<<RESET<<std::endl;
    
    ht.printHabits();
    
    std::cout <<"------------------------------\n\n"<<RESET<<std::endl;
    std::cout <<"Type 0 to go back to MAIN MENU\n";
    
    char ch;

    std::cin >> ch;
    return;

}

int main()
{
    habit_tracker h;

    int status{-1};

    //try to load the habits from myhabits.txt in the current folder
    status = h.loadHabits("myhabits.txt");
    
    if (status==-1)
    {
        std::cerr <<"No myhabits file found. Will create one when the program terminates.";
    }
    
    int c{0};

    while(c!=9)
    {

        c = showMainMenu();
        std::cout <<"You have selected "<<c<<"\n";

        switch (c)
        {
        case 1:
            // call Add Habit Input Screen
            addHabitScreen(h);
            break;
        case 2:
            // call track habit screen
            trackHabitScreen(h);
            break;
        case 3: 
            // call show habit screen
            showHabitScreen(h);
            break;
        case 9:
            // User selected to exit the program. Save the habits to file.
            h.saveHabits("myhabits.txt");
            break;
        default:
            // some other unknown option selected. Just ignore and show main menu again.
            break;
        }
    }
    return 0;
    
}