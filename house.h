#ifndef HOUSE_H
#define HOUSE_H
#include "property.h"

class House : public Property {

    public:
     //   void print_debug(){};
        House();
        int get_property_value() const;
        int get_rent_turn_value();
        string to_str() override;
        House& operator=(const House& h);
        ~House();

};


#endif