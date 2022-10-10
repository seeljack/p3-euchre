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

TEST(test_simple_make_trump) {
    Player * alice = Player_factory("Alice", "Simple");
    Card c1(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c2(Card::RANK_KING, Card::SUIT_SPADES);
    Card c3(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card c4(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c5(Card::RANK_TEN, Card::SUIT_SPADES);
    Card upcard(Card::RANK_QUEEN, Card::SUIT_SPADES);
    string s;
    
    alice->add_card(c1);
    alice->add_card(c2);
    alice->add_card(c3);
    alice->add_card(c4);
    alice->add_card(c5);
    assert(alice->make_trump(upcard, false, 1, s));
    ASSERT_EQUAL(s, Card::SUIT_SPADES);
}

TEST(test_simple_lead) {
    Player * alice = Player_factory("Alice", "Simple");
    Card c1(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c2(Card::RANK_KING, Card::SUIT_SPADES);
    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c4(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c5(Card::RANK_TEN, Card::SUIT_SPADES);
    string s;
    
    alice->add_card(c1);
    alice->add_card(c2);
    alice->add_card(c3);
    alice->add_card(c4);
    alice->add_card(c5);
    
    ASSERT_TRUE(c1 == alice->lead_card(Card::SUIT_SPADES));

}
TEST(test_simple_play_card) {
    Player * alice = Player_factory("Alice", "Simple");
    Card c1(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c2(Card::RANK_KING, Card::SUIT_SPADES);
    Card c3(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card c4(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c5(Card::RANK_TEN, Card::SUIT_SPADES);
    Card upcard(Card::RANK_ACE, Card::SUIT_CLUBS);
    string s;
    
    alice->add_card(c1);
    alice->add_card(c2);
    alice->add_card(c3);
    alice->add_card(c4);
    alice->add_card(c5);
    
    ASSERT_TRUE(c3 == alice->play_card(upcard, Card::SUIT_DIAMONDS));
}
// Add more tests here

TEST_MAIN()
