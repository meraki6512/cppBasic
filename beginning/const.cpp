// const
// 1. 매개변수
// 2. 메소드

#include <iostream>

using namespace std;

class Account {
private:
    int money;
public:
    Account():money(0){}
    Account(int money):money(money){}

    void deposit(const int d){
        //d = money; //const 매개변수: 매개변수에 접근(변경) 불가능.
        money += d;
        cout << d << "원 예금." << endl;
    }

    void draw(const int d){
        if (money >= d){
            money-=d;
            cout << d<< "원 인출." <<endl;
        }
    }

    int viewMoney() const { // 비멤버 함수에서는 const 사용 불가능.
        //money++; //const 메소드: 멤버변수에 접근(변경) 불가능.
        return money;
    }
};

int main (){
    Account a(200);
    a.deposit(100);
    a.draw(20);

    cout << "잔액: " << a.viewMoney() << "d원" <<endl; 
}