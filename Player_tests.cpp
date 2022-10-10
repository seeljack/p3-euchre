// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include "unit_test_framework.h"

#include <iostream>
#include <cassert>

using namespace std;

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());
    delete alice;
}
//During round one, a Simple Player considers ordering up the suit of the upcard, which would make that suit trump. They will order up if that would mean they have two or more cards that are either face or ace cards of the trump suit (the right and left bowers, and Q, K, A of the trump suit, which is the suit proposed by the upcard). (A Simple Player does not consider whether they are the dealer and could gain an additional trump by picking up the upcard.)
//
//During round two, a Simple Player considers ordering up the suit with the same color as the upcard, which would make that suit trump. They will order up if that would mean they have one or more cards that are either face or ace cards of the trump suit in their hand (the right and left bowers, and Q, K, A of the order-up suit). For example, if the upcard is a Heart and the player has the King of Diamonds in their hand, they will order up Diamonds. The Simple Player will not order up any other suit. If making reaches the dealer during the second round, we invoke screw the dealer, where the dealer is forced to order up. In the case of screw the dealer, the dealer will always order up the suit with the same color as the upcard.

TEST(test_simple_make_trump) {
    Player * alice = Player_factory("Alice", "Simple");
    Card c1(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c2(Card::RANK_KING, Card::SUIT_SPADES);
    Card c3(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card c4(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c5(Card::RANK_TEN, Card::SUIT_SPADES);
    Card upcard1(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card upcard2(Card::RANK_QUEEN, Card::SUIT_HEARTS);
    string s;
    
    alice->add_card(c1);
    alice->add_card(c2);
    alice->add_card(c3);
    alice->add_card(c4);
    alice->add_card(c5);
    //round 1
    assert(alice->make_trump(upcard1, false, 1, s));
    ASSERT_EQUAL(s, Card::SUIT_SPADES);
    s = "";
    assert(!alice->make_trump(upcard2, false, 1, s));
    //round 2
    assert(alice->make_trump(upcard1, false, 2, s));
    ASSERT_EQUAL(s, Card::SUIT_CLUBS);
    assert(alice->make_trump(upcard2, true, 2, s));
    ASSERT_EQUAL(s, Card::SUIT_DIAMONDS);
    
    delete alice;
}
//
//When a Simple Player leads a trick, they play the highest non-trump card in their hand. If they have only trump cards, they play the highest trump card in their hand.
TEST(test_simple_lead) {
    Player * alice = Player_factory("Alice", "Simple");
    Card c1(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c2(Card::RANK_KING, Card::SUIT_SPADES);
    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c4(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c5(Card::RANK_TEN, Card::SUIT_SPADES);
    Card c6(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    
    alice->add_card(c1);
    alice->add_card(c2);
    alice->add_card(c3);
    alice->add_card(c4);
    alice->add_card(c5);
    
    ASSERT_TRUE(c4 == alice->lead_card(Card::SUIT_SPADES));
    ASSERT_TRUE(c1 == alice->lead_card(Card::SUIT_HEARTS));
    ASSERT_TRUE(c1 == alice->lead_card(Card::SUIT_DIAMONDS));
    ASSERT_TRUE(c1 == alice->lead_card(Card::SUIT_CLUBS));
    
    alice->add_and_discard(c6);
    
    ASSERT_TRUE(c6 == alice->lead_card(Card::SUIT_SPADES));
    ASSERT_TRUE(c1 == alice->lead_card(Card::SUIT_HEARTS));
    ASSERT_TRUE(c1 == alice->lead_card(Card::SUIT_DIAMONDS));
    ASSERT_TRUE(c1 == alice->lead_card(Card::SUIT_CLUBS));
    
    delete alice;
}
//
//When playing a card, Simple Players use a simple strategy that considers only the suit that was led. A more complex strategy would also consider the cards on the table.
//
//If a Simple Player can follow suit, they play the highest card that follows suit. Otherwise, they play the lowest card in their hand.
TEST(test_simple_play_card) {
    Player * alice = Player_factory("Alice", "Simple");
    Card c1(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c2(Card::RANK_KING, Card::SUIT_SPADES);
    Card c3(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card c4(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c5(Card::RANK_TEN, Card::SUIT_SPADES);
    Card upcard1(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card upcard2(Card::RANK_QUEEN, Card::SUIT_HEARTS);
    
    alice->add_card(c1);
    alice->add_card(c2);
    alice->add_card(c3);
    alice->add_card(c4);
    alice->add_card(c5);
    
    ASSERT_TRUE(c3 == alice->play_card(upcard1, Card::SUIT_DIAMONDS));
    ASSERT_TRUE(c5 == alice->play_card(upcard2, Card::SUIT_DIAMONDS));
    ASSERT_TRUE(c5 == alice->play_card(upcard2, Card::SUIT_SPADES));
    delete alice;
}

TEST(test_small_add){
    Player * alice = Player_factory("Alice", "Simple");
    Card c1(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c3(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    alice->add_card(c1);
    Card upcard2(Card::RANK_QUEEN, Card::SUIT_HEARTS);

    alice->add_and_discard(upcard2);

    ASSERT_TRUE(upcard2 == alice->play_card(c3,Card::SUIT_SPADES));

    delete alice;
}

TEST(test_lead_card_only_trump){
    Player * alice = Player_factory("Alice", "Simple");
    Card c1(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c2(Card::RANK_KING, Card::SUIT_SPADES);
    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c4(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c5(Card::RANK_TEN, Card::SUIT_SPADES);
    Card upcard1(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card upcard2(Card::RANK_QUEEN, Card::SUIT_HEARTS);
    Card upcard3(Card::RANK_NINE, Card::SUIT_DIAMONDS);

    alice->add_card(c1);
    alice->add_card(c2);
    alice->add_card(c3);
    alice->add_card(c4);
    alice->add_card(c5);

    ASSERT_TRUE(c4 == alice->lead_card(Card::SUIT_SPADES));
    ASSERT_TRUE(c5 == alice->play_card(upcard1,Card::SUIT_CLUBS));
    ASSERT_EQUAL(c3, alice->play_card(upcard2,Card::SUIT_CLUBS));
    ASSERT_TRUE(c2 == alice->play_card(upcard1,Card::SUIT_CLUBS));
    ASSERT_TRUE(c1 == alice->play_card(upcard3,Card::SUIT_CLUBS));

    delete alice;
}

TEST(test_new){
    Player * alice = Player_factory("Alice", "Simple");
    Card c1(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c2(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c4(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c5(Card::RANK_TEN, Card::SUIT_SPADES);
    Card upcard100(Card::RANK_KING, Card::SUIT_SPADES);
    Card upcard2(Card::RANK_QUEEN, Card::SUIT_HEARTS);
    Card upcard3(Card::RANK_NINE, Card::SUIT_DIAMONDS);

    alice->add_card(c1);
    alice->add_card(c2);
    alice->add_card(c3);
    alice->add_card(c4);
    alice->add_card(c5);

    ASSERT_EQUAL(c4,alice->play_card(upcard100,Card::SUIT_SPADES));


}
// Add more tests here

TEST_MAIN()
