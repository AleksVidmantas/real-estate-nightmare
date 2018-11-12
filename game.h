#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "property.h"

class Game{

    private:
        Player player; //single player, user of program      
        Property** properties = NULL; //list of all properties to be used in game, set in constructor  
        int num_properties = 0;
        char cont; //char will be yes by default
    public: 
        bool get_continue();
        Game();
        void initialize_game();
        Property generate_property(int tier, int budget);
        void loop();
        Locations rand_location();
        bool p_has_won();
        void remove_property(int index);
        int rand_price(int budget);
        void exit();
        ~Game();
};



#endif