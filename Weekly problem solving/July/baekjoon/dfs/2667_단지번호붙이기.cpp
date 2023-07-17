#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

// 18일에 마저 하기

using namespace std;

int n;
int m[26][26]={0,};
bool visited[26][26]={false,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};

int cnt = 0;
int dfs(int y,int x){
    visited[y][x] = true;
    cnt++;

    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny>=n || nx>=n || ny<0 || nx<0){
            continue;
        }else{
            if(!visited[ny][nx] && m[ny][nx]==1){
                dfs(ny,nx);
            }
        }
    }

    return cnt;
}


int main(){
    cin >> n;

    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++){
            m[i][j]=str[j]- '0';
        }
    }

    vector<int> ans;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp = 0;
            if(m[i][j]==1 && visited[i][j]==false){
                temp=dfs(i,j);
                //cout << temp << endl;
                ans.emplace_back(temp);
                temp=0;
                cnt=0;
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << '\n';
    }

}