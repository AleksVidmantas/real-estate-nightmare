#include <iostream>
#include "complex.h"
using namespace std;

Complex::Complex(){
    cout << "COmplex const" << endl;
    num_tenants = 0;
    tenants = new Tenant[num_tenants];
}

int Complex::get_rent_turn_value(){
    int rent_total = 0;
    for(int i = 0; i < num_tenants; i++){
        rent_total += tenants[i].get_rent();
    }
    cout << "[DIAG2] Rent is: " << rent_total << endl;
    return rent_total;
}

Complex::~Complex(){
    delete [] tenants;
}