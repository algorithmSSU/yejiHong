#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int m;
    vector<int> v;
    cin >> N;
    m = N/2;

    while(N--){
        int num;
        cin >> num;
        v.emplace_back(num);
    }

    sort(v.begin(),v.end());
    cout << v[m] << endl;

}