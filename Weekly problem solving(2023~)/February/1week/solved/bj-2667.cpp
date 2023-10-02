#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int map[26][26]={0,};
int visited[26][26]={0,};
int n;
int my[4]={-1,1,0,0};
int mx[4]={0,0,-1,1};

int bfs(int y,int x){

    queue < pair<int, int> > q;
    q.push(make_pair(y,x));
    int cnt= 0;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int ny = cy+my[i];
            int nx = cx+mx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=n){
                continue;
            };
            if(visited[ny][nx]==0 && map[ny][nx]==1){
                cnt++;
                visited[ny][nx]=1;
                q.push(make_pair(ny,nx));
                
            };
        };
        if(cnt==0){
            cnt++;
        }
    };
    return cnt;
};



int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    
    string str;
    for(int i=0;i<n;i++){
        cin >> str;
        for(int j=0;j<str.length();j++){
            if(str[j]=='0'){
                map[i][j]=0;
            }else{
                map[i][j]=1;
            } 
        };
    };


    int count =0;
    vector<int> apart;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==1 && visited[i][j]!=1){
                count=bfs(i,j);
                //cout << count << endl;
                if(count>0){
                    apart.push_back(count);
                    count=0;
                };
                
            }
        }
    }

    sort(apart.begin(),apart.end());

    cout << apart.size() << endl;

    for(int i=0;i<apart.size();i++){
        cout << apart[i] << "\n";
    }


/*
   for(int i=0;i<n;i++){
    cout<< "\n";
    for(int j=0;j<n;j++){
        cout << map[i][j];
    }
   }
*/
    
    return 0;



}


/*

- 모든 정점을 방문한다.
- 아직 방문하지 않았으며 && 1인 정점을 찾으면 그 정점 부터 bfs 로 인접한(상/하/좌/우) 곳에 1이 있는 지 탐색 후
있으면 count 를 1씩 증가시키고 return 한다.
- return 받은 연결요소들의 갯수를 연결요소갯수를 담는 벡터에 담는다.
- 벡터를 오름차순으로 정렬시키고   벡터의 크기, 벡터의 요소들을 출력한다.



*/