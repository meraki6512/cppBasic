#include <iostream>
#include <algorithm>

using namespace std;

class Student{

private:
    string name;
    int score;

public:
    Student(string name, int score){
        this->name = name;
        this->score = score;
    }

    bool operator<(Student &student){
        return this->score < student.score;
    }

    string getName(){
        return this->name;    
    }

};

int main(){

    Student student[5] = {
        {"a", 90},
        {"b", 70},
        {"c", 30},
        {"d", 80},
        {"e", 50}
    };

    sort(student, student+5);

    for (int i=0; i<5; i++){
        cout << student[i].getName() << endl;
    }
}