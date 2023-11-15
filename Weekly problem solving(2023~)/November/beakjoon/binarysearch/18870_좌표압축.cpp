#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<long long> v;
    vector<long long> vo;
    vector<int> answer;


    cin >> N;
    for(int i=0;i<N;i++){
        long long num;
        cin >> num;
        v.emplace_back(num);
        vo.emplace_back(num);
    }
    //vo = v;// deep copy?

    // ⭐️ unique 후에 erase+unique ⭐️ 
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    

    //sort(v.begin(),v.end());

    for(auto it : vo){
        int idx =lower_bound(v.begin(),v.end(),it)-v.begin();
        answer.emplace_back(idx);
    }
    for(auto it : answer){
        cout << it << " ";
    }
    cout << '\n';
    
    
}