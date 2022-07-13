#include <iostream>
#include <cstring>

using namespace std;

class String{
public:
    String(){
        strData = NULL;
        len = 0;
    }
    String(const char* str){
        len = strlen(str); // NULL문자 제외한 string 길이 반환.
        strData = new char[len+1];
        strcpy(strData, str);
    }
    ~String(){
        delete[] strData;
    }
    char* getStrData() const { return strData; }
    int getLen() const {return len;}
private:
    char* strData;
    int len;
};

int main(){
    String s;
}