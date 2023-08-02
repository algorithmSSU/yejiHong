#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;



bool comp(pair<int,string> a, pair<int,string> b){
    return a.first>b.first;
}
int main(){


    cin.tie(0);
    ios_base::sync_with_stdio(false);


    int n;
    vector<pair<int,string> > v;
    cin >> n;

    for(int i=0;i<n;i++){
        string temp;
        int grade;
        cin >> temp >> grade;
        v.emplace_back(grade,temp);
    };

    sort(v.begin(),v.end(),comp);


    cout << v[2].second << endl;


}