// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include "unit_test_framework.h"

#include <iostream>

using namespace std;

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());
    delete alice;
}

TEST(test_player_add_cards) {
    Human * alice = new Human("Alice");
    Card c1(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card c2(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c3(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card c4(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c5(Card::RANK_TEN, Card::SUIT_SPADES);
    alice->add_card(c1);
    alice->add_card(c2);
    alice->add_card(c3);
    alice->add_card(c4);
    alice->add_card(c5);
    ostringstream os;
    
    alice->print_hand();
}

// Add more tests here

TEST_MAIN()
