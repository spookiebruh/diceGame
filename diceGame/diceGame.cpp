// diceGame.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <ctime>
using namespace std;


int main()
{
    int dicePlayer1;
    int diceCpu1;
    int dicePlayer2;
    int diceCpu2;
    int winsPlayer = 0;
    int winsCpu = 0;
    int money;
    int bet;
    int age;
    string yesNo;

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
    while (true)
    {
        cout << "How much money do you want to bet on this first game? $100, $300 or $500?" << endl;
        cin >> bet;
        if (bet == 100 || bet == 300 || bet == 500)
        {
            if (bet > money)
            {
                cout << "Please choose a number you can afford." << endl;
                continue; 
            }
            else
            {
                break;
            } 
        }
        else
        {
            cout << "Please choose $100, $300 or $500." << endl;
            continue;
        }
    }
    
    while (true)
    {
        dicePlayer1 = rand() % 6 + 1;
        dicePlayer2 = rand() % 6 + 1;

        diceCpu1 = rand() % 6 + 1;
        diceCpu2 = rand() % 6 + 1;
        cout << "You got " << dicePlayer1 + dicePlayer2 << endl;
        cout << "Computer got " << diceCpu1 + dicePlayer2 << endl;

        if (dicePlayer1 + dicePlayer2 > diceCpu1 + diceCpu2)
        {
            winsPlayer = winsPlayer++;
            cout << "You won a round! You have " << winsPlayer << " wins." << endl;

            if (winsPlayer == 2)
            {
                money = money + bet;
                cout << "You won it all! Your betted money has been doubled." << endl;
                cout << "You now have $" << money << "." << endl;
                cout << "Do you want to play again? y/n" << endl;
                cin >> yesNo;
                if (yesNo == "y" || yesNo == "Y")
                {
                    while (true)
                    {
                        cout << "How much money do you want to bet on this game? $100, $300 or $500?" << endl;
                        cin >> bet;
                        if (bet == 100 || bet == 300 || bet == 500)
                        {
                            if (bet > money)
                            {
                                cout << "Please choose a number you can afford." << endl;
                                continue; 
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                        cout << "Please choose $100, $300 or $500." << endl;
                        continue; 
                        }
                    }
                    continue;
                }
                else if (yesNo == "n" || yesNo == "N")
                {
                    break;
                }
            }
            continue;
        }
        else
        {
            winsCpu = winsCpu++;
            cout << "You lost a round. Computer has " << winsCpu << " wins." << endl;
            if (winsCpu == 2)
            {   
                money = money - bet;
                cout << "You lost it all. Your betted money has been removed." << endl;
                cout << "You now have $" << money << "." << endl;
                cout << "Do you want to play again? y/n" << endl;
                cin >> yesNo;
                if (yesNo == "y" || yesNo == "Y")
                {
                    while (true)
                    {
                        cout << "How much money do you want to bet on this game? $100, $300 or $500?" << endl;
                        cin >> bet;
                        if (bet == 100 || bet == 300 || bet == 500)
                        {
                            if (bet > money)
                            {
                                cout << "Please choose a number you can afford." << endl;
                                continue; 
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                        cout << "Please choose $100, $300 or $500." << endl;
                        continue; 
                        }
                    }
                    continue;
                }
                else if (yesNo == "n" || yesNo == "N")
                {
                    break;
                }
            }
            continue;
        }
    }
    

}


