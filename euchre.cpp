/* euchre.cpp
 *
 * Run euchre gameplay
 * Project UID 1d9f47bfc76643019cfbf037641defe1
 *
 * by Josh Cussen and Jack Seel
 * jcussen@umich.edu and seeljack@umich.edu
 * 10/9/22
 */


#include "Card.h"
#include "Pack.h"
#include "Player.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Game{
    public:
    Game(bool shuffle_in, int points_to_win, Player* p1, Player* p2, Player* p3, Player* p4, Pack pack_in) {
        
        players.push_back(p1);
        players.push_back(p2);
        players.push_back(p3);
        players.push_back(p4);
        pack = pack_in;
        do_shuffle = shuffle_in;
        // shuffle(shuffle_in);
        points_win = points_to_win;
    }
    
    void play(){
        while (points_t1 < points_win && points_t2 < points_win) {
            string trump;
            int trump_maker;
            shuffle(do_shuffle);
            deal(players[0],players[1],players[2],players[3],upcard);
            trump_maker = make_trump(players[0],players[1],players[2],players[3],upcard,trump);
            play_round(trump, dealer, trump_maker);
        }
        if (points_t1 == points_win) {
            cout << players[0]->get_name() << " and " << players[2]->get_name() \
            << " win!" << endl;
            return;
        }
        else {
            cout << players[1]->get_name() << " and " << players[3]->get_name() \
            << " win!" << endl;
            return;
        }
    }
    ~Game() {}
    
    private:
        std::vector<Player*> players;
        Pack pack;
        bool do_shuffle;
        int points_win;
    //team's game points
        int points_t1 = 0;
        int points_t2 = 0;
        int dealer = 0;
        Card upcard;


        //Shuffles deck if do_shuffle is true. Else if do_shuffle is false, it resets
        void shuffle(bool do_shuffle){
          if(do_shuffle){
            pack.shuffle();
            cout << "is shuffled";
          }
          else{
            pack.reset();
          }
        }

        //Deals4 players cards in 3232 2323 order. Then turns up the next  card(upcard)
        void deal(Player* p1, Player* p2, Player* p3, Player* p4, Card &upcard){
          Card dealt;
          //p1 is dealer
          if(dealer % 4 ==  0){
            //First Deal
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p2->add_card(dealt);
            }
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p3->add_card(dealt);
            }
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p4->add_card(dealt);
            }
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p1->add_card(dealt);
            }
            //Second Deal
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p2->add_card(dealt);
            }
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p3->add_card(dealt);
            }
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p4->add_card(dealt);
            }
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p1->add_card(dealt);
            }
          }
          //p2 is dealer
          else if(dealer % 4 == 1){
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p3->add_card(dealt);
            }
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p4->add_card(dealt);
            }
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p1->add_card(dealt);
            }
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p2->add_card(dealt);
            }
            //Second Deal
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p3->add_card(dealt);
            }
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p4->add_card(dealt);
            }
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p1->add_card(dealt);
            }
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p2->add_card(dealt);
            }
          }

         //p3 is dealer
          else if(dealer % 4 == 2){
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p4->add_card(dealt);
            }
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p1->add_card(dealt);
            }
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p2->add_card(dealt);
            }
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p3->add_card(dealt);
            }
            //Second Deal
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p4->add_card(dealt);
            }
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p1->add_card(dealt);
            }
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p2->add_card(dealt);
            }
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p3->add_card(dealt);
            }
          }

          //p4 is dealer
          else if(dealer % 4 == 3){
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p1->add_card(dealt);
            }
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p2->add_card(dealt);
            }
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p3->add_card(dealt);
            }
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p4->add_card(dealt);
            }
            //Second Deal
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p1->add_card(dealt);
            }
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p2->add_card(dealt);
            }
            for(int i = 0; i < 2; i ++){
              dealt = pack.deal_one();
              p3->add_card(dealt);
            }
            for(int i = 0; i < 3; i ++){
              dealt = pack.deal_one();
              p4->add_card(dealt);
            }
          }
          dealer += 1;
          dealt = pack.deal_one();
          upcard = dealt;
        }

    int make_trump(Player* p1, Player* p2, Player* p3, Player* p4, Card &upcard, string& trump){
          bool c1 = false;
          bool c2 = false;
          bool c3 = false;
          bool c4 = false;
          int round = 1;
       //   string s;
          if(dealer % 4 == 0){
            c1 = true;
          }
          else if(dealer % 4 == 1){
            c2 = true;
          }
          else if(dealer % 4 == 2){
            c3 = true;
          }
          else if(dealer % 4 == 3){
            c4 = true;
          }
        
          if(p1->make_trump(upcard,c1,round,trump)){
            cout << "sucess";
          }
        
          else if(p2->make_trump(upcard,c2,round,trump)){
            cout << p1->get_name() << "passes" << endl;
            cout << "sucess";
          }
        
          else if(p3->make_trump(upcard,c3,round,trump)){
            cout << p2->get_name() << "passes" << endl;
            cout << "sucess";
          }
        
          else if(p4->make_trump(upcard,c4,round,trump)){
              cout << p3->get_name() << "passes" << endl;
            cout << "sucess";
          }
          else{
            cout << p4->get_name() << "passes" << endl;
            cout << "Doing round two";
            round = 2;
            if(p1->make_trump(upcard,c1,round,trump)){
              cout << "sucess";
            }
            else if(p2->make_trump(upcard,c2,round,trump)){
              cout << p1->get_name() << "passes" << endl;
              cout << "sucess";
            }
            else if(p3->make_trump(upcard,c3,round,trump)){
              cout << p2->get_name() << "passes" << endl;
              cout << "sucess";
            }
            else if(p4->make_trump(upcard,c4,round,trump)){
              cout << p3->get_name() << "passes" << endl;
              cout << "sucess";
          }
          }
          cout << "\n" << " The suit is " << trump << "\n";
          return -1;
        }
    //needs to know what trump is, who dealer is, and who made trump
    //needs to award points based on who won the hand, including getting euchered
    void play_round(string trump, int dealer, int trump_maker) {
        int trick_winner; //trick winner, they will lead the next hand
        int tricks_won_t1 = 0; //tracks tricks won to award points
        int tricks_won_t2 = 0;
        int trump_team = 0; //the team who made trump, in case they get euchered
        
        if (trump_maker % 4 == 0 || trump_maker % 4 == 2) {
            trump_team = 1;
        }
        else if (trump_maker % 4 == 1 || trump_maker % 4 == 3) {
            trump_team = 2;
        }
        //to the left of dealer leads off
        trick_winner = play_trick(trump, (dealer) % 4);
        cout << players[trick_winner]->get_name() << " takes the trick" << endl;
        
        for (int i = 1; i < 5; i++) {
            trick_winner = play_trick(trump, trick_winner);
            cout << players[trick_winner]->get_name() << " takes the trick" << endl;
            if (trick_winner == 1 || trick_winner == 3) {
                tricks_won_t1++;
            }
            else if (trick_winner == 2 || trick_winner == 4) {
                tricks_won_t2++;
            }
        }
        
        if (tricks_won_t1 > tricks_won_t2) {
            cout << players[0]->get_name() << " and " << players[2]->get_name() \
            << " win the hand" << endl;
            if (trump_team == 2) { //for euchre
                points_t1 += 2;
                cout << "euchred!" << endl;
            }
            else {
                points_t1++;
            }
        }
        else{
            if (trump_team == 1) {  //for euchre
                points_t2 += 2;
                cout << "euchred!" << endl;
            }
            else {
                points_t1++;
            }
        }
        cout << "\n" ;
        cout << players[0]->get_name() << " and " << players[2]->get_name() << " have "<< points_t1 << "\n" << players[1]->get_name() << " and " << players[3]->get_name() << " have " << points_t2 << "\n";
    }
    //need to know who leads and what the trump is
    //needs to return who won the hand
    int play_trick(string trump, int lead) {
        Card c1 = players[lead % 4]->lead_card(trump);
        cout << c1 << " lead by " << players[lead]->get_name() << endl;
        
        Card c2 = players[(lead + 1) % 4]->play_card(c1, trump);
        cout << c2 << " played by " << players[(lead + 1) % 4]->get_name() << endl;
        
        Card c3 = players[(lead + 2) % 4]->play_card(c1, trump);
        cout << c3 << " played by " << players[(lead + 2) % 4]->get_name() << endl;
        
        Card c4 = players[(lead + 3) % 4]->play_card(c1, trump);
        cout << c4 << " played by " << players[(lead + 3) % 4]->get_name() << endl;

        Card winner = trick_winner(c1, c2, c3, c4, trump);
        if (winner == c1) {
            return lead;
        }
        else if (winner == c2) {
            return (lead + 1) % 4;
        }
        else if (winner == c3) {
            return (lead + 2) % 4 ;
        }
        else {
            return (lead + 3) % 4;
        }
    }
    
    Card trick_winner(Card c1, Card c2, Card c3, Card c4, string trump) {
        if (!Card_less(c1, c2, trump) && !Card_less(c1, c3, trump) && !Card_less(c1, c4, trump)) {
            return c1;
        }
        else if (!Card_less(c2, c1, trump) && !Card_less(c2, c3, trump) && !Card_less(c2, c4, trump)) {
            return c2;
        }
        else if (!Card_less(c3, c1, trump) && !Card_less(c3, c2, trump) && !Card_less(c3, c4, trump)) {
            return c3;
        }
        else {
            return c4;
        }
    }
};






int main(int argc, char **argv) {
    // ./euchre.exe pack.in shuffle 10 Edsger Simple Fran Simple Gabriel Simple Herb Simple
    // if(argc != 12){
    //   cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
    //   << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
    //   << "NAME4 TYPE4" << endl;
    // }
    // else if(!(atoi(argv[3]) >= 1 && atoi(argv[3]) <= 100)){
    //   cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
    //   << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
    //   << "NAME4 TYPE4" << endl;
    // }
    // else if(!(argv[2] == "shuffle" || argv[2] == 'noshuffle')){
    //   cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
    //   << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
    //   << "NAME4 TYPE4" << endl;
    // }
    // else if(!(argv[5] == "Simple" || argv[5] == "Human")){
    //   cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
    //   << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
    //   << "NAME4 TYPE4" << endl;
    // }
    // else if(!(argv[7] == "Simple" || argv[7] == "Human")){
    //   cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
    //   << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
    //   << "NAME4 TYPE4" << endl;
    // }
    // else if(!(argv[9] == "Simple" || argv[9] == "Human")){
    //   cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
    //   << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
    //   << "NAME4 TYPE4" << endl;
    // }
    // else if(!(argv[11] == "Simple" || argv[11] == "Human")){
    //   cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
    //   << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
    //   << "NAME4 TYPE4" << endl;
    // }
    ifstream is;
    is >> *argv[1];
    is.open(argv[1]);
    string pack_filename = argv[1];
    string shuffle = argv[2];
    bool do_shuffle;
    if(shuffle == "shuffle"){
        do_shuffle = true;
    }
    else{
        do_shuffle = false;
    }
    int points_to_win = atoi(argv[3]);
    
    if(!is.is_open()){
      cout << "Error opening " << pack_filename << endl;
    }

    Player* p1 = Player_factory(argv[4], argv[5]);
    Player* p2 = Player_factory(argv[6], argv[7]);
    Player* p3 = Player_factory(argv[8], argv[9]);
    Player* p4 = Player_factory(argv[10], argv[11]);
    Pack pack_in(is);
    
    Game* game = new Game(do_shuffle, points_to_win, p1, p2, p3, p4, pack_in);
    game->play();
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete game;
    return 0;
}

  // Read command line args and check for errors
//   Game game(/* game details */);
//   game.play();

// Euchre.cpp plan

// -Read in all inputs through argv
// -Initialize players and pack
// -Make a new game with constructor that has these players, pack, plus shuffle instructions and amount of turns

// -The game class will then run the whole game, with a loop that runs every trick, running for the number of turns provided
// -the play function will do this and will probably be the bulk of the code

// -We might need a system to track points and declare a winner





//./euchre.exe pack.in noshuffle 10 Edsger Simple Fran Simple Gabriel Simple Herb Simple