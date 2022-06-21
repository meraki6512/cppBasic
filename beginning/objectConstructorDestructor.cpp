// 멤버변수를 초기화하는 생성자
// 생성자 초기화목록
// 생성자 위임

#include <iostream>

using namespace std;

class Complex{
private:
    string test;
    double real;
    double image;

public:
    Complex() : test("0"), real(0), image(0) {} //우측부터 매개변수 디폴트 값 지정 //초기화목록: 생성자에만 사용
    Complex(string test) : test(test) {} 
    Complex(double real) : Complex() {} // 생성자 위임
    Complex(double real, double image) : Complex(real) {
         this->image = image;
    }

    double GetReal(){
        return real;
    }
    void SetReal(double real){
        this -> real = real;
    }
    double GetImage(){
        return image;
    }
    void SetImage(double image_){
        image = image_;
    }
};

/*
class MyClass
{
public:
    MyClass()
    {
        cout << "생성자 호출\n";
    }
    ~MyClass()
    {
        cout << "소멸자 호출\n";
    }
};

MyClass globalObj;

void testLocalObj()
{
    cout << "testLocal.. \n";
    MyClass localObj;
    cout << "..testLocal\n";
}

void globalOrLocal()
{
    cout << "main.. \n";
    testLocalObj();
    cout << "..main \n";
}

*/

int main(){

    int a(5); //int a=5;

    Complex c1;
    Complex c2 = Complex(2,4);
    Complex c3(3, 5);
    Complex c4 = {2, 3};
    Complex c5 = Complex{2, 3};
    Complex c6{2,3};

    cout << "c1 = " << c1.GetReal() << ", " << c1.GetImage() << endl;
    cout << "c2 = " << c2.GetReal() << ", " << c2.GetImage() << endl;
    cout << "c3 = " << c3.GetReal() << ", " << c3.GetImage() << endl;
    cout << "c4 = " << c4.GetReal() << ", " << c4.GetImage() << endl;
    cout << "c5 = " << c5.GetReal() << ", " << c5.GetImage() << endl;
    cout << "c6 = " << c6.GetReal() << ", " << c6.GetImage() << endl;

}