#include <iostream>
#include <vector>
#include <memory.h>
#include <string>
#include <algorithm>
#include<cstring>

using namespace std;

#define MAX 16
int Area[MAX][MAX]={0,};
bool visited[MAX][MAX]={false,};
int N, M;

void init(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            Area[i][j]=0;
        }
    }
}

void input(int N){

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> Area[i][j];
        }
    }
}

int solution(int y,int x){

    int box_sum = 0;

    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            int ny = y + i;
            int nx = x + j;
            if(ny>=0 && nx>=0 && ny<N && nx<N){
                box_sum+=Area[ny][nx];
            }
        }
    }

    return box_sum;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int test_case;
    int T;

    cin >> T;
    for(test_case=1;test_case<=T;++test_case){
        cin >> N  >> M;

        // 맵 정보 받아서 설정
        input(N);

        // 모두 돌아다니면서 M크기 방향 탐색
        // 최대 값 갱신
        
        int max_box = -1e9;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int temp = solution(i,j);
                max_box = max(max_box, temp);
            }
        }  

        init();

        cout << "#" << test_case << " " << max_box << endl;
    }
    return 0;
}