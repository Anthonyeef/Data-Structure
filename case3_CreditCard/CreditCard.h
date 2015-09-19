//
// Created by Anthonyeef on 9/19/15.
//

#ifndef CASE3_CREDITCARD_CREDITCARD_H
#define CASE3_CREDITCARD_CREDITCARD_H

#include <string>
#include <iostream>

class CreditCard {
public:
    CreditCard(const std::string& no,
               const std::string& nm, int lim, double bal = 0);

    std::string getNumber() const { return  number;}
    std::string getName() const { return name;}

    double getBalance() const { return balance;}
    int getLimit() const { return limit;}

    bool chargelt(double price);
    void makePayment(double payment);

private:
    std::string number;
    std::string name;

    double balance;
    int limit;
};
std::ostream& operator<<(std::ostream& out, const CreditCard& c);
#endif
