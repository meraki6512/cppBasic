#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
    String()
    {
        cout << "String() ȣ���: " << this << endl;
        strData = NULL;
        len = 0;
    }
    String(const char *str)
    {
        cout << "String(const char* str) ȣ���: " << this << endl;
        len = strlen(str);
        alloc(len);
        strcpy(strData, str);
    }
    String(const String &rhs)
    {
        cout << "String(const String &rhs) ȣ���: " << this << endl;
        len = rhs.len;
        alloc(len);
        strcpy(strData, rhs.strData);
    }
    String(String &&rhs) // '�ӽð�ü'�� r-value.
    {
        cout << "String(String &&rhs) ȣ���: " << this << endl;
        len = rhs.len;
        strData = rhs.strData;
        // �̵� �ø�ƽ
        // �������� ��ü�� ������ ������ �ʵ��� �ϱ� ����.
        // ���ÿ� �ϳ��� ��ü�� ����Ű���� ���� ��, �������� ��ü�� �����͸� NULL�� �̵�.
        rhs.strData = NULL;
    }
    ~String()
    {
        cout << "~String() ȣ���: " << this << endl;
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
        rhs.strData = NULL; // �̵� �ø�ƽ
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