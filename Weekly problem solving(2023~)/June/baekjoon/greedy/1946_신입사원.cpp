#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<int> answer;
    cin >> n;

    for(int i=0;i<n;i++){
        int m;
        vector<pair<int, int> > v;
        cin >> m;
        for(int i=0;i<m;i++){
            int score, meet;
            cin >> score >> meet;
            v.emplace_back(score,meet);
        };

        sort(v.begin(),v.end());
        int count = 1;
        int temp = 0;
        for(int i=1;i<v.size();i++){
            if(v[temp].second>v[i].second){
                count++;
                temp = i;
            }
        }
        answer.emplace_back(count);
        //cout << count << '\n';
    };
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }

    

}