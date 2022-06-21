#include <iostream>

using namespace std;

class Color{
private:
    float r, g, b;
    int id;

public:
    Color(): r(0), g(0), b(0), id(idCounter++){}
    Color(float r, float g, float b): r(r), g(g), b(b), id(idCounter++){}

    float getR(){ return r; }
    float getG(){ return g; }
    float getB(){ return b; }

    static Color mixedColor(Color a, Color b){
        return Color (((a.r+b.r)/2), ((a.g+b.g)/2), ((a.b+b.b)/2));
    }
    
    static int idCounter; //Ŭ���� ���ο��� ���� �Ұ���. // �������� ��� static ��� ����ϸ�, Coupling ���� �� �ִ�.
};

int Color::idCounter=1; //������ Ŭ���� ������ �ϰ�, ���Ǵ� Ŭ���� �ۿ��� ��.

int main(){
    Color red(1,0,0), blue(0,0,1);
    Color purple = Color::mixedColor(red, blue);

    cout << "purple\n" << "r=" << purple.getR() << ", g=" << purple.getG() << ", b=" << purple.getB() << endl;
}
