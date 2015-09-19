//
// Created by Anthonyeef on 9/19/15.
//

#include <vector>
#include "CreditCard.h"

using namespace std;

void testCard() {
    vector<CreditCard*> wallet(10);

    wallet[0] = new CreditCard("5464 6543 9876 0976", "John Bowman", 2500);
    wallet[1] = new CreditCard("2398 0238 9284 2013", "John Bowman", 3500);
    wallet[2] = new CreditCard("2398 0238 8723 2013", "John Bowman", 4500);

    for (int j = 0; j <= 16; ++j) {
        wallet[0]->chargelt(double(j));
        wallet[1]->chargelt(2 * j);
        wallet[2]->chargelt(double(3 * j));
    }

    cout << "Card payments:\n";
    for (int i = 0; i < 3 ; ++i) {
        cout<< *wallet[i];
        while (wallet[i]->getBalance() > 100.0) {
            wallet[i]->makePayment(100.0);
            cout<< "New balance = " << wallet[i]->getBalance()<<"\n";
        }
        cout<<"\n";
        delete wallet[i];
    }
}

int main() {
    testCard();
    return EXIT_SUCCESS;
}
