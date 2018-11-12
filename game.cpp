#include "game.h"
#include "house.h"
#include <iostream>
#include <ctime>
using namespace std;

bool Game::get_continue(){
    if(this->cont == 'y'){
        return true;
    }else{
        return false;
    }
}

/*
 * Game logic here, not setup. loopy
*/
int turn_to_tax = 12;
void Game::loop(){
    if(player.get_money() < 0) {
        cout << "Bankrupt, now leave" << endl;
        exit();
    }
    turn_to_tax -= 1;
    if(turn_to_tax == 0){
        cout << "Tax time!!! " << endl;
        player.pay_taxes();
        turn_to_tax = 12; 
    }
    
    //cout << "Line" << endl;
    char option;
    player.reap_rent();
    player.pay_mortage();
    cout << "Would you like to buy (b), sell (s), adjust rent (r), or pass (p)? ";
    cin >> option;
    //payment info
    


    //option branch
    switch(option){
        case('b'):
            cout << "Your options... " << endl;
            cout << "--------------------------------" << endl;
            for(int i = 0; i < num_properties; i++){
                //cout << "num properties" << num_properties << endl;
                //cout << &properties[i] << endl;
                cout << endl << "(" << (i+1) << ") " << properties[i]->to_str() << endl;
            }
            cout << endl;

            cout << "Type the number you wish to purchase or c to cancel... "; //could have used a goto, instead punish user by waiting a turn
            char option1;
            cin >> option1;
            //cout << "IS DIGIT " << isdigit(option1) << endl;
            
            switch(option1){
                case('c'):
                    break;
                default:
                    if(isdigit(option1)){
                        //cout << "NUM BAL " << option1-48 << endl;
                        if(option1 - 48 <= num_properties){
                            if(player.get_money() > properties[option1-48-1]->get_property_value()){ //check if user is rich enough
                                player.add_property(properties[option1-48-1]);
                                remove_property(option1-48-1);
                                cout << "Congratulations on buying a property!" << endl;
                            }   
                        }
                    }
                    break;
            }
            break;
        case('r'):
            cout << "Which building would you like to adjust rent for? ";
            int index;
            cin >> index;
            index = index-1;//for non cs folks
            if(index < player.get_num_properties()){
                cout << "You chose bulding " << index << " with a current rent of " << (player.get_properties()[index])->get_rent_turn_value() << endl;
                cout << "What would you like to set it to? ";
                int rent_target;
                cin >> rent_target;
                player.get_properties()[index]->set_rent(rent_target);
                cout << "Rent has been set to " << player.get_properties()[index]->get_rent_turn_value() << endl;

            }else{
                cout << "INVALID" << endl;
            }
            break;
        case('s'):
            cout << "Type in the number building you wish to sell... ";
            int sell_id;
            cin >> sell_id;
            if(sell_id-1 < player.get_num_properties()){
                player.sell_building(sell_id);
            }else{
                cout << "INVALID" << endl;
            }
            
            break;
            

    }


    if(!p_has_won()){
        cout << endl << "----------End Turn----------" << endl << endl;
        loop();
    }

    

}

/*
 * Initialize game values.  It's ok to rely on this function to work, values assigned
*/
void Game::initialize_game(){
    cout << "Welcome to Real Estate Tycoon 0.01" << endl;
    int seed = static_cast<int>(time(0));
    srand(seed);
    this->player.set_money(500000); //starting money values
    //cout << "Initialize 26" << endl;
    this->num_properties = 3;
    this->properties = new Property*[this->num_properties]; //9 is starting size, defined???
    this->properties[0] = new House;
    *(this->properties[0]) = generate_property(0, 100000);
    this->properties[1] = new House;
    *(this->properties[1]) = generate_property(0, 100000);
    this->properties[2] = new House;
    *(this->properties[2]) = generate_property(0, 100000);


    for(int i = 0; i < num_properties; i++){
        this->properties[i]->set_location(rand_location());
        //cout << properties[i]->get_location_str() << endl;
        this->properties[i]->set_property_value(rand_price(100000));
        this->properties[i]->mortage = rand_price(5000);
        this->properties[i]->owed = this->properties[i]->get_property_value();
    }   

    for(int i = 0; i < num_properties; i++){
        
    }
    loop();
    
}

bool Game::p_has_won(){
    if(player.get_money() > 1000000){
        cout << "You have won" << endl;
        return true;
    }else{
        return false;
    }
}

void Game::remove_property(int index){
    Property** temp = new Property*[num_properties-1];
    for(int i = 0; i < num_properties; i++){
        if(i<index){///if i=4 and index =5
            
        }else if(i <= index && i!=num_properties){
            properties[i] = properties[i+1];
        }
    }

    for(int i = 0; i < num_properties-1; i++){
        temp[i] = properties[i];
    }
    delete [] properties;
    properties = temp;

    num_properties -= 1;
}
Game::Game(){
    //cout << "Game const" << endl;
    this->cont = 'y';
    initialize_game();
}

Game::~Game(){
    for(int i = 0; i < this->num_properties; i++){
        delete properties[i];
    }
    delete [] properties;
    properties = NULL;      

}
int Game::rand_price(int budget){
 
    int base, price;
    //price = budget/1000;
    base = budget/2; //minimum
    price = rand() % budget/2;
    price += base; //some randomness
    price = price /1000;
    return price * 1000;
}

Locations Game::rand_location(){

    int num;
    num = rand() % 5;
    switch(num){
        case(0):
            return Locations::MW;
        case(1):
            return Locations::NE;
        case(2): 
            return Locations::NW;
        case(3):
            return Locations::SE;
        case(4):
            return Locations::SW;
        default:
            return Locations::NW;
    }
}
Property Game::generate_property(int tier, int budget){
    //random for budget
    switch(tier){
        case(0):
        //cout << "Budget: " << budget/1000 << endl;
            House h;
        
            //h.set_location(rand_location());
            //h.set_property_value(rand_price(budget));
            //cout << "Price set to: " << h.get_property_value() << endl;
            return h;
            break;
            
    }
}

void Game::exit(){
    abort();
}