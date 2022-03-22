// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>     
#include <stdlib.h>  
#include <time.h>       

#include <Windows.h> 
#include <mmsystem.h>
#include "2D_graphics.h"
#include "timer.h"
#include "Audio.h"


using namespace std;

// FUNCTION DECLARATION
void DisplayName(string playerName, int i, int numberPlayers);
pair<string, int> CardGenerator();
vector<int> previousNumbers;
pair<string, int> CardCheck(int NumGen);
template <typename T>
bool contains(vector<T> vec, const T& elem);
bool DealerUnder = true;

//PLAYER CLASS
class Player {
private:
    string name;
    vector<pair<string, int>> cardDisplay;
    vector<int> cardNum;
    int total;
public:
    //CONSTRUCTOR PLAYERS NAME SAVE
    Player(string n) {
        name = n;
    }
    Player() {
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



int main()
{
    //INTIALIZE GRAPHICS
    initialize_graphics();
    clear();

    //Intializing All Cards

    int I[52 + 1];

    //Facedown
    create_sprite("facedown.png", I[0]);

    //Hearts
    create_sprite("ace_of_hearts.png", I[1]);
    create_sprite("2_of_hearts.png", I[2]);
    create_sprite("3_of_hearts.png", I[3]);
    create_sprite("4_of_hearts.png", I[4]);
    create_sprite("5_of_hearts.png", I[5]);
    create_sprite("6_of_hearts.png", I[6]);
    create_sprite("7_of_hearts.png", I[7]);
    create_sprite("8_of_hearts.png", I[8]);
    create_sprite("9_of_hearts.png", I[9]);
    create_sprite("10_of_hearts.png", I[10]);
    create_sprite("jack_of_hearts.png", I[11]);
    create_sprite("queen_of_hearts.png", I[12]);
    create_sprite("king_of_hearts.png", I[13]);

    //Diamonds
    create_sprite("ace_of_diamonds.png", I[14]);
    create_sprite("2_of_diamonds.png", I[15]);
    create_sprite("3_of_diamonds.png", I[16]);
    create_sprite("4_of_diamonds.png", I[17]);
    create_sprite("5_of_diamonds.png", I[18]);
    create_sprite("6_of_diamonds.png", I[19]);
    create_sprite("7_of_diamonds.png", I[20]);
    create_sprite("8_of_diamonds.png", I[21]);
    create_sprite("9_of_diamonds.png", I[22]);
    create_sprite("10_of_diamonds.png", I[23]);
    create_sprite("jack_of_diamonds.png", I[24]);
    create_sprite("queen_of_diamonds.png", I[25]);
    create_sprite("king_of_diamonds.png", I[26]);

    //Clubs
    create_sprite("ace_of_clubs.png", I[27]);
    create_sprite("2_of_clubs.png", I[28]);
    create_sprite("3_of_clubs.png", I[29]);
    create_sprite("4_of_clubs.png", I[30]);
    create_sprite("5_of_clubs.png", I[31]);
    create_sprite("6_of_clubs.png", I[32]);
    create_sprite("7_of_clubs.png", I[33]);
    create_sprite("8_of_clubs.png", I[34]);
    create_sprite("9_of_clubs.png", I[35]);
    create_sprite("10_of_clubs.png", I[36]);
    create_sprite("jack_of_clubs.png", I[37]);
    create_sprite("queen_of_clubs.png", I[38]);
    create_sprite("king_of_clubs.png", I[39]);

    //Spades
    create_sprite("ace_of_spades.png", I[40]);
    create_sprite("2_of_spades.png", I[41]);
    create_sprite("3_of_spades.png", I[42]);
    create_sprite("4_of_spades.png", I[43]);
    create_sprite("5_of_spades.png", I[44]);
    create_sprite("6_of_spades.png", I[45]);
    create_sprite("7_of_spades.png", I[46]);
    create_sprite("8_of_spades.png", I[47]);
    create_sprite("9_of_spades.png", I[48]);
    create_sprite("10_of_spades.png", I[49]);
    create_sprite("jack_of_spades.png", I[50]);
    create_sprite("queen_of_spades.png", I[51]);
    create_sprite("king_of_spades.png", I[52]);

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

    //INTIALIZING ALL PLAYER OBJECTS
    Player Player1;
    Player Player2;
    Player Player3;
    Player Player4;
    Player Player5;
    Player Player6;
    Player Dealer;

    //SOUNDS
    char file[] = ("whip-whoosh-02.wav");           //CARD HIT SOUND
    Audio A(file);

    char fileb[] = ("shuffling_cards.wav");         //SHUFFLE SOUND
    Audio B(fileb);

    char filed[] = ("fireworks_3.wav");             //WIN SOUND
    Audio D(filed);
    char filee[] = ("fireworks_22.wav");            //WIN SOUND
    Audio E(filee);
    char filef[] = ("fireworks_1.wav");             //WIN SOUND
    Audio F(filef);

    char fileg[] = ("fail-buzzer-03.wav");          //LOSS SOUND
    Audio G(fileg);

    char filel[] = ("fail_trombone.wav");
    Audio L(filel);



    //PLAYING DEALER
    Dealer.setName("Dealer");
    cout << "Dealer is playing" << endl;
    B.play();
    Sleep(2000);

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

        //______PRINT NAME_______
        DisplayName(playerName, i, numberPlayers);


        //PLAYING SELECT EACH PLAYER
        if (i == 1) {
            Player1.setName(playerName);
            cout << playerName + " is playing" << endl;
            B.play();                                   //SHUFFLE SOUND
            Sleep(2000);                            
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
                cout << "Would you like another card? (Y or N)"; //ASK FOR CARD
                cin >> anotherCard;
                A.play();                                   //CARD HIT SOUND
                Sleep(1500);
                cout << endl;
                B.play();                                   //SHUFFLE SOUND
                Sleep(2000);
            } while (anotherCard == "Y"); //CONTINUE WITH YES
        }

        //REPEAT FOR EACH PLAYER
        else if (i == 2) {
            Player2.setName(playerName);
            cout << playerName + " is playing" << endl;
            B.play();                                   //SHUFFLE SOUND
            Sleep(2000);
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
                A.play();                                   //CARD HIT SOUND
                Sleep(1500);
                cout << endl;
                B.play();                                   //SHUFFLE SOUND
                Sleep(2000);
            } while (anotherCard == "Y");
        }
        else if (i == 3) {
            Player3.setName(playerName);
            cout << playerName + " is playing" << endl;
            B.play();                                   //SHUFFLE SOUND
            Sleep(2000);
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
                A.play();                                   //CARD HIT SOUND
                Sleep(1500);
                cout << endl;
                B.play();                                   //SHUFFLE SOUND
                Sleep(2000);
            } while (anotherCard == "Y");
        }
        else if (i == 4) {
            Player4.setName(playerName);
            cout << playerName + " is playing" << endl;
            B.play();                                   //SHUFFLE SOUND
            Sleep(2000);
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
                A.play();                                   //CARD HIT SOUND
                Sleep(1500);
                cout << endl;
                B.play();                                   //SHUFFLE SOUND
                Sleep(2000);
            } while (anotherCard == "Y");
        }
        else if (i == 5) {
            Player5.setName(playerName);
            cout << playerName + " is playing" << endl;
            B.play();                                   //SHUFFLE SOUND
            Sleep(2000);
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
                A.play();                                   //CARD HIT SOUND
                Sleep(1500);
                cout << endl;
                B.play();                                   //SHUFFLE SOUND
                Sleep(2000);
            } while (anotherCard == "Y");
        }
        else if (i == 6) {
            Player6.setName(playerName);
            cout << playerName + " is playing" << endl;
            B.play();                                   //SHUFFLE SOUND
            Sleep(2000);
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
                A.play();                                   //CARD HIT SOUND
                Sleep(1500);
                cout << endl;
                B.play();                                   //SHUFFLE SOUND
                Sleep(2000);
            } while (anotherCard == "Y");
        }
    }
    //DEALING WITH THE DEALER
    player[0] = Dealer.calculate();
    //HIT WHILE UNDER 16
    while (player[0] < 16) {
        cout << endl << "Dealer being dealt another card " << endl << endl;
        B.play();
        Sleep(2000);
        auto Card = CardGenerator();
        Dealer.addCardDisplay(Card);
        Dealer.addCardNum(Card.second);
        player[0] = Dealer.calculate();
    }
    //CHECK EACH PLAYER VERSUS DEALER
    for (int i = 1; i < numberPlayers + 1; i++)
    {
        cout << endl << endl;
        switch (i)  //SWITCH FOR EACH PLAYER
        {
        case 1: //CASE IS PLAYER 1
            if ((player[0] < player[i] || !DealerUnder) && player[i] <= 21) { //PLAYER OVER DEALER AND DEALER UNDER 21 AND PLAYER UNDER 21
                cout << Player1.getName() << " has won"; //PLAYER 1 WON WITH NAME
            }
            else
            {
                cout << Player1.getName() << " has lost"; //PLAYER 1 LOST WITH NAME
                G.play();
                Sleep(1500);
            }
            break;
        case 2:
            if ((player[0] < player[i] || !DealerUnder) && player[i] <= 21) {
                cout << Player2.getName() << " has won";
            }
            else
            {
                cout << Player2.getName() << " has lost";
                G.play();
                Sleep(1500);
            }
            break;
        case 3:
            if ((player[0] < player[i] || !DealerUnder) && player[i] <= 21) {
                cout << Player3.getName() << " has won";
            }
            else
            {
                cout << Player3.getName() << " has lost";
                G.play();
                Sleep(1500);
            }
            break;
        case 4:
            if ((player[0] < player[i] || !DealerUnder) && player[i] <= 21) {
                cout << Player4.getName() << " has won";
            }
            else
            {
                cout << Player4.getName() << " has lost";
                G.play();
                Sleep(1500);
            }
            break;
        case 5:
            if ((player[0] < player[i] || !DealerUnder) && player[i] <= 21) {
                cout << Player5.getName() << " has won";
            }
            else
            {
                cout << Player5.getName() << " has lost";
                G.play();
                Sleep(1500);
            }
            break;
        case 6:
            if ((player[0] < player[i] || !DealerUnder) && player[i] <= 21) {
                cout << Player6.getName() << " has won";
            }
            else
            {
                cout << Player6.getName() << " has lost";
                G.play();
                Sleep(1500);
            }
            break;
        }
     
    }

    for (int i = 0; i < numberPlayers; i++)
    {
        if ((player[0] > player[i] && player[i] > 21) || (player[0] > player[i] && player[i] < 21))
        {
            L.play();
            Sleep(2000);
        }
        else if ((player[0] < player[i] || !DealerUnder) && player[i] <= 21)
        {
            D.play();
            Sleep(5000);
            E.play();
            Sleep(1500);
            F.play();
            Sleep(2000);
        }
    }

    cout << endl << endl;
    system("pause");
}


void DisplayName(string playerName, int i, int numberPlayers) {
    int DisplaySize = 800;
    double Spaces = DisplaySize / (numberPlayers + 1);
    double PrintSpot = Spaces * i;



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

//SAVING EACH TYPE OF CARD
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





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
