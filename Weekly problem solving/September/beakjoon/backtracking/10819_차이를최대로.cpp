#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> arr;

int make_max(vector<int> v){
    int answer = 0;
    int s = v.size();
    for(int i=0;i<s-1;i++){
        answer+=abs(v[i]-v[i+1]);
    }
    return answer;
}


int cal(vector<int> v){
    int Max = -1;

    sort(v.begin(),v.end());

    do{
        int cur = make_max(v);
        Max = max(cur,Max);

    }while(next_permutation(v.begin(),v.end()));


    return Max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    };

    int res;
    res = cal(arr);
    cout << res << endl;


    
}