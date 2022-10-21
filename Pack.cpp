// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <string>
#include "Pack.h"
#include <vector>
#include "Card.h"
using namespace std;

// EFFECTS: Initializes the Pack to be in the following standard order:
//          the cards of the lowest suit arranged from lowest rank to
//          highest rank, followed by the cards of the next lowest suit
//          in order from lowest to highest rank, and so on.
// NOTE: The standard order is the same as that in pack.in.
// NOTE: Do NOT use pack.in in your implementation of this function
Pack::Pack() {
    int index = 0;
    for(int i = 0; i < NUM_SUITS; i++){
        for(int j =7; j < NUM_RANKS; j++){
            cards[index] = Card(RANK_NAMES_BY_WEIGHT[j], SUIT_NAMES_BY_WEIGHT[i]);
            index +=1;
        }
    }
    next = 0;
}

// REQUIRES: pack_input contains a representation of a Pack in the
//           format required by the project specification
// MODIFIES: pack_input
// EFFECTS: Initializes Pack by reading from pack_input.
Pack::Pack(istream& pack_input){
    for(int i =0; i < PACK_SIZE; i++){
        string rank;
        string junk;
        string suit;
        pack_input >> rank >> junk >> suit;
        cards[i] = Card(rank, suit);
    }
    next = 0;
}

// REQUIRES: cards remain in the Pack
// EFFECTS: Returns the next card in the pack and increments the next index
Card Pack::deal_one(){
    Card c;
    c = cards[next];
    next += 1;
    return c;
}

// EFFECTS: Resets next index to first card in the Pack
void Pack::reset(){
    next = 0;
}

// EFFECTS: Shuffles the Pack and resets the next index. This
//          performs an in shuffle seven times. See
//          https://en.wikipedia.org/wiki/In_shuffle.
void Pack::shuffle(){
    int count = 0;
    int half_pack_size = PACK_SIZE / 2;
    Card a;
    Card b;
    vector<Card> keep_lost;
    while (count < 7){
        int counter = 1;
        keep_lost.clear();
        int index = 0;
        count += 1;
        for(int i = 0; i < half_pack_size; i++){
                if(i==0){
                    a = cards[i];
                    b = cards[half_pack_size + i];
                    cards[i] = b;
                    keep_lost.push_back(cards[i+1]);
                    cards[i+1] = a;
                }
                else{
                    b = cards[half_pack_size + i];
                    keep_lost.push_back(cards[i+counter]);
                    keep_lost.push_back(cards[i+ counter + 1]);
                    cards[i+counter] = b;
                    cards[i+counter + 1] = keep_lost[index];
                    index +=1;
                    counter += 1;
                }
            }
        next = 0;
    }
//    int half_pack_size = PACK_SIZE / 2;
//    for (int count = 0; count < 7; count++) {
//        std::vector<Card> new_cards;
//        for (int i = 0; i < PACK_SIZE; i++) {
//            new_cards.push_back(cards[i]);
//        }
//        for (int a = 0; a < 7; a++) {
//            for (int i = 0; i < PACK_SIZE; i += 2) {
//                cards[i] = new_cards[(i / 2) + half_pack_size];
//                cards[i + 1] = new_cards[i / 2];
//            }
//        }
//    }
}

// EFFECTS: returns true if there are no more cards left in the pack
bool Pack::empty() const{
    if (next >= 24) {
        return true;
    }
    else {
        cout << next << "\n";
        return false;
    }
}
