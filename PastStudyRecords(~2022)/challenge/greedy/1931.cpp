#include <iostream>
#include <vector>
#include <algorithm>
using std::pair;

using namespace std;
vector<pair<int, int>> v;
int n;
bool compare(pair<int,int> &a, pair<int,int> &b){
    if(a.first==b.first){
        return a.second > b.second;
    }
    return a.second < b.second;
}
int main(){

    cin >> n;

    for (int i = 0; i < n;i++){
        int x, y;
        cin >> y >> x;
        v.push_back(make_pair(x, y));
    };

    sort(v.begin(), v.end());
    /*
        for (int j = 0; j < n;j++){
            cout << v[j].first << v[j].second << endl;
        };

        */

    int cnt = 0;
    int cur = 0;

    for (int i = 0;i<n;i++){
        if(cur<=v[i].second){
            cur = v[i].first;
            cnt++;
        };
    };

    cout << cnt << endl;
};
