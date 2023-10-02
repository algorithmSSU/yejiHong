#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    vector<int> ans;
    //stack<int> s;

    stack<pair<int, int> > s;
    
    int n;
    cin >> n;
    while(n--){
        int tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    };


    for(int i=0;i<v.size();i++){
        if(s.empty()){
            s.push(make_pair(v[i],i+1));
            ans.push_back(0);
        }else{
            if(s.top().first>=v[i]){
                ans.push_back(s.top().second);
                s.push(make_pair(v[i],i+1));
            }else{

                if(s.top().first<v[i]){
                    while(!s.empty()){
                        if(s.top().first<v[i]){
                            s.pop();
                        }else if(s.top().first > v[i]){
                            break;
                        }
                    }
                }
                
                if(s.size()==0){
                    ans.push_back(0);
                    s.push(make_pair(v[i], i+1));
                }else{
                    ans.push_back(s.top().second);
                    s.push(make_pair(v[i],i+1));

                }
                
            };
        };
    };

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    };
    cout<< endl;

}