#include <iostream>
#include <vector>

using namespace std;
int answer[1001][4];
int main(){
    int dollor;
    int N;
    cin >> N;
    int n = N;
    

    int coins[4]={25,10,5,1};
    
    
    for(int i=0;i<N;i++){
        int coin_cnt[4]={0,0,0,0};
        cin >> dollor;
        for(int i=0;i<4;i++){
            if(dollor >= coins[i]){
                int money = dollor/coins[i];
                dollor%=coins[i];
                coin_cnt[i]=money;
            }
        }
        for(int j=0;j<4;j++){
            answer[i][j] = coin_cnt[j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            cout << answer[i][j] << " ";
        }
        cout << '\n';
    }


    
    

    


}