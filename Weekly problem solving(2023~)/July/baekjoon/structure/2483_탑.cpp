#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){

    vector<int> ans;
    stack<pair<int,int> > s;

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;

    for(int i=0;i<n;i++){

        int x;
        cin >> x;
        if(s.empty()){
            s.push(make_pair(x,i));
            ans.emplace_back(0);
        }else{
            if (s.top().first < x)
            {
                while (1)
                {
                    if (s.empty() || s.top().first > x)
                    {
                        if (!s.empty())
                        {
                            ans.emplace_back(s.top().second);
                        }else if(s.empty()){
                            ans.emplace_back(0);
                        }
                        break;
                    }
                    else
                    {
                        s.pop();
                    }
                }
            }else if(s.top().first >= x){
                ans.emplace_back(s.top().second);
            }
        };
        s.push(make_pair(x,i+1));
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    };
    cout << '\n';




}