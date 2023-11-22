#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define INF 100000001

// 배열의 크기
int n = 3;
int Arr[3][3]={
    {0,3,11},
    {6,0,2},
    {3,INF,0}
};

int dist[3][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = Arr[i][j];
        }
    }
    
    // k = 거쳐가는 노드
    for(int k=0;k<n;k++){
        // i = 시작점
        for(int i=0;i<n;i++){
            // j = 도착점
            for(int j=0;j<n;j++){
                // k 를 거쳐가는 경우가 더 최단거리인 경우 갱신한다.
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }   
            }
        }
    }



    cout << "===Original Arr===" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << Arr[i][j] << " ";
        }
        cout << '\n';
    }

    cout << "===floyd Warshall===" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

}