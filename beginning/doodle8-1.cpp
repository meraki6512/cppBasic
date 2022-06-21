//namespace review

#include <iostream>
using namespace std;

int n = 0;
namespace A{
    int n=0;
    namespace B{
        void set() {n = 10;}
        int n = 0;
    }
}

namespace C{
    void set();
    int n=0;
}

void C::set(){n=20;}

int main(){
    using namespace A::B;
    set();                  // A::n = 10
    C::set();               // C::n = 20;

    cout << ::n << endl;    // B::n (0)
    cout << A::n << endl;   // A::n (10)
    cout << A::B::n << endl;// B::n (0)
    cout << C::n << endl;   // C::n (20)
}