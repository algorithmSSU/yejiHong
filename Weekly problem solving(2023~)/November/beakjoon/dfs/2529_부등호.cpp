#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
int N;
vector<char> op;
bool visited[10]={false,};
vector<string> ans;

bool isvalid(string num){
    for(int i=0;i<N;i++){
        if(op[i]=='>'){
            if(num[i]<num[i+1]){
                return false;
            }
        }else if(op[i]=='<'){
            if(num[i]>num[i+1]){
                return false;
            }
        }
    }
    return true;
}


void dfs(int idx,string num){
    if(idx == N+1){
        if(isvalid(num)){
            ans.emplace_back(num);
        }
        return;
    }
    for(int i=0;i<10;i++){
        if(!visited[i]){
            visited[i] =true;
            dfs(idx+1,num+to_string(i));
            visited[i] = false;
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    for(int i=0;i<N;i++){
        char c;
        cin >> c;
        op.emplace_back(c);
    }

    dfs(0,"");
    auto p = minmax_element(ans.begin(),ans.end());
    cout << *p.second << '\n' << *p.first << '\n';


}