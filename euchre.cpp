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
        Game(/* ... */);
        void play();
    
    private:
        std::vector<Player*> players;
        Pack pack;


        //Shuffles deck if do_shuffle is true. Else if do_shuffle is false, it resets
        void shuffle(bool do_shuffle){
          if(do_shuffle){
            pack.shuffle();
          }
          else{
            pack.reset();
          }
        }

        
        void deal(/* ... */);
        void make_trump(/* ... */);
        void play_hand(/* ... */);

};






int main(int argc, char **argv) {
   ifstream is;
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
    is >> *argv[1];
    is.open(argv[1]);
    string pack_filename = argv[1];
    if(!is.is_open()){
      cout << "Error opening " << pack_filename << endl;
    }
    else{
      string is_shuffle;
      bool do_shuffle;
      is_shuffle = argv[2];
      if(is_shuffle == "shuffle"){
        do_shuffle = true;
      }
      else{
        do_shuffle = false;
      }
      cout << do_shuffle;
    }

  // Read command line args and check for errors
//   Game game(/* game details */);
//   game.play();
}
