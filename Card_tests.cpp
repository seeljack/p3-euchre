// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "unit_test_framework.h"
#include <iostream>
#include <assert.h>

using namespace std;


TEST(test_card_ctor) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit());
}

TEST(test_get_suit) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    
    ASSERT_EQUAL(c.get_suit(Card::SUIT_SPADES), Card::SUIT_SPADES);
    ASSERT_EQUAL(c.get_suit(Card::SUIT_CLUBS), Card::SUIT_CLUBS);
    ASSERT_EQUAL(c.get_suit(Card::SUIT_DIAMONDS), Card::SUIT_SPADES);
}

TEST(test_is_face_or_ace) {
    Card c1(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card c2(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c3(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card c4(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c5(Card::RANK_TEN, Card::SUIT_SPADES);
    Card c6(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    
    ASSERT_TRUE(c1.is_face_or_ace());
    ASSERT_TRUE(c2.is_face_or_ace());
    ASSERT_TRUE(c3.is_face_or_ace());
    ASSERT_TRUE(c4.is_face_or_ace());
    ASSERT_FALSE(c5.is_face_or_ace());
    ASSERT_FALSE(c6.is_face_or_ace());
}

TEST(test_is_bowers) {
    Card c1(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c2(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card c3(Card::RANK_KING, Card::SUIT_CLUBS);
    
    ASSERT_TRUE(c1.is_right_bower(Card::SUIT_SPADES));
    ASSERT_TRUE(c1.is_left_bower(Card::SUIT_CLUBS));
    
    ASSERT_FALSE(c2.is_right_bower(Card::SUIT_SPADES));
    ASSERT_FALSE(c2.is_left_bower(Card::SUIT_DIAMONDS));
    
    ASSERT_FALSE(c3.is_right_bower(Card::SUIT_CLUBS));
    ASSERT_FALSE(c3.is_left_bower(Card::SUIT_CLUBS));
    
}

TEST(test_is_trump) {
    Card c1(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card c2(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c3(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card c4(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c5(Card::RANK_TEN, Card::SUIT_SPADES);
    Card c6(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    
    ASSERT_TRUE(c1.is_trump(Card::SUIT_HEARTS));
    ASSERT_TRUE(c2.is_trump(Card::SUIT_DIAMONDS));
    ASSERT_TRUE(c3.is_trump(Card::SUIT_CLUBS));
    ASSERT_TRUE(c4.is_trump(Card::SUIT_SPADES));
    ASSERT_TRUE(c4.is_trump(Card::SUIT_CLUBS));
    
    ASSERT_FALSE(c4.is_trump(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c5.is_trump(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c6.is_trump(Card::SUIT_HEARTS));
}

TEST(test_suit_next){
    ASSERT_EQUAL(Suit_next(Card::SUIT_SPADES), Card::SUIT_CLUBS);
    ASSERT_EQUAL(Suit_next(Card::SUIT_HEARTS), Card::SUIT_DIAMONDS);
}

TEST(test_overloading) {
    Card c1(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card c2(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c3(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card c4(Card::RANK_QUEEN, Card::SUIT_SPADES);
    ASSERT_TRUE(c2 < c1);
    ASSERT_TRUE(c2 <= c1);
    ASSERT_TRUE(c3 < c1);
    ASSERT_FALSE(c1 < c2);
    ASSERT_FALSE(c1 <= c2);
    
    
    ASSERT_TRUE(c1 > c2);
    ASSERT_TRUE(c1 >= c2);
    ASSERT_TRUE(c2 > c3);
    ASSERT_FALSE(c3 > c1);
    ASSERT_FALSE(c3 >= c1);
    
    ASSERT_TRUE(c4 == c4);
    ASSERT_FALSE(c1 == c2);
    ASSERT_TRUE(c1 != c2);
    ASSERT_FALSE(c3 != c3);
}

TEST(test_card_less1) {
    Card c1(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card c2(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c3(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card c4(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c5(Card::RANK_TEN, Card::SUIT_SPADES);
    Card c6(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    
    ASSERT_TRUE(Card_less(c2, c1, Card::SUIT_CLUBS));
    ASSERT_TRUE(Card_less(c4, c3, Card::SUIT_DIAMONDS));
    ASSERT_TRUE(Card_less(c5, c4, Card::SUIT_SPADES));
    ASSERT_TRUE(Card_less(c1, c2, Card::SUIT_DIAMONDS));
    ASSERT_TRUE(Card_less(c1, c6, Card::SUIT_DIAMONDS));
    
    ASSERT_FALSE(Card_less(c5, c2, Card::SUIT_SPADES));
}

TEST(test_card_less2) {
    Card c1(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card c2(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c3(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card c4(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c5(Card::RANK_TEN, Card::SUIT_SPADES);
    Card c6(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    
    ASSERT_TRUE(Card_less(c2, c1, c1, Card::SUIT_CLUBS));
    ASSERT_TRUE(Card_less(c4, c3, c2, Card::SUIT_DIAMONDS));
    ASSERT_TRUE(Card_less(c1, c4, Card::SUIT_SPADES));
    ASSERT_TRUE(Card_less(c3, c6, c6, Card::SUIT_HEARTS));
    ASSERT_TRUE(Card_less(c1, c4, Card::SUIT_CLUBS));
    
    ASSERT_FALSE(Card_less(c5, c2, c5, Card::SUIT_HEARTS));
    ASSERT_FALSE(Card_less(c4, c1, c5, Card::SUIT_DIAMONDS));
    ASSERT_FALSE(Card_less(c4, c1, c1, Card::SUIT_SPADES));
    ASSERT_FALSE(Card_less(c4, c1, c1, Card::SUIT_CLUBS));
}
// Add more test cases here

TEST_MAIN()
