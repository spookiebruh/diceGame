
#include <iostream>
#include <ctime>
using namespace std;


int main()
{
    // Initierar alla variabler.

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

    // Ålderskontroll som avbryter programmet om man är under 18.

    cout << "Welcome to Dice Game!" << endl;
    cout << "How old are you?" << endl;
    cin >> age;
    if (age < 18)
    {
        cout << "You need to be over 18 to play this game. >:(";
        return 0;
    }

    // Insättning av pengar som inte får överskrida $5000.

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
    
    // Loop för att betta pengar på den första matchen. Man kan inte välja något annat än 100, 300 eller 500.

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
    
    // Huvudloopen för utförandet av spelet

    while (true)
    {
        dicePlayer1 = rand() % 6 + 1;
        dicePlayer2 = rand() % 6 + 1;

        diceCpu1 = rand() % 6 + 1;
        diceCpu2 = rand() % 6 + 1;

        // Här under visar jag vad spelaren och datorn fick för resultat på en runda.

        cout << "You got " << dicePlayer1 + dicePlayer2 << endl;
        cout << "Computer got " << diceCpu1 + dicePlayer2 << endl;

        /* Om spelarens resultat är högre än datorn så vinner man en runda.Då kollar den även om man vunnit en tidigare.Då dubblas ens bettade pengar och
            man blir frågad om man vill spela igen. Då går den igenom att betta pengar igen. */
        if (dicePlayer1 + dicePlayer2 > diceCpu1 + diceCpu2)
        {
            winsPlayer = winsPlayer++;
            cout << "You won a round! You have " << winsPlayer << " wins." << endl;

            if (winsPlayer == 2)
            {
                money = money + bet;
                winsPlayer = 0;
                winsCpu = 0;
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

        // Här gör koden exakt samma som över fast om man förlorar mot datorn. 

        else
        {
            winsCpu = winsCpu++;
            cout << "You lost a round. Computer has " << winsCpu << " wins." << endl;
            if (winsCpu == 2)
            {   
                money = money - bet;
                winsPlayer = 0;
                winsCpu = 0;
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


