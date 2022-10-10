#ifndef PLAYER_H
#define PLAYER_H
/* Player.h
 *
 * Euchre player interface
 * Project UID 1d9f47bfc76643019cfbf037641defe1
 *
 * by Josh Cussen and Jack Seel
 * jcussen@umich.edu and seeljack@umich.edu
 * 10/9/22
 */


#include "Card.h"
#include "Pack.h"
#include <iostream>
#include <string>
#include <vector>

class Player {
 public:
  //EFFECTS returns player's name
  virtual const std::string & get_name() const = 0;

  //REQUIRES player has less than MAX_HAND_SIZE cards
  //EFFECTS  adds Card c to Player's hand
  virtual void add_card(const Card &c) = 0;

  //REQUIRES round is 1 or 2
  //MODIFIES order_up_suit
  //EFFECTS If Player wishes to order up a trump suit then return true and
  //  change order_up_suit to desired suit.  If Player wishes to pass, then do
  //  not modify order_up_suit and return false.
  virtual bool make_trump(const Card &upcard, bool is_dealer,
                          int round, std::string &order_up_suit) const = 0;

  //REQUIRES Player has at least one card
  //EFFECTS  Player adds one card to hand and removes one card from hand.
  virtual void add_and_discard(const Card &upcard) = 0;

  //REQUIRES Player has at least one card, trump is a valid suit
  //EFFECTS  Leads one Card from Player's hand according to their strategy
  //  "Lead" means to play the first Card in a trick.  The card
  //  is removed the player's hand.
  virtual Card lead_card(const std::string &trump) = 0;

  //REQUIRES Player has at least one card, trump is a valid suit
  //EFFECTS  Plays one Card from Player's hand according to their strategy.
  //  The card is removed from the player's hand.
  virtual Card play_card(const Card &led_card, const std::string &trump) = 0;

  // Maximum number of cards in a player's hand
  static const int MAX_HAND_SIZE = 5;

  // Needed to avoid some compiler errors
  virtual ~Player() {}
};

//EFFECTS: Returns a pointer to a player with the given name and strategy
//To create an object that won't go out of scope when the function returns,
//use "return new Simple(name)" or "return new Human(name)"
//Don't forget to call "delete" on each Player* after the game is over
Player * Player_factory(const std::string &name, const std::string &strategy);

//EFFECTS: Prints player's name to os
std::ostream & operator<<(std::ostream &os, const Player &p);


//class Human : public Player {
//public:
//    
//    Human(std::string name_in);
//    
//    //EFFECTS returns player's name
//    const std::string & get_name() const;
//    
//    //REQUIRES player has less than MAX_HAND_SIZE cards
//    //EFFECTS  adds Card c to Player's hand
//    void add_card(const Card &c);
//    
//    //REQUIRES round is 1 or 2
//    //MODIFIES order_up_suit
//    //EFFECTS If Player wishes to order up a trump suit then return true and
//    //  change order_up_suit to desired suit.  If Player wishes to pass, then do
//    //  not modify order_up_suit and return false.
//    bool make_trump(const Card &upcard, bool is_dealer,
//                            int round, std::string &order_up_suit) const;
//    
//    //REQUIRES Player has at least one card
//    //EFFECTS  Player adds one card to hand and removes one card from hand.
//    void add_and_discard(const Card &upcard);
//    
//    //REQUIRES Player has at least one card, trump is a valid suit
//    //EFFECTS  Leads one Card from Player's hand according to their strategy
//    //  "Lead" means to play the first Card in a trick.  The card
//    //  is removed the player's hand.
//    Card lead_card(const std::string &trump);
//    
//    //REQUIRES Player has at least one card, trump is a valid suit
//    //EFFECTS  Plays one Card from Player's hand according to their strategy.
//    //  The card is removed from the player's hand.
//    Card play_card(const Card &led_card, const std::string &trump);
//    
//    void print_hand() const;
//    
//    // Needed to avoid some compiler errors
//    ~Human() {}
//};



//class Simple : public Player {
//public:
//
//    Simple(std::string name_in);
//    //EFFECTS returns player's name
//    const std::string & get_name() const;
//
//    //REQUIRES player has less than MAX_HAND_SIZE cards
//    //EFFECTS  adds Card c to Player's hand
//    void add_card(const Card &c);
//
//    //REQUIRES round is 1 or 2
//    //MODIFIES order_up_suit
//    //EFFECTS If Player wishes to order up a trump suit then return true and
//    //  change order_up_suit to desired suit.  If Player wishes to pass, then do
//    //  not modify order_up_suit and return false.
//    bool make_trump(const Card &upcard, bool is_dealer,
//                            int round, std::string &order_up_suit) const;
//
//    //REQUIRES Player has at least one card
//    //EFFECTS  Player adds one card to hand and removes one card from hand.
//    void add_and_discard(const Card &upcard);
//
//    //REQUIRES Player has at least one card, trump is a valid suit
//    //EFFECTS  Leads one Card from Player's hand according to their strategy
//    //  "Lead" means to play the first Card in a trick.  The card
//    //  is removed the player's hand.
//    Card lead_card(const std::string &trump);
//
//    //REQUIRES Player has at least one card, trump is a valid suit
//    //EFFECTS  Plays one Card from Player's hand according to their strategy.
//    //  The card is removed from the player's hand.
//    Card play_card(const Card &led_card, const std::string &trump);
//
//
//    // Needed to avoid some compiler errors
//    ~Simple() {}
//};
#endif
