#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare (pair<string, pair<int, int>> a, pair<string, pair<int, int>> b){
    
    if (a.second.first == b.second.first){
        return a.second.second > b.second.second;
    }
    else{
        return a.second.first > b.second.first;
    }

}

int main(){

    vector <pair<string, pair<int, int>>> v;
    v.push_back(pair<string, pair<int, int>>("a", pair<int, int>(90, 20011012)));
    v.push_back(pair<string, pair<int, int>>("b", pair<int, int>(80, 20010308)));
    v.push_back(pair<string, pair<int, int>>("c", pair<int, int>(90, 20010419)));
    v.push_back(pair<string, pair<int, int>>("d", pair<int, int>(70, 20010505)));
    v.push_back(pair<string, pair<int, int>>("e", pair<int, int>(80, 20011231)));

    sort(v.begin(), v.end(), compare);

    for (int i=0; i<v.size(); i++){
        cout << v[i].first << endl;
    }

    return 0;

}