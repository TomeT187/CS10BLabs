#include "Card.h"
#include <cctype>

Card::Card(){
    suit = 'c';
    rank = 2;
}
Card::Card(char suitIn, int rankIn){
    suitIn = tolower(suitIn);
    if (suitIn == 'c' || suitIn == 'd' || suitIn == 'h' || suitIn == 's'){
        suit = suitIn;
    }else{
        suit = 'c';
    }
    if (rankIn >= 1 && rankIn <= 13){
        rank = rankIn;
    }else{
        rank = 2;
    }
}
char Card::getSuit() const{
    return suit;
}
int Card::getRank() const{
    return rank;
}
ostream & operator<<(ostream & out, const Card & rhs){
    string rankOut;
    string suitOut;
    if (rhs.rank == 1){
        rankOut = "Ace";
    }else if(rhs.rank == 11){
        rankOut = "Jack";
    }else if(rhs.rank == 12){
        rankOut = "Queen";
    }else if(rhs.rank == 13){
        rankOut = "King";
    }else if(rhs.rank == 10){
        rankOut = "10";
    }
    else{
        rankOut = char(rhs.rank + 48);
    }

    if (rhs.suit == 'c'){
        suitOut = "Clubs";
    }else if(rhs.suit == 'd'){
        suitOut = "Diamonds";
    }else if(rhs.suit == 'h'){
        suitOut = "Hearts";
    }else if(rhs.suit == 's'){
        suitOut = "Spades";
    }else{
        suitOut = rhs.suit; //should never occur, only for error testing
    }
    out << rankOut << " of " << suitOut;
    return out;
}

// int main(){
//     Card test('S',100);
//     cout << test << endl;
//     return 1;
// }