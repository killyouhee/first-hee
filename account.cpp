#include <string>
#include <iostream>
#include "account.h"


using namespace std;
using Bank::Account;


Account::Account(string n, int bal) : name(n), balance(bal) { }


Account::~Account() {
    cout << name << ": 객체 소멸" << endl;
}

void Account::deposit(const int money) {
    balance += money;
}


int Account::withdraw(int money) {

    if (money > balance) { // 저축된 돈이 찾는 금액보다 작은 경우
        money = balance;
        balance = 0;
    }
    else
        balance -= money;

    return money; // 실제 찾은 금액 리턴
}

 

int Account::check() const {
    return balance;
}

 

string Account::getOwner() const {
    return name;
}