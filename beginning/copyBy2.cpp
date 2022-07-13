#include <iostream>
#include <cstring>

using namespace std;

class String{    
public:
    String(){
        cout << "String() ������ ȣ��" << endl;
        strData = NULL;
        len = 0;
    }
    String(const char* str){
        cout << "String(const char*) ������ ȣ��" << endl;
        len = strlen(str);
        strData = new char[len+1];
        cout << "strData �Ҵ�: " << (void*) strData << endl;
        strcpy(strData, str);
    }
    String(const String & rhs){
        cout << "String (coonst String& rhs) ������ ȣ��" <<endl;
        len = rhs.len;
        strData = new char[rhs.len+1];
        cout << "strData �Ҵ�: " << (void*) strData<< endl;
        strcpy(strData, rhs.strData);
    }
    ~String(){
        cout << "~String() �Ҹ��� ȣ��" << endl;
        delete[] strData;
        cout << "strData ������: " << (void*) strData << endl;
        strData = NULL;
    }
    char* getStrData() const { return strData; }
    int getLen() const { return len; }

private:
    char* strData;
    int len;
};

int main(void){
    String s1("�ȳ�");
    String s2(s1);

    cout  << s1.getStrData() << endl;
    cout << s2.getStrData() << endl;
}