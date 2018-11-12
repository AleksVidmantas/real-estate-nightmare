#ifndef COMPLEX_H
#define COMPLEX_H
#include "property.h"

class Complex : public Property {
    public:
        Complex();
        int get_rent_turn_value();
        ~Complex();
}; 

#endif