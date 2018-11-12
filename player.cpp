#include "player.h"
#include <iostream>
using namespace std;

void Player::set_money(int money){
    this->money = money;
}

void Player::add_property(Property *p){
    Property** temp = new Property*[this->num_properties + 1]; //property.h non pure virtual for this reason
    for(int i = 0; i < this->num_properties; i++){
        if(this->properties[i] != NULL){
            temp[i] = properties[i];
            delete properties[i];
        }
    }

    delete [] properties;
    temp[this->num_properties] = p;
    this->num_properties += 1;
    properties = temp;
}  

Property** Player::get_properties(){
    return this->properties;
}

int Player::get_money(){
    return money;
}

void Player::pay_mortage(){
    for(int i = 0; i < num_properties; i++){
        set_money(get_money() - properties[i]->calculate_monthly_due());
        properties[i]->pay( properties[i]->calculate_monthly_due() );
        cout << "You payed " << properties[i]->calculate_monthly_due() << " and owe " << properties[i]->owed << " and have " << get_money() << endl;
    }
}

void Player::reap_rent(){
    int rent = 0;
    for(int i = 0; i < num_properties; i++){
        rent+=properties[i]->get_rent_turn_value();
    }
    cout << "You are being payed via rent, the amount: " << rent << endl;
    set_money(get_money() + rent);
    cout << "You know have " << get_money() << endl;
}
void Player::sell_building(int index){
    Property** temp = new Property*[num_properties-1];
    for(int i = 0; i < num_properties; i++){
        if(i<index){///if i=4 and index =5
            //index stuff
            set_money(properties[i]->get_property_value() - properties[i]->owed);
            cout << "You've been payed " << properties[i]->get_property_value() - properties[i]->owed<< " for selling a property" << endl;
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
void Player::pay_taxes(){
    int lump_sum;
    for(int i = 0; i < num_properties; i++){
        lump_sum += properties[i]->get_property_value();
    }
    int tax_dues = 0.015*lump_sum;
    cout << "Congratulations, you paid the tax man: " << tax_dues << endl;
    set_money(get_money() - tax_dues);
    cout << "You now have " << get_money() << endl;
    
}
int Player::get_num_properties(){
    return num_properties;
}

Player::~Player(){
    delete [] this->properties;
}