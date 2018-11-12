#ifndef TENANT_H
#define TENANT_H

class Tenant {
    public:
        int agreeability = 0;
        int monthly_budget = 0;
        int rent = 900;
        int get_rent() const;
        Tenant();
        Tenant& operator=(const Tenant& t);

};

#endif