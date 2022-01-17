#include <iostream>
#include "account.h"


using namespace std;
using Bank::Account;
using Bank::MENU;


int main() {
    Account a("C++", 50000);
    int menu, money;
    cout << "menu : 1. �Ա�, 2. ��� 3. ��ȸ >> ";
    cin >> menu;

    switch (menu) {

        case (static_cast<int> (MENU::DEPOSIT)):
            cout << "�Աݾ� >> ";
            cin >> money;
            a.deposit(money);
            cout << a.getOwner() << "�� �Ա� ���� " << money << endl;
            cout << a.getOwner() << "�� �ܾ��� " << a.check() << endl;
            break;

        case (static_cast<int> (MENU::WITHDRAW)):
            cout << "��ݾ� >> ";
            cin >> money;
            cout << a.getOwner() << "�� ��� ���� " << a.withdraw(money) << endl;
            cout << a.getOwner() << "�� �ܾ��� " << a.check() << endl;
            break;

        case (static_cast<int> (MENU::CHECK)):
            cout << a.getOwner() << "�� �ܾ��� " << a.check() << endl;
    }
    return 0;
}