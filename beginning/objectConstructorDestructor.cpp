// ��������� �ʱ�ȭ�ϴ� ������
// ������ �ʱ�ȭ���
// ������ ����

#include <iostream>

using namespace std;

class Complex{
private:
    string test;
    double real;
    double image;

public:
    Complex() : test("0"), real(0), image(0) {} //�������� �Ű����� ����Ʈ �� ���� //�ʱ�ȭ���: �����ڿ��� ���
    Complex(string test) : test(test) {} 
    Complex(double real) : Complex() {} // ������ ����
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
        cout << "������ ȣ��\n";
    }
    ~MyClass()
    {
        cout << "�Ҹ��� ȣ��\n";
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