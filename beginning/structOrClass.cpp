// c++에서는 struct도 함수 선언 가능.
// 디폴트 접근 지정자: class==private, struct==public

#include <iostream>
using namespace std;

struct TV
{
private:
    int volume = 10;
    bool power = false;
    int channel = 1;

public:
    void setPower();
    void setChannel(int channel);
    void setVolume(int volume);
};

void TV::setPower()
{
    if (!power)
    {
        cout << "TV를 켭니다." << endl;
        power = true;
    }
    else
    {
        cout << "TV를 끕니다." << endl;
        power = false;
    }
}

void TV::setChannel(int channel)
{
    if (this->power && channel > 0 && channel < 100)
    {
        cout << "채널 변경: " << this->channel << "->" << channel << endl;
        this->channel = channel;
    }
}
void TV::setVolume(int volume)
{
    if (this->power && volume >= 0 && volume <= 50)
    {
        cout << "채널 변경: " << this->volume << "->" << volume << endl;
        this->volume = volume;
    }
}

int main()
{
    TV lg;

    lg.setPower();
    lg.setChannel(10);
    lg.setVolume(20);
}