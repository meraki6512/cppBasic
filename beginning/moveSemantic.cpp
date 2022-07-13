#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
    String()
    {
        cout << "String() 호출됨: " << this << endl;
        strData = NULL;
        len = 0;
    }
    String(const char *str)
    {
        cout << "String(const char* str) 호출됨: " << this << endl;
        len = strlen(str);
        alloc(len);
        strcpy(strData, str);
    }
    String(const String &rhs)
    {
        cout << "String(const String &rhs) 호출됨: " << this << endl;
        len = rhs.len;
        alloc(len);
        strcpy(strData, rhs.strData);
    }
    String(String &&rhs) // '임시객체'는 r-value.
    {
        cout << "String(String &&rhs) 호출됨: " << this << endl;
        len = rhs.len;
        strData = rhs.strData;
        // 이동 시맨틱
        // 쓸데없이 객체를 여러개 만들지 않도록 하기 위함.
        // 동시에 하나의 객체를 가리키도록 만든 후, 전달해준 객체의 포인터를 NULL로 이동.
        rhs.strData = NULL;
    }
    ~String()
    {
        cout << "~String() 호출됨: " << this << endl;
        release();
    }

    char *getStrData() const { return strData; }
    int getLen() const { return len; }

    void setStrData(const char *str)
    {
        release();
        len = strlen(str);
        alloc(len);
        strcpy(strData, str);
    }

    String &operator=(const String &rhs)
    {
        if (this != &rhs)
        {
            release();
            len = rhs.len;
            alloc(len);
            strcpy(strData, rhs.strData);
        }
        return *this;
    }
    String &operator=(String &&rhs)
    {
        len = rhs.len;
        strData = rhs.strData;
        rhs.strData = NULL; // 이동 시맨틱
        return *this;
    }

private:
    char *strData;
    int len;

    void alloc(int len)
    {
        strData = new char[len + 1];
        cout << "strData allocated: " << (void *)strData << endl;
    }
    void release()
    {
        delete[] strData;
        if (strData)
            cout << "strData released: " << (void *)strData << endl;
    }
};

String getName()
{
    String res("GETNAME");
    return res;
}

int main()
{
    String a;
    a = getName();
}