//동적 할당: 프로그램 실행 중 메모리 할당을 하는 것.

#include <iostream>

using namespace std;

class Vector2{
public:
    Vector2(): x(0), y(0){ //생성자
        cout << this << " : Vector2()" <<endl;
    }
    Vector2(const float x, const float y): x(x), y(y){
        cout << this << " : Vector2(const float x, const float y)" << endl; 
    }
    ~Vector2(){ //소멸자
        cout << this << ": ~Vector2()" << endl;
    }

    float GetX() const {return x;}
    float GetY() const {return y;}
private:
    float x, y;
};

Vector2 s3;

int main(){

    //1. int 동적할당
    int *a = new int(5); //new 연산자: 주소값 반환.
    cout << a << endl;
    cout << *a << endl;
    *a = 10;
    cout << a << endl;
    cout << *a << endl;
    delete a; // 메모리 해제: delete 연산자.

    //2. 배열 동적할당
    int *arr;
    int len;
    cout << "arr 길이 입력: ";
    cin >> len;
    arr = new int[len];

    for (int i=0; i<len ;i++){
        arr[i] = len-i;
    }
    for (int i=0; i<len; i++){
        cout <<arr[i] <<endl;
    }

    delete[] arr; //배열 메모리 해제: delete[] 연산자.

    //3. 객체 동적할당
    Vector2 s1;
    Vector2 s2(3,2);
    Vector2 *d1 = new Vector2();
    Vector2 *d2 = new Vector2(3,2);

    cout << "(" << d1->GetX() << ", " << d1->GetY() << ")" << endl;
    cout << "(" << d2->GetX() << ", " << d2->GetY() << ")" << endl;

    delete d1;
    delete d2;

}