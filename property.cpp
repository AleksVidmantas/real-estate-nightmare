#include <iostream>
#include "property.h"
using namespace std;

void Property::set_property_value(int val){
    property_value = val;
}

int Property::get_property_value() const{
    return property_value;
}

void Property::set_rent(int rent){
    for(int i = 0; i < num_tenants; i++){
        tenants[i].rent = rent;
    }
}

void Property::set_owed(){
    owed = get_property_value();
}

int Property::calculate_monthly_due(){
    if(owed > mortage ){
        // /cout << "Paying " << mortage << endl;
        return (mortage);
    }else if(mortage > owed){
        // cout << "Paying" <<(owed) << endl;
        return (owed);
    }
}

void Property::pay(int payment){
    owed-=payment;
}

string Property::get_location_str() const{
   // cout << "Beginning get_location_str" << endl;
    switch(this->location){
        case(Locations::MW):
            return "MW";
        case(Locations::NE):
            return "NE";
        case(Locations::NW):
            return "NW";
        case(Locations::SE):
            return "SE";
        case(Locations::SW):
            return "SW";
        default:
            return "SHTF";
    }
}

void Property::set_location(Locations l){
    this->location = l;
}
int Property::get_num_tenants() const{
    return this->num_tenants;
}
bool Property::operator>(Property &prop2){
    if(this->get_rent_turn_value() > prop2.get_rent_turn_value()){
        //cout << "Local val is " << this->get_rent_turn_value();
        return true;
    }else{
        return false;
    }
}

Property::Property(){
    //scout << "Property Constructor" << endl;
    this->property_value = 0;
    //this->tax = 0.015; //constant tax of .015, could be const but...
    this->num_tenants = 0;
}

Locations Property::get_location() const{
    return this-> location;
}

/* This function is amazing, follow this setup for now on*/
Property::~Property(){
    if(num_tenants > 1){
        delete [] tenants;
    }else if(num_tenants == 0 && tenants != NULL){
        delete tenants;
    }
    
}