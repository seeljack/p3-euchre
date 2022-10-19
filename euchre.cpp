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
        turns = points_to_win;
    }
        void play(){
          shuffle(do_shuffle);
          deal(players[0],players[1],players[2],players[3],upcard);
          make_trump(players[0],players[1],players[2],players[3],upcard);
        }
    
    private:
        std::vector<Player*> players;
        Pack pack;
        bool do_shuffle;
        int turns;
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
          else if(dealer % 3 == 3){
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




        void make_trump(Player* p1, Player* p2, Player* p3, Player* p4, Card &upcard){
          bool c1 = false;
          bool c2 = false;
          bool c3 = false;
          bool c4 = false;
          int round = 1;
          string s;
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
          if(p1->make_trump(upcard,c1,round,s)){
            cout << "sucsess";
          }
          else if(p2->make_trump(upcard,c2,round,s)){
            cout << "sucsess";
          }
          else if(p3->make_trump(upcard,c3,round,s)){
            cout << "sucsess";
          }
          else if(p4->make_trump(upcard,c4,round,s)){
            cout << "sucsess";
          }
          else{
            cout << "Doing round two";
          }
        }

        void play_hand(/* ... */);

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
        Game game(do_shuffle, points_to_win, p1, p2, p3, p4, pack_in);
        game.play();
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
