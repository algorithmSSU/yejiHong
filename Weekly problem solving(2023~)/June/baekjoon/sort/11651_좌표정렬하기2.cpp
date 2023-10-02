#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second ==b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
};



int main(){
    int n;
    vector<pair<int, int> > v;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        v.emplace_back(a,b);
    }
    //sort(v.begin(),v.end());
    sort(v.begin(),v.end(),compare);

    for(int i=0;i<v.size();i++){
        cout << v[i].first << " " << v[i].second << endl;
    }

}