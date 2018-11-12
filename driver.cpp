#define NDEBUG
#include <iostream>
using namespace std;
#include "house.h"
#include "complex.h"
#include "player.h"
#include "game.h"
#include "property.h"

int main(){
   
    Game g;

   Property** prop1 = new Property*[5]; 
   prop1[0] = new Property;
   prop1[1] = new Property;
   prop1[2] = new Property;
   prop1[3] = new Property;
   if(prop1[4] == NULL){
       cout << "NULL" << endl;
   }

   for(int i = 0; i < 4; i++){
       delete prop1[i];
   }
   delete [] prop1;
   /* Complex c;
    
    Player me;
    me.add_property(h);
    me.add_property(c);
    Game game;
    cout << me.get_properties()[0].get_num_tenants()<< endl;
*/
    return 0;
}
