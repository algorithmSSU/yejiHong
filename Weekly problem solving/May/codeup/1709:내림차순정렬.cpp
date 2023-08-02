#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool comp(int a,int b){
    return a>b;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<int> v;
    int n;
    cin >> n;

    while(n--){
        int num;
        cin >> num;
        v.emplace_back(num);
    };

    sort(v.begin(),v.end(),comp);
    for(auto i : v){
        cout << i << " ";
    }
    cout << '\n';
    
    








}