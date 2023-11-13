#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> answer;

    cin >> T;
    while(T--){
        int p;
        cin >> p;
        vector<pair<int,int>> v;
        for(int i=0;i<p;i++){
            int a,b;
            cin >> a>>b;
            v.emplace_back(a,b);
        }
        sort(v.begin(),v.end());

        int compare = v.front().second;
        int cnt = 1;
        for(auto it : v){
            if(compare > it.second){
                cnt++;
                compare = it.second;
            }else{
                continue;
            }
        }
        answer.emplace_back(cnt);
    }

    for(auto it : answer){
        cout << it << endl;
    }

}