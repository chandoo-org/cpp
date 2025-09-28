std::vector<habit> myHabits;

    habit temp{"Drink Water", "Health"};

    myHabits.push_back(temp);

    temp =  habit{"Go for jog", "Health"};
    myHabits.push_back(temp);

    temp =  habit{"Code for an hour everyday", "Mind"};
    myHabits.push_back(temp);

    for(habit& x:myHabits)
    {
        x.printHabit();
        x.trackHabit();
    }
    std::cout <<"----------------------\n";
    
    std::cout <<"After tracking all the habits once \n";

    for(habit x:myHabits)
    {
        x.printHabit();
    }