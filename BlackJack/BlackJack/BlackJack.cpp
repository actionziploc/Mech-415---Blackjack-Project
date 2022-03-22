// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stdio.h>     
#include <stdlib.h>  
#include <time.h>       
#include <Windows.h>
#include <mmsystem.h>
#include "Audio.h"
#include "players.h"


using namespace std;

// FUNCTION DECLARATION
pair<string, int> CardGenerator();
vector<int> previousNumbers; 
pair<string, int> CardCheck(int NumGen); 
template <typename T>
bool contains(vector<T> vec, const T& elem);
bool DealerUnder = true;

//PLAYER CLASS
class Players;

//class CardClass {
//public:
//    string name;
//    string suit;
//    int value;
//};


int main()
{
    srand(time(NULL));  //INTIALIZING SEED RANDOM
    bool hitting = true;
    int numberPlayers;
    string suit, cardCall, playerName, anotherCard;
    int player[7];

    cout << "How many players are there?" << endl;
    cin >> numberPlayers;

    //MAX PLAYER CHECK 
    while (numberPlayers > 6)
    {
        cout << "Please imput a number less than 7" << endl;
        cout << "How many players are there?" << endl;
        cin >> numberPlayers;
    }
   
    //INITIALIZE SOUND FILES
    char file[] = ("shuffling_cards.wav");
    Audio A(file);
   
    //INTIALIZING ALL PLAYER OBJECTS
    Players Player1;
    Players Player2;
    Players Player3;
    Players Player4;
    Players Player5;
    Players Player6;
    Players Dealer;


    //PLAYING DEALER
    Dealer.setName("Dealer");
    cout << "Dealer is playing" << endl;
    auto Card = CardGenerator();  
    Dealer.addCardDisplay(Card);
    Dealer.addCardNum(Card.second);
    Card = CardGenerator();
    Dealer.addCardDisplay(Card);
    Dealer.addCardNum(Card.second);
    Dealer.dealerIntDeal();

    //PLAYING CARDS FOR EACH PLAYER
    for (int i = 1; i < numberPlayers + 1; i++)
    {

        cout << "What is player " + to_string(i) + " name? ";
        cin >> playerName;

        //PLAYING SELECT EACH PLAYER
        if (i == 1) {
            Player1.setName(playerName);
            cout << playerName + " is playing" << endl;
            auto Card = CardGenerator(); //DEALING FIRST CARD
            Player1.addCardDisplay(Card); //SAVING EACH CARD
            Player1.addCardNum(Card.second); //SAVING NUMBER
            anotherCard = "Y";
            do { //DOWHILE FOR NEXT CARD
                auto Card = CardGenerator(); //GENERATE DEAL CARDS
                Player1.addCardDisplay(Card);  //SAVING ALL CARD DATA
                Player1.addCardNum(Card.second); //SAVING NUMBER
                player[i] = Player1.showNums(); //COUNTING CARD DISPLAY
                if (player[i] > 21) break; //IF OVER 21 
                cout << "Would you like another card? (Y or N)" ; //ASK FOR CARD
                cin >> anotherCard;
                cout << endl;
            } while (anotherCard == "Y"); //CONTINUE WITH YES
        }

        //REPEAT FOR EACH PLAYER
        else if (i == 2) {
            Player2.setName(playerName);
            cout << playerName + " is playing" << endl;
            auto Card = CardGenerator();
            Player2.addCardDisplay(Card);
            Player2.addCardNum(Card.second);
            anotherCard = "Y";
            do {

                auto Card = CardGenerator();
                Player2.addCardDisplay(Card);
                Player2.addCardNum(Card.second);
                player[i] = Player2.showNums();
                if (player[i] > 21) break;
                cout << "Would you like another card? (Y or N)";
                cin >> anotherCard;
                cout << endl;
            } while (anotherCard == "Y");
        }
        else if (i == 3) {
            Player3.setName(playerName);
            cout << playerName + " is playing" << endl;
            auto Card = CardGenerator();
            Player3.addCardDisplay(Card);
            Player3.addCardNum(Card.second);
            anotherCard = "Y";
            do {

                auto Card = CardGenerator();
                Player3.addCardDisplay(Card);
                Player3.addCardNum(Card.second);
                player[i] = Player3.showNums();
                if (player[i] > 21) break;
                cout << "Would you like another card? (Y or N)";
                cin >> anotherCard;
                cout << endl;
            } while (anotherCard == "Y");
        }
        else if (i == 4) {
            Player4.setName(playerName);
            cout << playerName + " is playing" << endl;
            auto Card = CardGenerator();
            Player4.addCardDisplay(Card);
            Player4.addCardNum(Card.second);
            anotherCard = "Y";
            do {

                auto Card = CardGenerator();
                Player4.addCardDisplay(Card);
                Player4.addCardNum(Card.second);
                player[i] = Player4.showNums();
                if (player[i] > 21) break;
                cout << "Would you like another card? (Y or N)";
                cin >> anotherCard;
                cout << endl;
            } while (anotherCard == "Y");
        }
        else if (i == 5) {
            Player5.setName(playerName);
            cout << playerName + " is playing" << endl;
            auto Card = CardGenerator();
            Player5.addCardDisplay(Card);
            Player5.addCardNum(Card.second);
            anotherCard = "Y";
            do {

                auto Card = CardGenerator();
                Player5.addCardDisplay(Card);
                Player5.addCardNum(Card.second);
                player[i] = Player5.showNums();
                if (player[i] > 21) break;
                cout << "Would you like another card? (Y or N)";
                cin >> anotherCard;
                cout << endl;
            } while (anotherCard == "Y");
        }
        else if (i == 6) {
            Player6.setName(playerName);
            cout << playerName + " is playing" << endl;
            auto Card = CardGenerator();
            Player6.addCardDisplay(Card);
            Player6.addCardNum(Card.second);
            anotherCard = "Y";
            do {

                auto Card = CardGenerator();
                Player6.addCardDisplay(Card);
                Player6.addCardNum(Card.second);
                player[i] = Player6.showNums();
                if (player[i] > 21) break;
                cout << "Would you like another card? (Y or N)";
                cin >> anotherCard;
                cout << endl;
            } while (anotherCard == "Y");
        }
    }
    //DEALING WITH THE DEALER
    player[0] = Dealer.calculate();
    //HIT WHILE UNDER 16
    while (player[0] < 16) {
        cout << endl  << "Dealer being dealt another card " << endl <<endl;
        auto Card = CardGenerator();
        Dealer.addCardDisplay(Card);
        Dealer.addCardNum(Card.second);
        player[0] = Dealer.calculate();
    }
    //CHECK EACH PLAYER VERSUS DEALER
    for (int i = 1; i < numberPlayers+1; i++)
    {
        cout << endl << endl;
        switch (i)  //SWITCH FOR EACH PLAYER
        {
        case 1: //CASE IS PLAYER 1
            if ((player[0] < player[i] || !DealerUnder) && player[i] <= 21) { //PLAYER OVER DEALER AND DEALER UNDER 21 AND PLAYER UNDER 21
                cout << Player1.getName() << " has won"; //PLAYER 1 WON WITH NAME
            } else cout << Player1.getName() << " has lost"; //PLAYER 1 LOST WITH NAME
            break;
        case 2:
            if ((player[0] < player[i] || !DealerUnder) && player[i] <= 21) {
                cout << Player2.getName() << " has won";
            }
            else cout << Player2.getName() << " has lost";
            break;
        case 3:
            if ((player[0] < player[i] || !DealerUnder) && player[i] <= 21) {
                cout << Player3.getName() << " has won";
            }
            else cout << Player3.getName() << " has lost";
            break;
        case 4:
            if ((player[0] < player[i] || !DealerUnder) && player[i] <= 21) {
                cout << Player4.getName() << " has won";
            }
            else cout << Player4.getName() << " has lost";
            break;
        case 5:
            if ((player[0] < player[i] || !DealerUnder) && player[i] <= 21) {
                cout << Player5.getName() << " has won";
            }
            else cout << Player5.getName() << " has lost";
            break;
        case 6:
            if ((player[0] < player[i] || !DealerUnder) && player[i] <= 21) {
                cout << Player6.getName() << " has won";
            }
            else cout << Player6.getName() << " has lost";
            break;
        }
    }
    cout << endl << endl;
}



pair<string, int> CardGenerator() {
    int NumGen;
    bool Looping;
    NumGen = rand() % 52 + 1;  //GENERATING NUMBER AND FINDING NUMBER BETWEEN 1 AND 52
    Looping = true;
    while (Looping)
    {
        if (contains(previousNumbers, NumGen)) //CHECK IF NUMGENERATED ABOVEHAD ALREADY BEEN GENERATED AND IS IN LIST
        {
            NumGen = rand() % 52 + 1; //IF ALREADY GENERATED DO IT AGAIN
        }
        else
        {
            Looping = false; //IF NOT LEAVE LOOP
        }
    }
    previousNumbers.push_back(NumGen);  //ADD TO PREVIOUS NUMBER LIST
    auto Card = CardCheck(NumGen); //CHECK CARD
    return Card; //RETURN CARD
}

template <typename T>
bool contains(vector<T> vec, const T& elem)
{
    bool result = false; 
    if (find(vec.begin(), vec.end(), elem) != vec.end()) // CHECK IF CARD IS FOUND IN THE VECTOR
    {
        result = true;
    }
    return result;
}

//SABVING EACH TYPE OF CARD
pair<string, int> CardCheck(int NumGen) {
    pair<string, int> result;
    //SAVING SUIT
    if (NumGen <= 13) {
        result.first = "Heart";
    }
    else if (13 < NumGen && NumGen <= 26) {
        result.first = "Diamond";
    }
    else if (26 < NumGen && NumGen <= 39) {
        result.first = "Spade";
    }
    else {
        result.first = "Club";
    }
    //SAVING CARD NUMBER
    result.second = NumGen % 13 + 1;
    return result;
}


class Players {
private:
    string name;
    vector<pair<string, int>> cardDisplay;
    vector<int> cardNum;
    int total;
public:
    //CONSTRUCTOR PLAYERS NAME SAVE
    Players(string n) {
        name = n;
    }
    Players() {
        name = "";
    }
    //SETTING NAME AFTER
    void setName(string n) {
        name = n;
    }
    //GETTING NAME
    string getName() { return name; }
    //ADDING CARD TO VECTOR
    void addCardDisplay(pair<string, int> d) {
        cardDisplay.push_back(d);
    }
    //SAVING CARD BUT REPLACING NUMBER TO VALUE
    //_____________________MAYBE THIS IS WHERE WE ADD AND PULL NUMBER FOR DSIPLAY__________________________
    void addCardNum(int num) {
        if (num == 1)
        {
            num = 11;
        }
        else if (num > 10) {
            num = 10;
        }
        cardNum.push_back(num);
    }
    //DEALER FACEDOWN
    void dealerIntDeal() {
        cout << endl << endl << "Dealer's Cards are" << endl;
        cout << "FACEDOWN ";
        for (auto it = begin(cardNum) + 1; it != end(cardNum); ++it) {
            cout << *it << " " << endl << endl;
        }
    }

    //CALCULATE CARD TOTAL
    int calculate() {
        int caltotal = 0;
        cout << "Here are the dealers current cards ";
        for (int num : cardNum) {
            cout << num << " ";
            caltotal = num + caltotal;
        }
        total = caltotal;
        cout << endl << "Dealer has : " << to_string(caltotal) << endl;
        if (caltotal > 21) {
            for (int num : cardNum) {
                if (num == 11) {
                    cout << endl << "Changing the ace to a 1: " << endl;
                    replace(cardNum.begin(), cardNum.end(), 11, 1);
                    int caltotal = 0;
                    cout << "Here are the dealers current cards ";
                    for (int num : cardNum) {
                        cout << num << " ";
                        caltotal = num + caltotal;
                    }
                    total = caltotal;
                    cout << endl << "Dealer has : " << to_string(caltotal) << endl;
                    return total;
                    break;
                }
            }
            cout << "Dealer went over";
            DealerUnder = false;
            return total;
        }
        else return total;
    }
    //SHOWING NUMBERS AND REPLACING 11 TO 1 IF ACE IN HAND
    int showNums() {
        int caltotal = 0;
        cout << "Here are your current cards ";
        for (int num : cardNum) {
            cout << num << " ";
            caltotal = num + caltotal;
        }
        total = caltotal;
        cout << endl << "Totalling: " << to_string(caltotal) << endl;
        if (caltotal > 21) {
            for (int num : cardNum) {
                if (num == 11) {
                    cout << endl << "Changing your ace to a 1: " << endl;
                    replace(cardNum.begin(), cardNum.end(), 11, 1);

                    int caltotal = 0;
                    cout << "Here are your current cards ";
                    for (int num : cardNum) {
                        cout << num << " ";
                        caltotal = num + caltotal;
                    }
                    total = caltotal;
                    cout << endl << "Totalling: " << to_string(caltotal) << endl;

                    return total;
                    break;
                }
            }
            cout << "You lost" << endl << endl;
            return total;
        }
        else return total;
    }
};




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
