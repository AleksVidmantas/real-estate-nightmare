#include <iostream>
#include "tenant.h"

int Tenant::get_rent() const{
    return rent;
}

Tenant::Tenant(){
    int seed = static_cast<int>(time(0));
    srand(seed);
    agreeability = rand() % 5 + 1; //agreeability, 1-5
    monthly_budget = 100*(rand() & 46 + 5); //500 - 50000
}

Tenant& Tenant::operator=(const Tenant& t){
    this->rent = t.get_rent();
}