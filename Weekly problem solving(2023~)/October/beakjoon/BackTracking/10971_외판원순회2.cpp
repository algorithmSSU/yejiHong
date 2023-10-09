#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long map[11][11];
bool visited[11]={false,};
int Case[11];
long long Min = 1e9;


// 계산
long long cost_cal(int *arr,int size){
    long long cost_sum=0;
    for(int i=1;i<=size-1;i++){
        int y = arr[i];
        int x = arr[i+1];
        if(map[y][x]==0){
            return 0; // 해당 경로로는 모든 곳을 이동할 수 없다.
        }
        cost_sum+=map[y][x];
    }
    return cost_sum;

}



void all_case(int pos){
    if(pos==N+1){
        
        Case[N+1]=Case[1];
        // for(int i=1;i<pos;i++){
        //     cout << Case[i] << " ";
        // }

        long long temp = cost_cal(Case,N+1);
        if(temp==0){
            return;
        }
        Min=min(temp,Min);
        // 거리계산
        // 배열 맨앞자리를 맨뒤에 하나 더넣어주기
        return;
    }
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            visited[i]=true;
            Case[pos]=i;
            all_case(pos+1);
            visited[i]=false;
        }
    }

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> map[i][j];
        }
    }
    all_case(1);
    cout << Min << endl;




}