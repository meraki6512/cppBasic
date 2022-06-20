#include <iostream>
#include <algorithm>

using namespace std;

class Vector2{
private:
    float x, y;   
    
public:
    Vector2(): x(0), y(0) {}
    Vector2(float x, float y): x(x), y(y){}
    float GetX() const {
        return x;
    }
    float GetY() const {
        return y;
    }

    Vector2& operator+=(const Vector2 &rhs){
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
};

template <typename T>
T getArraySum(T arr[], int n){
    T sum = T();
    for (int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){

    int int_arr[5] = {10, 3, 5, 2, 6};
    float float_arr[4] = {2.3, 3.6, 65.1, 4.0};
    Vector2 vector_arr[3] = {Vector2(1, 2), Vector2(3, 4), Vector2(5, 6)};
    string string_arr[3] = {"hello", " ", "world!"};

    cout << "int arr: " << getArraySum(int_arr, 5) << endl;
    cout << "float arr: " << getArraySum(float_arr, 4) << endl;
    cout << "vector arr: " << getArraySum(vector_arr, 3).GetX() << "," << getArraySum(vector_arr, 3).GetY() << endl;
    cout << "string arr: " << getArraySum(string_arr, 3) << endl;

}