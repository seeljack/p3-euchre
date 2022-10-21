// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <string>
#include "Player.h"
#include "Card.h"
#include "vector"
using namespace std;

                //HUMAN
class Human : public Player {
public:
    
    std::vector<Card> Hand;
    std::string name;
    
    Human(std::string name_in) {
        name = name_in;
    }
    
    //EFFECTS returns player's name
    const std::string & get_name() const {
        return name;
    }
    
    //REQUIRES player has less than MAX_HAND_SIZE cards
    //EFFECTS  adds Card c to Player's hand
    void add_card(const Card &c) {
        if (static_cast<int>(Hand.size()) < MAX_HAND_SIZE) {
            Hand.push_back(c);
        }
    }
    
    //REQUIRES round is 1 or 2
    //MODIFIES order_up_suit
    //EFFECTS If Player wishes to order up a trump suit then return true and
    //  change order_up_suit to desired suit.  If Player wishes to pass, then do
    //  not modify order_up_suit and return false.
    bool make_trump(const Card &upcard, bool is_dealer,
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
                // if (is_dealer) {
                //     add_and_discard(upcard);
                // }
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
                }
                cout << "Error: invalid input" << endl;
                return false;
            }
        }
        //Added this so it would compile:
        return false;
    }
    //REQUIRES Player has at least one card
    //EFFECTS  Player adds one card to hand and removes one card from hand.
    void add_and_discard(const Card &upcard){
        
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
    Card lead_card(const std::string &trump){
        assert(false);
    }
    
    //REQUIRES Player has at least one card, trump is a valid suit
    //EFFECTS  Plays one Card from Player's hand according to their strategy.
    //  The card is removed from the player's hand.
    Card play_card(const Card &led_card, const std::string &trump){
        assert(false);
    }
    
    void print_hand() const {
        for (size_t i = 0; i < Hand.size(); ++i)
            cout << "Human player " << name << "'s hand: "
            << "[" << i << "] " << Hand[i] << "\n";
    }
    
//    Needed to avoid some compiler errors
    ~Human() {}
};



class Simple : public Player {
public:
    std::vector<Card> Hand;
    std::string name;
    
    Simple(std::string name_in) {
        name = name_in;
        
    }
    //EFFECTS returns player's name
    const std::string & get_name() const{
        return name;
    }
    
    //REQUIRES player has less than MAX_HAND_SIZE cards
    //EFFECTS  adds Card c to Player's hand
    void add_card(const Card &c){
        if (static_cast<int>(Hand.size()) < MAX_HAND_SIZE) {
            Hand.push_back(c);
        }
    }
    
    //REQUIRES round is 1 or 2
    //MODIFIES order_up_suit
    //EFFECTS If Player wishes to order up a trump suit then return true and
    //  change order_up_suit to desired suit.  If Player wishes to pass, then do
    //  not modify order_up_suit and return false.
    bool make_trump(const Card &upcard, bool is_dealer,
                    int round, std::string &order_up_suit) const{
        int count_of_upcard = 0;
        string other_suit;
        int count_round2 = 0;
        if(round == 1){
            for(int i = 0; i < Hand.size(); i++){
                if(Hand[i].get_suit() == upcard.get_suit() && (Hand[i].is_face_or_ace() || Hand[i].is_left_bower(upcard.get_suit()) || Hand[i].is_right_bower(upcard.get_suit()))){
                    count_of_upcard += 1;
                }
            }
            if(count_of_upcard >=2){
                order_up_suit = upcard.get_suit();
                return true;
            }
            else{
                return false;
            }
            
        }
        //Round 2
        else{
            if(is_dealer){
                string suit = upcard.get_suit();
                if(suit == upcard.SUIT_CLUBS){
                    order_up_suit = upcard.SUIT_SPADES;
                }
                else if(suit == upcard.SUIT_SPADES){
                    order_up_suit = upcard.SUIT_CLUBS;
                }
                else if(suit == upcard.SUIT_DIAMONDS){
                    order_up_suit = upcard.SUIT_HEARTS;
                }
                else{
                    order_up_suit = upcard.SUIT_DIAMONDS;
                }
                return true;
            }
            else{
                string suit = upcard.get_suit();
                if(suit == upcard.SUIT_CLUBS){
                    other_suit = upcard.SUIT_SPADES;
                }
                else if(suit == upcard.SUIT_SPADES){
                    other_suit = upcard.SUIT_CLUBS;
                }
                else if(suit == upcard.SUIT_DIAMONDS){
                    other_suit = upcard.SUIT_HEARTS;
                }
                else{
                    other_suit = upcard.SUIT_DIAMONDS;
                }
                
                for(int i = 0; i < Hand.size(); i++){
                    if(Hand[i].get_suit() == other_suit){
                        count_round2 +=1;
                    }
                }
                if(count_round2 >= 1){
                    order_up_suit = other_suit;
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        
    }
    
    //REQUIRES Player has at least one card
    //EFFECTS  Player adds one card to hand and removes one card from hand.
 void add_and_discard(const Card &upcard){
        Card min = Hand[0];
        int min_num = 0;
        for(int i = 0; i < Hand.size(); i++){
            if(Card_less(Hand[i],min, upcard.get_suit())){
                min = Hand[i];
                min_num = i;
            }
        }
        Hand.erase(Hand.begin()+ min_num);
        add_card(upcard);
        
    }
    
    //REQUIRES Player has at least one card, trump is a valid suit
    //EFFECTS  Leads one Card from Player's hand according to their strategy
    //  "Lead" means to play the first Card in a trick.  The card
    //  is removed the player's hand.
    Card lead_card(const std::string &trump){
        int has_all_trump = 0;
        int is_left = 0;
       // int is_left_num = 0;
       // int max_iterator = 0;
       // int real_is_left_num;
        for(int i = 0; i < Hand.size(); i++){
            if(Hand[i].get_suit() == trump || Hand[i].is_left_bower(trump)){
                has_all_trump += 1;
            }
        }
        if(has_all_trump == Hand.size()){
            //plays highest value card(trump)
            Card max = Hand[0];
            Card is_left_b = Hand[0];
            for(int i = 0; i < Hand.size(); i++){
            //    max_iterator += 1;
             //   is_left_num += 1;
                if(Hand[i].is_right_bower(trump)){
                    Card trump1;
                    trump1 = Hand[i];
                    // trump1 = play_card(trump1,trump);
                    // Hand.erase(Hand.begin()+ i);
                    Hand.erase(Hand.begin()+ i);
                    return trump1;
                }
                else if(Hand[i].is_left_bower(trump)){
                    is_left = 1;
                 //   real_is_left_num = is_left_num;
                    is_left_b = Hand[i];
                }
                else if(operator>(Hand[i], max)){
                    max = Hand[i];
                //    max_iterator = i;
                }
            }
            if(is_left == 1){
                // Hand.erase(Hand.begin()+ real_is_left_num);
                return is_left_b;
            }
            else{
                // Hand.erase(Hand.begin()+ max_iterator);
                return max;
                // return play_card(max,trump);
            }
        }
        else{
            int counter = 0;
            Card max;
            for(int i = 0; i < Hand.size(); i++){
                if(Hand[i].get_suit() != trump){
                    Card max = Hand[i];
                    break;
                }
            }
            for(int i = 0; i < Hand.size(); i++){
                if((operator>(Hand[i], max)) &&  Hand[i].get_suit()!= trump){
                    max = Hand[i];
                    counter = i;
                }
            }
            Hand.erase(Hand.begin()+ counter);
            return max;
            // return play_card(max,trump);
        }
    }
    
    //REQUIRES Player has at least one card, trump is a valid suit
    //EFFECTS  Plays one Card from Player's hand according to their strategy.
    //  The card is removed from the player's hand
    Card play_card(const Card &led_card, const std::string &trump){
        Card highest_follow_suit;
//int counter = 0;
        int the_counter = 0;
        bool has_follow_suit = false;
        for(int i = 0; i < Hand.size(); i++){
            if(Hand[i].get_suit() == led_card.get_suit()){
                highest_follow_suit = Hand[i];
                has_follow_suit = true;
                break;
            }
        }
        if(has_follow_suit == true){
            for(int i = 0; i < Hand.size(); i++){
            //    counter +=1;
                if(Hand[i].get_suit() == led_card.get_suit() && operator>=(Hand[i],highest_follow_suit)){
                    highest_follow_suit = Hand[i];
                    the_counter = i;
                }
            }
            Hand.erase(Hand.begin()+ the_counter);
            return highest_follow_suit;
        }
        else{
            Card min = Hand[0];
            for(int i = 0; i < Hand.size(); i++){
               // counter +=1;
                if(Card_less(Hand[i],min,trump)){
                    the_counter = i;
                    min = Hand[i];
                }
            }
            Hand.erase(Hand.begin()+ the_counter);
            return min;
        }
    }
    
    ~Simple() {}
};
    

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
    assert(false);
    return nullptr;
}
    //EFFECTS: Prints player's name to os
std::ostream & operator<<(std::ostream &os, const Player &p) {
    return os << p.get_name();
}

//SIMPLE

//Simple::Simple(std::string name_in) {
//    name = name_in;
//
//}
//    //EFFECTS returns player's name
//const std::string & Simple::get_name() const{
//    return name;
//}
//
//    //REQUIRES player has less than MAX_HAND_SIZE cards
//    //EFFECTS  adds Card c to Player's hand
//void Simple::add_card(const Card &c){
//    if (static_cast<int>(Hand.size()) < MAX_HAND_SIZE) {
//        Hand.push_back(c);
//    }
//}
//
//    //REQUIRES round is 1 or 2
//    //MODIFIES order_up_suit
//    //EFFECTS If Player wishes to order up a trump suit then return true and
//    //  change order_up_suit to desired suit.  If Player wishes to pass, then do
//    //  not modify order_up_suit and return false.
//bool Simple::make_trump(const Card &upcard, bool is_dealer,
//                        int round, std::string &order_up_suit) const{
//    int count_of_upcard = 0;
//    string other_suit;
//    int count_round2 = 0;
//    if(round == 1){
//        for(int i = 0; i < Hand.size(); i++){
//            if(Hand[i].get_suit() == upcard.get_suit() && (Hand[i].is_face_or_ace() || Hand[i].is_left_bower(upcard.get_suit()) || Hand[i].is_right_bower(upcard.get_suit()))){
//                count_of_upcard += 1;
//            }
//        }
//        if(count_of_upcard >=2){
//            order_up_suit = upcard.get_suit();
//            return true;
//        }
//        else{
//            return false;
//        }
//
//    }
//    //Round 2
//    else{
//        if(is_dealer){
//            string suit = upcard.get_suit();
//            if(suit == upcard.SUIT_CLUBS){
//                order_up_suit = upcard.SUIT_SPADES;
//            }
//            else if(suit == upcard.SUIT_SPADES){
//                order_up_suit = upcard.SUIT_CLUBS;
//            }
//            else if(suit == upcard.SUIT_DIAMONDS){
//                order_up_suit = upcard.SUIT_HEARTS;
//            }
//            else{
//                order_up_suit = upcard.SUIT_DIAMONDS;
//            }
//            return true;
//        }
//        else{
//            string suit = upcard.get_suit();
//            if(suit == upcard.SUIT_CLUBS){
//                other_suit = upcard.SUIT_SPADES;
//            }
//            else if(suit == upcard.SUIT_SPADES){
//                other_suit = upcard.SUIT_CLUBS;
//            }
//            else if(suit == upcard.SUIT_DIAMONDS){
//                other_suit = upcard.SUIT_HEARTS;
//            }
//            else{
//                other_suit = upcard.SUIT_DIAMONDS;
//            }
//
//            for(int i = 0; i < Hand.size(); i++){
//                if(Hand[i].get_suit() == other_suit){
//                    count_round2 +=1;
//                }
//            }
//            if(count_round2 >= 1){
//                order_up_suit = other_suit;
//                return true;
//            }
//            else{
//                return false;
//            }
//        }
//    }
//
//}
//
//    //REQUIRES Player has at least one card
//    //EFFECTS  Player adds one card to hand and removes one card from hand.
//void Simple::add_and_discard(const Card &upcard){
//    Card min = Hand[0];
//    int min_num = 0;
//    for(int i = 0; i < 5; i++){
//        if(Card_less(Hand[i],min, upcard.get_suit())){
//            min = Hand[i];
//            min_num = i;
//        }
//    }
//    Hand.erase(Hand.begin()+(min_num - 1));
//    add_card(upcard);
//
//}
//
//    //REQUIRES Player has at least one card, trump is a valid suit
//    //EFFECTS  Leads one Card from Player's hand according to their strategy
//    //  "Lead" means to play the first Card in a trick.  The card
//    //  is removed the player's hand.
//Card Simple::lead_card(const std::string &trump){
//    int has_all_trump = 0;
//    for(int i = 0; i < Hand.size(); i++){
//        if(Hand[i].get_suit() == trump){
//            has_all_trump += 1;
//        }
//    }
//    if(has_all_trump == Hand.size()){
//        //plays highest value card
//        Card max = Hand[0];
//        for(int i = 0; i < Hand.size(); i++){
//            if(operator>(Hand[i], max)){
//                max = Hand[i];
//            }
//        }
//        return play_card(max,trump);
//    }
//    else{
//        Card max;
//        for(int i = 0; i < Hand.size(); i++){
//            if(Hand[i].get_suit() != trump){
//                Card max = Hand[i];
//                break;
//            }
//       }
//        for(int i = 0; i < Hand.size(); i++){
//            if((operator>(Hand[i], max)) &&  Hand[i].get_suit()!= trump){
//                max = Hand[i];
//            }
//    }
//        return play_card(max,trump);
// }
//}
//
//    //REQUIRES Player has at least one card, trump is a valid suit
//    //EFFECTS  Plays one Card from Player's hand according to their strategy.
//    //  The card is removed from the player's hand
//Card Simple::play_card(const Card &led_card, const std::string &trump){
//     Card highest_follow_suit;
//     bool has_follow_suit = false;
//     for(int i = 0; i < Hand.size(); i++){
//         if(Hand[i].get_suit() == led_card.get_suit()){
//             highest_follow_suit = Hand[i];
//             has_follow_suit = true;
//             break;
//         }
//     }
//     if(has_follow_suit == true){
//         for(int i = 0; i < Hand.size(); i++){
//             if(Hand[i].get_suit() == led_card.get_suit() && operator>(Hand[i],highest_follow_suit)){
//                 highest_follow_suit = Hand[i];
//             }
//         }
//         return highest_follow_suit;
//     }
//     else{
//         Card min = Hand[0];
//         for(int i = 0; i < Hand.size(); i++){
//             if(operator<(Hand[i],min)){
//                 min = Hand[i];
//             }
//         }
//        return min;
//     }
//}