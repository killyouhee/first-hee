#include <iostream>
#include "account.h"


using namespace std;
using Bank::Account;
using Bank::MENU;


int main() {
    Account a("C++", 50000);
    int menu, money;
    cout << "menu : 1. 입금, 2. 출금 3. 조회 >> ";
    cin >> menu;

    switch (menu) {

        case (static_cast<int> (MENU::DEPOSIT)):
            cout << "입금액 >> ";
            cin >> money;
            a.deposit(money);
            cout << a.getOwner() << "의 입금 액은 " << money << endl;
            cout << a.getOwner() << "의 잔액은 " << a.check() << endl;
            break;

        case (static_cast<int> (MENU::WITHDRAW)):
            cout << "출금액 >> ";
            cin >> money;
            cout << a.getOwner() << "의 출금 액은 " << a.withdraw(money) << endl;
            cout << a.getOwner() << "의 잔액은 " << a.check() << endl;
            break;

        case (static_cast<int> (MENU::CHECK)):
            cout << a.getOwner() << "의 잔액은 " << a.check() << endl;
    }
    return 0;
}