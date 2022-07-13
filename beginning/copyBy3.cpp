#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
    String()
    {
        cout << "String() 생성자 호출" << endl;
        strData = NULL;
        len = 0;
    }
    String(const char *str)
    {
        cout << "String(const char*) 생성자 호출" << endl;
        len = strlen(str);
        strData = new char[len + 1];
        cout << "strData 할당: " << (void *)strData << endl;
        strcpy(strData, str);
    }
    String(const String &rhs)
    {
        cout << "String (coonst String& rhs) 생성자 호출" << endl;
        len = rhs.len;
        strData = new char[rhs.len + 1];
        cout << "strData 할당: " << (void *)strData << endl;
        strcpy(strData, rhs.strData);
    }
    ~String()
    {
        cout << "~String() 소멸자 호출" << endl;
        delete[] strData;
        cout << "strData 해제됨: " << (void *)strData << endl;
        strData = NULL;
    }

    String &operator=(const String &rhs)
    { // 굳이 한번 더 객체를 생성하지 않도록 레퍼런스로 받고 반환함.
        if (this != &rhs)
        {
            delete[] strData; // 기존 데이터 해제.
            len = rhs.len;
            strData = new char[rhs.len + 1];
            cout << "strData 할당: " << (void *)strData << endl;
            strcpy(strData, rhs.strData);
        }
        return *this;
    }

    char *getStrData() const { return strData; }
    int getLen() const { return len; }

private:
    char *strData;
    int len;
};

int main(void)
{
    String s1("안녕");
    String s2(s1);
    String s3("Hello");
    s3 = s1; // s3.operator=(s1);

    cout << s1.getStrData() << endl;
    cout << s2.getStrData() << endl;
    cout << s3.getStrData() << endl;
}