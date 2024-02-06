#include <iostream>
#include <cstdlib> //???? why is this the default template
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand){
    for (unsigned i = 0; i < hand.size(); i++){
        for (unsigned ii = i +1; ii < hand.size(); ii++){
            if (hand[i].getRank() == hand[ii].getRank()){
                return true;
            }
        }
    }
    return false;
}

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream & out, const vector<Card> & cardVec){
    for (unsigned i = 0; i < cardVec.size(); i++){
        out << cardVec[i];
        if (i != cardVec.size() - 1){
            out << ", ";
        }
    }
    return out;
}

int main() {
    srand(2222);
    ofstream fout;
    string input;
    int cardsPerHand;
    int numSims;
    cout << "Do you want to output all hands to a file?(Yes/No)" << endl;
    cin >> input;
    bool openFile = (input == "Yes");
    if (openFile){
        cout << "Enter name of output file:" << endl;
        cin >> input;
        fout.open(input);
    }
    // if (!fout.is_open()){
    //     cout << "not open ---------------------------" << endl;
    // }
    cout << "Enter number of cards per hand:" << endl;
    cin >> cardsPerHand;
    cout << "Enter number of deals (simulations):" << endl;
    cin >> numSims;

    Deck tempDeck;
    int handCount = 0;
    int pairCount = 0;
    for (int i = 0; i < numSims; i++){
        tempDeck.shuffleDeck();
        vector<Card> cardVec;
        for (int ii = 0; ii < cardsPerHand; ii++){
            cardVec.push_back(tempDeck.dealCard());
        }
        handCount++;
        if (hasPair(cardVec)){
            pairCount++;
        }
        if (openFile){
            if(hasPair(cardVec)){
                fout << "Found Pair!!";
            }else{
                fout << "            ";
            }
            fout <<" " << cardVec << endl;
        }

    }
    double percentage = (double(pairCount)/ double(handCount)) * 100;
    fout.close();
    cout << "Chances of receiving a pair in a hand of " << cardsPerHand << " cards is: " << percentage << "%" << endl;



    return 0;
}