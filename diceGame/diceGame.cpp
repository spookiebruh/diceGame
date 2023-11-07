// diceGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>;
using namespace std;


int main()
{
    int dicePlayer1;
    int diceCpu1;
    int dicePlayer2;
    int diceCpu2;
    int money;
    int age;

    srand(time(0));

    cout << "Welcome to Dice Game!" << endl;
    cout << "How old are you?" << endl;
    cin >> age;
    if (age < 18)
    {
        cout << "You need to be over 18 to play this game. >:(";
        return 0;
    }

    while (true)
    {
        cout << "How much money do you want to insert?" << endl;
        cin >> money;
        if (money > 5000)
        {
            cout << "Don't insert more than $5000, it's bad for your personal economy. Insert money." << endl;
            cin >> money;
        }
        break;
    }
    
    cout << "$" << money << endl;
    

    dicePlayer1 = rand() % 6 + 1;
    dicePlayer2 = rand() % 6 + 1;
    
    diceCpu1 = rand() % 6 + 1;
    diceCpu2 = rand() % 6 + 1;
    cout << "You got " << dicePlayer1 + dicePlayer2 << endl;
    cout << "Computer got " << diceCpu1 + dicePlayer2 << endl;

    if (dicePlayer1+dicePlayer2 > diceCpu1+diceCpu2)
    {
        cout << "You won!";
    }
    else
    {
        cout << "You lost.";
    }
}


