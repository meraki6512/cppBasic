// 1. ��� �޼ҵ��� ����� ���� �и�
// static ��� ������ ���, �ʼ��� // �׿��� ���, recommended.
// ex)...
// void a(){
//     c(); //��Ÿ�� ����.
// }
// void b(){
//     a();
// }
// void c(){
//     b();
// }

// 2. ����
// 3. ������ �����ε�

#include <iostream>
using namespace std;

//�����

class Vector2
{
private:
    float x, y;

public:
    Vector2();
    Vector2(float x, float y);

    float GetX() const;
    float GetY() const;

    static Vector2 vectorSum(const Vector2 a, const Vector2 b) // const : static ��� �Լ��� ��� �Ұ�.
    {
        return Vector2(a.x + b.x, a.y + b.y);
    }

    Vector2 add(const Vector2 rhs) const;
    Vector2 operator+(const Vector2 rhs) const;
};

Vector2 operator*(const float a, const Vector2 b);

//����

int main()
{
    Vector2 a(2, 3);
    Vector2 b(-1, 4);
    Vector2 c1 = Vector2::vectorSum(a, b);
    Vector2 c2 = a.add(b);
    Vector2 d1 = a + b;
    Vector2 d2 = a.operator+(b);
    Vector2 e1 = operator*(3,b);
    Vector2 e2 = 3*b;
    cout << "a:" << a.GetX() << ", " << a.GetY() << endl;
    cout << "b:" <<  b.GetX() << ", " << b.GetY() << endl;
    cout << "c1:" <<  c1.GetX() << ", " << c1.GetY() << endl;
    cout << "c2:" <<  c2.GetX() << ", " << c2.GetY() << endl;
    cout << "d1:" <<  d1.GetX() << ", " << d1.GetY() << endl;
    cout << "d2:" <<  d2.GetX() << ", " << d2.GetY() << endl;
    cout << "e1:" <<  e1.GetX() << ", " << e1.GetY() << endl;
    cout << "e2:" <<  e2.GetX() << ", " << e2.GetY() << endl;
}

//���Ǻ� / ������

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}

float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }

Vector2 Vector2::add(const Vector2 rhs) const {
    return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator+(const Vector2 rhs) const {
    return Vector2(x + rhs.x, y + rhs.y);
}


Vector2 operator*(const float a, const Vector2 b){
    return Vector2 (a*b.GetX(), a*b.GetY());
}