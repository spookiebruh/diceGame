// diceGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>;
using namespace std;


int main()
{
    int dice1;
    int dice2;
    int money;
    int age;

    cout << "Welcome to Dice Game!" << endl;
    cout << "How old are you?" << endl;
    cin >> age;
    if (age < 18)
    {
        cout << "You need to be over 18 to play this game. >:(";
        return 0;
    }

    srand(time(0));
    dice1 = rand() % 6 + 1;

    cout << dice1;
    
}


