#include "Deck.h"
#include <algorithm>

Deck::Deck(){
    char suits[] = {'c','d','h','s'};
    for (int s = 3; s >= 0; s--){
        for (int r = 13; r > 0; r--){
            Card tempCard(suits[s],r);
            theDeck.push_back(tempCard);
        }
    }

}

Card Deck::dealCard(){
    Card temp = theDeck.back();
    theDeck.pop_back();
    dealtCards.push_back(temp);
    return temp;

}

void Deck::shuffleDeck(){
    for (unsigned i = 0; i < dealtCards.size(); i++){
        theDeck.push_back(dealtCards[i]);
    }
    vector<Card> clear;
    dealtCards = clear;
    
    random_shuffle(theDeck.begin(), theDeck.end()); //IDE says function doesnt exist
                                                    //i say too bad
}

unsigned Deck::deckSize() const{
    return theDeck.size();
}

// int main(){
//     Deck temp;
//     cout << "test" << endl;
//     for (unsigned i = 0; i < temp.deckSize(); i++){
//         cout << temp.dealCard() << endl;
//     }
//     temp.shuffleDeck();
//     cout << "Shuffled ---------------------------------------------" << endl;
//     for (unsigned i = 0; i < temp.deckSize(); i++){
//         cout << temp.dealCard() << endl;
//     }
//     temp.shuffleDeck();
//     cout << "Shuffled2 ---------------------------------------------" << endl;
//     for (unsigned i = 0; i < temp.deckSize(); i++){
//         cout << temp.dealCard() << endl;
//     }
//     return 0;
// }