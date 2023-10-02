#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int answer = 0;
    int n;
    vector<int> v;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.emplace_back(num);
    };
    sort(v.begin(), v.end());

    for(int i=n-3;i>=0;i--){
        if(v[i+2]<v[i]+v[i+1]){
            answer = v[i]+v[i+1]+v[i+2];
            break;
        }else if(i==0){
            answer = -1;
        }
    }
    
    cout << answer << '\n';
}