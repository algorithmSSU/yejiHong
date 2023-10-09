#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



long long N, M;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<long long> v;
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        long long tree;
        cin >> tree;
        v.emplace_back(tree);
    }

    sort(v.begin(),v.end());
    long long answer = 0;
    long long Min=0;
    long long Max=v[v.size()-1];

    while(Min<=Max){
        long long Mid = (Min+Max)/2;
        int dangkang = 0;
        for(auto it : v){
            if(Mid<it){
                dangkang+=it-Mid;
            }
        }
        if(dangkang>=M){
            answer=Mid;
            Min=Mid+1;
        }else{
            Max=Mid-1;
        }
    }
    cout << answer << '\n';

    


}