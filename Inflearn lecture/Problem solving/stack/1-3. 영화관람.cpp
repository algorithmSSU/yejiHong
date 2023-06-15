#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 54 52 57 50 52 53 51
// 51

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(n+1,0);
    vector<int> ans(n+1,0);
    stack<int> s;

    for(int i=1;i<=n;i++){
        cin >> v[i];
    };

    for(int j=n;j>=1;j--){
        while(!s.empty()&&v[j]>v[s.top()]){
            ans[s.top()]=j;
            s.pop();
        };
        // stack 에 없으면 
        s.push(j);
    }

    for(int i=1;i<ans.size();i++){
        cout << ans[i] << " ";
    }

}