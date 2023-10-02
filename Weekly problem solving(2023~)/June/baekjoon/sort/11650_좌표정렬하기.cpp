#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}


int main(){
    std::cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    vector<pair<int, int> > v;
    std::cin >> n;

    while(n--){
        int a,b;
        std::cin >> a >> b;
        v.emplace_back(a,b);
    };

    sort(v.begin(),v.end(),compare);

    for(int i=0;i<v.size();i++){
        std::cout << v[i].first << " " << v[i].second << '\n';
    };


}