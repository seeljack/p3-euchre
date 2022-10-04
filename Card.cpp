// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <string>
#include "Card.h"
using namespace std;
// add any necessary #include or using directives here

// rank and suit names -- do not remove these
constexpr const char* const Card::RANK_TWO;
constexpr const char* const Card::RANK_THREE;
constexpr const char* const Card::RANK_FOUR;
constexpr const char* const Card::RANK_FIVE;
constexpr const char* const Card::RANK_SIX;
constexpr const char* const Card::RANK_SEVEN;
constexpr const char* const Card::RANK_EIGHT;
constexpr const char* const Card::RANK_NINE;
constexpr const char* const Card::RANK_TEN;
constexpr const char* const Card::RANK_JACK;
constexpr const char* const Card::RANK_QUEEN;
constexpr const char* const Card::RANK_KING;
constexpr const char* const Card::RANK_ACE;

constexpr const char* const Card::SUIT_SPADES;
constexpr const char* const Card::SUIT_HEARTS;
constexpr const char* const Card::SUIT_CLUBS;
constexpr const char* const Card::SUIT_DIAMONDS;

// add your code below
//EFFECTS Initializes Card to the Two of Spades
Card::Card()
    : rank(RANK_TWO), suit(SUIT_SPADES){}

//REQUIRES rank is one of "Two", "Three", "Four", "Five", "Six", "Seven",
//  "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"
//  suit is one of "Spades", "Hearts", "Clubs", "Diamonds"
//EFFECTS Initializes Card to specified rank and suit
Card::Card(const std::string &rank_in, const std::string &suit_in)
    : rank(rank_in), suit(suit_in){}

//EFFECTS Returns the rank
std::string Card::get_rank() const{
    return rank;
}

//EFFECTS Returns the suit.  Does not consider trump.
std::string Card::get_suit() const{
    return suit;
}

//REQUIRES trump is a valid suit
//EFFECTS Returns the suit
//HINT: the left bower is the trump suit!
std::string Card::get_suit(const std::string &trump) const{
    if (rank == RANK_JACK && is_trump(trump)) {
            return trump;
    }
    else {
        return suit;
    }
}

//EFFECTS Returns true if card is a face card (Jack, Queen, King or Ace)
bool Card::is_face_or_ace() const{
    if(rank == RANK_JACK || rank == RANK_QUEEN || rank == RANK_KING || rank == RANK_ACE){
        return true;
    }
    else{
        return false;
    }
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if card is the Jack of the trump suit
bool Card::is_right_bower(const std::string &trump) const{
    if (rank == RANK_JACK && suit == trump) {
        return true;
    }
    else {
        return false;
    }
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if card is the Jack of the next suit
bool Card::is_left_bower(const std::string &trump) const{
    if (rank == RANK_JACK && is_trump(trump) && suit != trump) {
        return true;
    }
    else {
        return false;
    }
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if the card is a trump card.  All cards of the trump
// suit are trump cards.  The left bower is also a trump card.
bool Card::is_trump(const std::string &trump) const{
    if (suit == trump) {
        return true;
    }
    else if (rank == RANK_JACK) {
        if (suit == SUIT_SPADES && trump == SUIT_CLUBS) {
            return true;
        }
        else if (suit == SUIT_CLUBS && trump == SUIT_SPADES) {
            return true;
        }
        else if (suit == SUIT_HEARTS && trump == SUIT_DIAMONDS) {
            return true;
        }
        else if (suit == SUIT_DIAMONDS && trump == SUIT_HEARTS) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

//EFFECTS Returns true if lhs is lower value than rhs.
//  Does not consider trump.
bool operator<(const Card &lhs, const Card &rhs){
    int lhs_rank = -1;
    int rhs_rank = -1;
    for(int i = 0; i < NUM_RANKS; i++) {
        if (RANK_NAMES_BY_WEIGHT[i] == lhs.get_rank()) {
            lhs_rank = i;
        }
        if (RANK_NAMES_BY_WEIGHT[i] == rhs.get_rank()) {
            rhs_rank = i;
        }
    }
    return lhs_rank < rhs_rank;
}

//EFFECTS Returns true if lhs is lower value than rhs or the same card as rhs.
//  Does not consider trump.
bool operator<=(const Card &lhs, const Card &rhs){
    int lhs_rank = -1;
    int rhs_rank = -1;
    for(int i = 0; i < NUM_RANKS; i++) {
        if (RANK_NAMES_BY_WEIGHT[i] == lhs.get_rank()) {
            lhs_rank = i;
        }
        if (RANK_NAMES_BY_WEIGHT[i] == rhs.get_rank()) {
            rhs_rank = i;
        }
    }
    return lhs_rank <= rhs_rank;
}

//EFFECTS Returns true if lhs is higher value than rhs.
//  Does not consider trump.
bool operator>(const Card &lhs, const Card &rhs){
    int lhs_rank = -1;
    int rhs_rank = -1;
    for(int i = 0; i < NUM_RANKS; i++) {
        if (RANK_NAMES_BY_WEIGHT[i] == lhs.get_rank()) {
            lhs_rank = i;
        }
        if (RANK_NAMES_BY_WEIGHT[i] == rhs.get_rank()) {
            rhs_rank = i;
        }
    }
    return lhs_rank > rhs_rank;
}


//EFFECTS Returns true if lhs is higher value than rhs or the same card as rhs.
//  Does not consider trump.
bool operator>=(const Card &lhs, const Card &rhs){
    int lhs_rank = -1;
    int rhs_rank = -1;
    for(int i = 0; i < NUM_RANKS; i++) {
        if (RANK_NAMES_BY_WEIGHT[i] == lhs.get_rank()) {
            lhs_rank = i;
        }
        if (RANK_NAMES_BY_WEIGHT[i] == rhs.get_rank()) {
            rhs_rank = i;
        }
    }
    return lhs_rank >= rhs_rank;
}

//EFFECTS Returns true if lhs is same card as rhs.
//  Does not consider trump.
bool operator==(const Card &lhs, const Card &rhs){
    if (lhs.get_suit() == rhs.get_suit()) {
        if (lhs.get_rank() == rhs.get_rank()) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}


//EFFECTS Returns true if lhs is not the same card as rhs.
//  Does not consider trump.
bool operator!=(const Card &lhs, const Card &rhs){
    if (lhs.get_suit() == rhs.get_suit()) {
        if (lhs.get_rank() == rhs.get_rank()) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return true;
    }
}

//REQUIRES suit is a valid suit
//EFFECTS returns the next suit, which is the suit of the same color
std::string Suit_next(const std::string &suit){
    if (suit == Card::SUIT_SPADES) {
        return Card::SUIT_CLUBS;
    }
    else if (suit == Card::SUIT_CLUBS) {
        return Card::SUIT_SPADES;
    }
    else if (suit == Card::SUIT_DIAMONDS) {
        return Card::SUIT_HEARTS;
    }
    else {
        return Card::SUIT_DIAMONDS;
    }
}

//EFFECTS Prints Card to stream, for example "Two of Spades"
std::ostream & operator<<(std::ostream &os, const Card &card){
    return os << card.get_rank() << " of " << card.get_suit();
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if a is lower value than b.  Uses trump to determine
// order, as described in the spec.
bool Card_less(const Card &a, const Card &b, const std::string &trump){
    if (a == b) {
        return false;
    }
    else if(!a.is_trump(trump) && !b.is_trump(trump)) { //both not trump
        return a < b;
    }
    else if (!a.is_trump(trump)) { //if a is not trump, b must be
        return true;
    }
    else if (!b.is_trump(trump)) { //if b is not, a must be
        return false;
    }
    else {
        if (a.is_right_bower(trump)) {
            return false;
        }
        else if(b.is_right_bower(trump)) {
            return true;
        }
        else if (a.is_left_bower(trump)) {
            return false;
        }
        else if (b.is_left_bower(trump)) {
            return true;
        }
        else {
            return a < b;
        }
    }
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if a is lower value than b.  Uses both the trump suit
//  and the suit led to determine order, as described in the spec.
bool Card_less(const Card &a, const Card &b, const Card &led_card,
             const std::string &trump){
//    if (a == b) {
//        return false;
//    }
//    else if (!a.is_trump(trump) && !b.is_trump(trump) && !led_card.is_trump(trump)) {
//        if (led_card.get_suit() != b.get_suit()) {
//            if (led_card.get_suit() != a.get_suit()) {
//                return a < b;
//            }
//        }
//    }
    if (led_card.is_trump(trump)){
        return Card_less(a, b, trump);
    }
    else {
        if (a.is_trump(trump) && b.is_trump(trump)) { //lead is not trump but a and b are
            return Card_less(a, b, trump);
        }
        else if (a.is_trump(trump)) {
            return false;
        }
        else if (b.is_trump(trump)) {
            return true;
        }
        else if (a.get_suit() == led_card.get_suit() && b.get_suit() == \
                 led_card.get_suit()) {
            //lead, a and b are not trump, a and b both match suit with lead
                return a < b;
            }
        else if (a.get_suit() == led_card.get_suit()) { //a matches suit but b doesnt
            return false;
        }
        else if (b.get_suit() == led_card.get_suit()) { //b matches but a doesn't
            return true;
        }
        else {
            return a < b; //a and b are not trump and do not match lead
        }
    }
}



// NOTE: We HIGHLY recommend you check out the operator overloading
// tutorial in the project spec before implementing
// the following operator overload functions:
//   operator<<
//   operator<
//   operator<=
//   operator>
//   operator>=
//   operator==
//   operator!=
