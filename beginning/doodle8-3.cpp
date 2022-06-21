#include <iostream>
using namespace std;

class MyClass{
private:
    int num;
    char ch;
public:
    MyClass() : num(cnt++), ch('\0'){}
    void Check(MyClass *ptr){
        if (ptr + num == this) {
            cout << num << endl;
        }
    }
    static int cnt;
};

int MyClass::cnt = 0;

int main(){
    MyClass obj[5]; //cnt = 0, 1, 2, 3, 4
    cout << "Test #1: " << endl;
    for (int i=0; i<5; i++){
        obj[i].Check(obj); // num = 0, 1, 2, 3, 4
    }
    cout << "Test #2: " << endl;
    for (MyClass &i: obj){ // i = obj[0], obj[1], ..., obj[4]
        i.Check(obj); // num = 0, 1, 2, 3, 4
    }
    cout << "cnt = " << MyClass::cnt << endl; // cnt = 5
}