#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class Vector2{
private:
    T x, y;
public:
    Vector2():x(T()),y(T()){}
    Vector2(T x, T y):x(x),y(y){}

    T getX() const{
        return x;
    }
    T getY() const{
        return y;
    }

    Vector2 operator+(Vector2& rhs){
        return Vector2(x+rhs.x, y+rhs.y);
    }
    
    Vector2 operator-(Vector2& rhs){
        return Vector2(x-rhs.x, y-rhs.y);
    }

    Vector2& operator+= (Vector2& rhs){
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Vector2& operator-= (Vector2& rhs){
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
    
};

int main(){

    Vector2<int> v1(2, 3);
    Vector2<double> v2(3.4, 10.1);
    Vector2<float> v3(5, 7);

    cout<<"sizeof(int_v1): "<<sizeof(v1)<<endl;
    cout<<"sizeof(double_v2): "<<sizeof(v2)<<endl;
    cout<<"sizeof(float_v3): "<<sizeof(v3)<<endl;

}