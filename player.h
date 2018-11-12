#ifndef PLAYER_H
#define PLAYER_H
#include "property.h"
/*
 * Serves as player, keeps track of score and properties.  One exists.
*/
class Player{
    private:
        int money;
        int num_properties = 0;
        Property** properties = NULL; //null to keep a lock down on memory
        

    public:
        void set_money(int money);
        int get_money();
        void sell_building(int index);
        void add_property(Property *p); //pass by reference to save memory
        Property** get_properties();
        void pay_mortage();
        void reap_rent();
        int get_num_properties();
        void pay_taxes();
        ~Player();
};

#endif