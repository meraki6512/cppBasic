#include <iostream>

using namespace std;  

int n;
void set(){
    //::n = 10; //명시적 전역변수
    n=10;
}

namespace doodle{
    int n;
    int m;
    void set();

    namespace zoozle{
        int n;
        void set();
        int m;
    }
}

void doodle::set(){
    //doodle::n = 20;
    n=20;
    m=10;
}

void doodle::zoozle::set(){
    n=50;
    m=999;
}

namespace google{
    int n;
    void set();
}

void google::set(){
    //google::n = 30;
    n=30;
    ::n=40;
}


int main(){
    
    using namespace doodle;

    ::set();
    doodle::set(); // using namespace doodle 사용해도 doodle:: 생략 불가.
    google::set();
    //doodle::zoozle::set();
    zoozle::set(); // using namespace doodle 사용했을 때, 모호성 사라짐. -> doodle:: 생략 가능.

    cout << ::n << endl;
    cout << doodle::n << endl;
    cout << google::n << endl;
    cout << doodle::zoozle::n <<endl;
    
    cout << "\n" << doodle::zoozle::m <<endl; // 선언 위치에 따라 값이 달라짐.
}
