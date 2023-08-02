#include <iostream>
#include <vector>

using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n = 0;
    int s = 0;
    cin >> n >> s;

    vector<int> v;
    while(n--){
        int temp;
        cin >> temp;
        v.emplace_back(temp);
    }


    int ans = 0;
    int sum = 0;

    for(int i=0;i<n;i++){
        cout << v[i] << endl;
    
    }
}