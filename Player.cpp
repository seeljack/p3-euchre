// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <string>
#include "Player.h"
#include "Pack.h"
#include "Card.h"
using namespace std;

                //HUMAN
Human::Human(std::string name_in) {
    name = name_in;
}

    //EFFECTS returns player's name
const std::string & Human::get_name() const {
    return name;
}
    
    //REQUIRES player has less than MAX_HAND_SIZE cards
    //EFFECTS  adds Card c to Player's hand
void Human::add_card(const Card &c) {
    if (static_cast<int>(Hand.size()) < MAX_HAND_SIZE) {
        Hand.push_back(c);
    }
}
    
    //REQUIRES round is 1 or 2
    //MODIFIES order_up_suit
    //EFFECTS If Player wishes to order up a trump suit then return true and
    //  change order_up_suit to desired suit.  If Player wishes to pass, then do
    //  not modify order_up_suit and return false.
bool Human::make_trump(const Card &upcard, bool is_dealer,
                       int round, std::string &order_up_suit) const{
    std::string input;
    print_hand();
    cout << "Human player " << name << ", please enter a suit, or \"pass\":\n";
    cin >> input;
    if (round == 1) {
        if (input == "pass") {
            cout << name << " passes" << endl;
            return false;
        }
        else if (input == upcard.get_suit()) {
            order_up_suit = upcard.get_suit();
            if (is_dealer) {
                add_and_discard(upcard);
            }
            return true;
        }
    }
    else {
        if (!is_dealer) {
            if (input == "pass") {
                cout << name << " passes" << endl;
                return false;
            }
            for (int i = 0; i < NUM_SUITS; i++) {
                if (input == SUIT_NAMES_BY_WEIGHT[i]) {
                    order_up_suit = SUIT_NAMES_BY_WEIGHT[i];
                    cout << name << " orders up " << order_up_suit;
                    return true;
                }
                cout << "Error: invalid input" << endl;
                return false;
            }
        }
    }
}
    //REQUIRES Player has at least one card
    //EFFECTS  Player adds one card to hand and removes one card from hand.
void Human::add_and_discard(const Card &upcard){
    
    std::string input;
    print_hand();
    cout << "Discard upcard: [-1]" << endl;
    cout << "Human player " << name <<", please select a card to discard:" << endl;
    cin >> input;
}
    
    //REQUIRES Player has at least one card, trump is a valid suit
    //EFFECTS  Leads one Card from Player's hand according to their strategy
    //  "Lead" means to play the first Card in a trick.  The card
    //  is removed the player's hand.
Card Human::lead_card(const std::string &trump){
    assert(false);
}
    
    //REQUIRES Player has at least one card, trump is a valid suit
    //EFFECTS  Plays one Card from Player's hand according to their strategy.
    //  The card is removed from the player's hand.
Card Human::play_card(const Card &led_card, const std::string &trump){
    assert(false);
}
void Human::print_hand() const {
    for (size_t i = 0; i < Hand.size(); ++i)
      cout << "Human player " << name << "'s hand: "
           << "[" << i << "] " << Hand[i] << "\n";
  }
    
    // Needed to avoid some compiler errors
  //  Human::~Human() {}

            //SIMPLE

Simple::Simple(std::string name_in) {
    name = name_in;
    
}
    //EFFECTS returns player's name
const std::string & Simple::get_name() const{
    return name;
}
    
    //REQUIRES player has less than MAX_HAND_SIZE cards
    //EFFECTS  adds Card c to Player's hand
void Simple::add_card(const Card &c){
    if (static_cast<int>(Hand.size()) < MAX_HAND_SIZE) {
        Hand.push_back(c);
    }
}
    
    //REQUIRES round is 1 or 2
    //MODIFIES order_up_suit
    //EFFECTS If Player wishes to order up a trump suit then return true and
    //  change order_up_suit to desired suit.  If Player wishes to pass, then do
    //  not modify order_up_suit and return false.
bool Simple::make_trump(const Card &upcard, bool is_dealer,
                        int round, std::string &order_up_suit) const{
    assert(false);
}
    
    //REQUIRES Player has at least one card
    //EFFECTS  Player adds one card to hand and removes one card from hand.
void Simple::add_and_discard(const Card &upcard){
    assert(false);
}
    
    //REQUIRES Player has at least one card, trump is a valid suit
    //EFFECTS  Leads one Card from Player's hand according to their strategy
    //  "Lead" means to play the first Card in a trick.  The card
    //  is removed the player's hand.
Card Simple::lead_card(const std::string &trump){
    assert(false);
}
    
    //REQUIRES Player has at least one card, trump is a valid suit
    //EFFECTS  Plays one Card from Player's hand according to their strategy.
    //  The card is removed from the player's hand
Card Simple::play_card(const Card &led_card, const std::string &trump){
    assert(false);
}
    
    
    // Needed to avoid some compiler errors
  //  ~Simple() {}

//EFFECTS: Returns a pointer to a player with the given name and strategy
//To create an object that won't go out of scope when the function returns,
//use "return new Simple(name)" or "return new Human(name)"
//Don't forget to call "delete" on each Player* after the game is over
Player * Player_factory(const std::string &name, const std::string &strategy) {
        if (strategy == "Simple") {
            return new Simple(name);
          }
        else if (strategy == "Human") {
            return new Human(name);
        }
    else{
        return nullptr;
    }
}
    //EFFECTS: Prints player's name to os
//std::ostream & Player::operator<<(std::ostream &os, const Player &p);
