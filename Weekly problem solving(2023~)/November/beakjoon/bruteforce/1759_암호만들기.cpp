#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
int L,C;
char key[17];
bool visited[17]={false,};
vector<string> ans;

bool ok(string s){
    char tool[5]={'a','e','i','o','u'};
    int m =0;
    int j =0;
    bool flag = false;
    for(int i=0;i<s.length();i++){
        int temp_m = 0;
        for(int t=0;t<5;t++){
            if(tool[t]==s[i]){
                temp_m++;
            }
        }
        if(temp_m>0){
            m++;
        }else{
            j++;
        }
    }
    if(m>=1 && j>=2){
        return true;
    }
    return false;
    
}


void dfs(int idx,int size,string s){
    if(size == L){
        //cout << s << endl;
        ans.emplace_back(s);
        return;
    }
    for(int i=idx;i<C;i++){
        if(visited[i]){
            continue;
        }
        visited[i] = true;
        if(i == 0 || s[size-1]<key[i]){
            dfs(idx+1,size+1,s+key[i]);
            
        }
        visited[i] = false;
    }
}



int main(){
    cin >> L >> C;
    for(int i=0;i<C;i++){
        cin >> key[i];
    }
    sort(key,key+C);
    dfs(0,0,"");

    for(auto it : ans){
        if(ok(it)){
            cout << it << endl;
        }
    }

    return 0;
}