#include <iostream>
using namespace std;

class GameWindow{
private:
    int width;
    int height;
public:
    GameWindow();
    GameWindow(const int width, const int height);

    int getWidth() const;
    int getHeight() const;
    void resizeWindow(const int width, const int height);

    static void printWindow(const GameWindow g){
        cout << "Window Size: (" << g.width << ", " << g.height << ")" <<endl;
    }
};

int main(){
    GameWindow g1(20, 20);
    GameWindow::printWindow(g1);
    g1.resizeWindow(10, 780);
    GameWindow::printWindow(g1);
    g1.resizeWindow(1280, 960);    
    GameWindow::printWindow(g1);
}

GameWindow::GameWindow(): width(800), height(600){}
GameWindow::GameWindow(const int width, const int height){
    if (width < 800){
        this->width = 800;
    }
    else{
        this->width = width;
    }

    if (height < 600){
        this->height = 600;
    }
    else{
        this->height = height;
    }
}
int GameWindow::getHeight()const {return height;}
int GameWindow::getWidth()const {return width;}
void GameWindow::resizeWindow(const int width, const int height){ 
    if (width < 800){
        this->width = 800;
    }
    else{
        this->width = width;
    }

    if (height < 600){
        this->height = 600;
    }
    else{
        this->height = height;
    }
}