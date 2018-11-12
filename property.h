#ifndef PROPERTY_H
#define PROPERTY_H
#include <string>
#include "location.h"
#include "tenant.h"
using namespace std;

class Property {
    protected:
        
        Tenant* tenants = NULL;
        
        int property_value;
        //float tax = 0.015;
        Locations location;
        int num_tenants;


    public:
        void set_owed();
        float tax = 0.015;
        int test = 60;
        int mortage;
        int calculate_monthly_due();
        int owed;
        void pay(int payment);
        void set_rent(int rent);
        bool owned = false; //short on time
        virtual void print_debug(){};
        Property();
        Locations get_location() const;
        string get_location_str() const;
        void set_location(Locations l);
        void set_property_value(int val);
        //void set_location(Locations location);
        int get_property_value() const;
         //override print for easy info display
        virtual string to_str(){return "No";};//random gibberish without return 0, expected
        virtual int get_rent_turn_value() {return 0;}; //only virtualfor comparison, Can params change?
        bool operator>(Property &prop2);//needed to change params
        int get_num_tenants() const;    
        ~Property();
        
}; 

#endif