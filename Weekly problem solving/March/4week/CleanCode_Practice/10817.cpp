#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int second(vector<int> v){
    int size = v.size();
    int middle = size/2;
    sort(v.begin(),v.end());
    
    return v[middle];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a,b,c,answer;
    vector<int> v;
    cin >> a >> b >> c;
    
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    answer = second(v);

    cout << answer << endl;
    
}