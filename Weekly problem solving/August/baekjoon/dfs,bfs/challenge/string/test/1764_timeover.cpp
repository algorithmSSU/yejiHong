#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> nolisten;
vector<string> nolook;
vector<string> intersection;

int main(){

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n;i++){
        string temp;
        cin >> temp;
        nolisten.push_back(temp);
    };
    for (int j = 0; j < m;j++){
        string temp;
        cin >> temp;
        nolook.push_back(temp);
    };

    set_intersection(nolisten.begin(), nolisten.end(), nolook.begin(), nolook.end(), back_inserter(intersection));
    cout << intersection.size() << endl;
    for(string n:intersection){
        cout << n << endl;
    };
};