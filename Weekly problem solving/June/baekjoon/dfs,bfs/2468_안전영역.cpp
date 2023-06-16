// 문제이해...종이에 그림 그려야할듯..

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int map[101][101];
int visited[101][101]={false,};
queue<pair<int,int> > q;
vector<pair<int,int> > safezone;
void bfs(){

    while(!q.empty()){
        //좌우위아래 비교했을 때 n보다 작은게 있어야하고,
        //n보다 작은게 아니면 비교해서 하나만 
    }

}


int main(){
    std::cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cin >> map[i][j];
            if(map[i][j]>=n){
                q.push(make_pair(i,j));
            };
        };
    };

    

}