#include <iostream>
#include <algorithm>

using namespace std;
int N,K;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int coins[10];// 10 개 고정으로 주어지니까
    cin >> N >> K;


    // 만약 동전으로 주어지는 크기와 K가 딱 맞으면 바로 1 return
    bool stop = false;
    for(int i=0;i<N;i++){
        cin >> coins[i];
        if(coins[i]==K){
            stop = true;
        }
    }
    // K값을 가지는 동전이 있나요? 확인
    if(stop){
        cout << 1 << endl;
        return 0;
    }

    int cnt = 0;
    
    /**
     * 동전이 큰값부터 돌면서 K보다 작거나 같은 동전이 있으면
     * 그 동전 몇개로 K에 가깝게 만들 수 있는지 체크 = temp
     * temp 는 필요동전에 더해주고,
     * 구한 동전 갯수와 동전을 곱해준 값을 K에서 뺴주면 잔돈 나옴 = K
     * K == 0 이면 종료
     * 
    */
    for(int i=N-1;i>=0;i--){
        if(K==0){
            break;
        }
        if(K>=coins[i]){
            int temp = K/coins[i];
            cnt+=temp;
            K-=temp*coins[i];
        }
    }

    cout << cnt << endl;

    return 0;

    

}