#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N;
char op[10];
vector<string> ans;
bool visited[10]={false,};

bool isValid(char opr, char prev, char now){
    if(opr=='<'){
        if(prev > now){
            return false;
        }
    }else if(opr=='>'){
        if(prev < now){
            return false;
        }
    }
    return true;
    
}


void dfs(int idx, string number){
    if(idx==N+1){
        ans.emplace_back(number);
        return;
    }
    for(int i=0;i<10;i++){
        if(visited[i]){
            continue;
        }
        if(idx == 0 || isValid(op[idx-1], number[idx-1], i+'0')){
            visited[i] = true;
            dfs(idx+1,number+to_string(i));
            visited[i] = false;
        }
    }
}




int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> op[i];
    }
    dfs(0,"");
    auto p = minmax_element(ans.begin(),ans.end());
    cout << *p.second << endl;
    cout << *p.first << endl;
    
    return 0;
    
    
}