#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n = 7;
    vector<int> v;
    while(n--){
        int weight;
        cin >> weight;
        v.emplace_back(weight);
        
    };

    sort(v.begin(),v.end());
    
    cout << v[6] << endl;
    cout << v[5] << endl;

    string t;
    t ="hello";
    t.length();
     


    return 0;
}