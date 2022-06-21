// const
// 1. �Ű�����
// 2. �޼ҵ�

#include <iostream>

using namespace std;

class Account {
private:
    int money;
public:
    Account():money(0){}
    Account(int money):money(money){}

    void deposit(const int d){
        //d = money; //const �Ű�����: �Ű������� ����(����) �Ұ���.
        money += d;
        cout << d << "�� ����." << endl;
    }

    void draw(const int d){
        if (money >= d){
            money-=d;
            cout << d<< "�� ����." <<endl;
        }
    }

    int viewMoney() const { // ���� �Լ������� const ��� �Ұ���.
        //money++; //const �޼ҵ�: ��������� ����(����) �Ұ���.
        return money;
    }
};

int main (){
    Account a(200);
    a.deposit(100);
    a.draw(20);

    cout << "�ܾ�: " << a.viewMoney() << "d��" <<endl; 
}