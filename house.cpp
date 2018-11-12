#include <iostream>
#include "house.h"
using namespace std;

int House::get_property_value() const{
   return property_value;
}

House::House(){
    num_tenants = 1;
    //delete [] tenants;
    tenants = new Tenant[num_tenants];
    //cout << "House constructor called" << endl;
}

int House::get_rent_turn_value(){
    int rent_total = 0;
    for(int i = 0; i < num_tenants; i++){
        // cout << num_tenants << endl;
        // cout << "Here" << endl;
        // cout << i << endl;
        rent_total += tenants[i].get_rent();
    }
    // cout << "[DIAG] Rent is: " << rent_total << endl;
    // cout << "Returning " << rent_total << endl;
    return rent_total; 
}

string House::to_str() {
   // cout << "TEST" << endl;

    //cout << get_location_str() << endl;
    //cout << to_string(get_property_value()) << endl;
    //cout << "value?" << to_string(get_property_value()) << endl;
    //cout << "loca" << get_location_str() << endl;
    return  ("house in the " + get_location_str() +  " of value " + to_string(get_property_value()));
}

House& House::operator=(const House& h){
    cout << "A" << endl;
    this->location = h.get_location();
    this->property_value = h.get_property_value();
    cout << "F" << endl;
    if(this->tenants != NULL){
        cout << "Running house op null" << endl;
        delete [] this->tenants; //invalid?? due to null
    }
    this->num_tenants = h.get_num_tenants();
    for(int i = 0; i < this->num_tenants; i++){
        this->tenants[i] = h.tenants[i];
    }
}

House::~House(){
    delete [] tenants;
}