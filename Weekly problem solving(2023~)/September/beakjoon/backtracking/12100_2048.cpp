#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n;
int Answer;
int map[21][21];
int original_map[21][21];
int Select[5];

int Bigger(int A,int B){
    if(A>B){
        return A;
    }
    return B;
}



// 오리지널 맵에 입력을받아둔다.
// 그리고 오리지널 맵을 복사해두고 거기에 이제 경우의수로 계산을 하면서 최대 값을 구한다.
void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> original_map[i][j];
        }
    }
}



// 오른쪽으로 이동
void move_right(){

    // 맨오른쪽 기준으로 수행
    // 커서를 오른쪽 -> 왼쪽 옮겨주면서 비교
    // 1. 현재 값이 0 일때
    for(int i=0;i<n;i++){
        for(int j=n-1;j>0;j--){
            if(map[i][j]==0){ // 현재 값이 0이면
                int k = j-1;
                bool flag = false;
                while(k>=0){
                    if(map[i][k]!=0){
                        flag = true;
                        break;
                    }
                    k--; // 커서를 계속 앞쪽(왼쪽)으로 떙겨준다.
                }
                if(flag){
                    map[i][j]=map[i][k]; // 오른쪽 기준으로 바로 <- 앞 값을 넣어준다
                    map[i][k]=0;
                }
            }
        }
    }


    // 2. 현재 값 == 바로 왼쪽 값
    for(int i=0;i<n;i++){
        for(int j=n-1;j>0;j--){
            if(map[i][j]==map[i][j-1]){ // 현재 값 == 바로 앞의 값
                map[i][j]=map[i][j]*2;
                map[i][j-1]=0;
            }
        }
    }

    // 3. 다시 옮겨주고 빈자리(0) 에 값 땡겨주기
    for(int i=0;i<n;i++){
        for(int j=n-1;j>0;j--){
            bool flag = false;
            if(map[i][j]==0){
                int k = j-1;
                while(k>=0){
                    if(map[i][k]!=0){
                        flag=true;
                        break;
                    }
                    k--;
                }
                if(flag){
                    map[i][j]=map[i][k];
                    map[i][k]=0;
                }
            }
        }
    }

}

// 왼쪽으로 이동
void move_left(){

    // 가장 왼쪽(시작) 위치를 기준으로 오른쪽값을 탐색
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(map[i][j]==0){
                int k=j+1;
                bool flag =false;
                while(k<=n-1){
                    if(map[i][k]!=0){
                        flag= true;
                        break;
                    }
                    k++;
                }
                if(flag){
                    map[i][j]=map[i][k];
                    map[i][k]=0;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(map[i][j]==map[i][j+1]){
                map[i][j]=map[i][j]*2;
                map[i][j+1]=0;
            }
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(map[i][j]==0){
                int k = j+1;
                bool flag= false;
                while(k<=n-1){
                    if(map[i][k]!=0){
                        flag=true;
                        break;
                    }
                    k++;
                }
                if(flag){
                    map[i][j]=map[i][k];
                    map[i][k]=0;
                }
            }
        }
    }
}

// 아래로 이동
void move_down(){

    // 현재 위치 값이 0 이면 아래로 떙겨 내려주기-----> 맨 아래가 기준
    for(int i=n-1;i>0;i--){
        for(int j=0;j<n;j++){
            if(map[i][j]==0){
                int k = i-1;
                bool flag= false;
                while(k>=0){
                    if(map[k][j]!=0){
                        flag= true;
                        break;
                    }
                    k--;
                }
                if(flag){
                    map[i][j]=map[k][j];
                    map[k][j]=0;
                }
            }
        }
    }

    // 바로 위 값이랑 같으면 현재 위치로 땡겨주기
    for(int i=n-1;i>0;i--){
        for(int j=0;j<n;j++){
            if(map[i][j]==map[i-1][j]){
                map[i][j]=map[i][j]*2;
                map[i-1][j]=0;
            }
        }
    }

    // 다시 빈공간에 땡겨주기
    for(int i=n-1;i>0;i--){
        for(int j=0;j<n;j++){
            bool flag = false;
            if(map[i][j]==0){
                int k = i-1;
                while(k>=0){
                    if(map[k][j]!=0){
                        flag = true;
                        break;
                    }
                    k--;
                }
                if(flag){
                    map[i][j] = map[k][j];
                    map[k][j]=0;
                }
            }
        }
    }
}

// 위로 이동
void move_up(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            bool flag = false;
            if(map[i][j]==0){
                int k = i+1;
                while(k<=n-1){
                    if(map[k][j]!=0){
                        flag=true;
                        break;
                    }
                    k++;
                }
                if(flag){
                    map[i][j] = map[k][j];
                    map[k][j]=0;
                }
            }
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==map[i+1][j]){
                map[i][j]=map[i][j]*2;
                map[i+1][j]=0;
            }
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            bool flag= false;
            if(map[i][j]==0){
                int k = i+1;
                while(k<=n-1){
                    if(map[k][j]!=0){
                        flag = true;
                        break;
                    }
                    k++;
                }
                if(flag){
                    map[i][j] = map[k][j];
                    map[k][j]=0;
                }
            }
        }
    }
}

// original copy map
void copy_map(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[i][j] = original_map[i][j];
        }
    }
}

// 맵 안에서 최대 값 찾기
int find_Max(){
    int Max = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            Max = Bigger(Max,map[i][j]);
        }
    }
    return Max;
}

// 이동을 완료해주고 최대 값 찾기
void play(){
    for(int i=0;i<5;i++){
        int dir = Select[i];
        if(dir==0){
            move_right();
        }else if(dir==1){
            move_left();
        }else if(dir==2){
            move_down();
        }else if(dir==3){
            move_up();
        }
    }
    int FM = find_Max();
    Answer = Bigger(Answer,FM);
}


// 방향 경우의 수 구하기
void dfs(int Idx, int cnt){
    if(cnt==5){
        //복사
        copy_map();
        //계산
        play();
        return;
    }
    for(int i=0;i<4;i++){
        Select[cnt]=i;
        dfs(i,cnt+1);// 다음 인덱스 가리키기
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    dfs(0,0);
    cout << Answer << '\n';

    return 0;
}