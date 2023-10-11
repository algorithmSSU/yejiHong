#include <iostream>
#include <vector>


// 튀튀 여기서 부터 다시....


using namespace std;

int n;
int cnt[41][2];

int fibo(int n,int idx){
    if(n==0){
        cnt[idx][0]++;
        return 0;
    }else if(n==1){
        cnt[idx][1]++;
        return 1;
    }else{
        return fibo(n-1,idx) + fibo(n-2,idx);
    }
};


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;

    for(int i=0;i<n;i++){
        int Case;
        int temp;
        cin >> Case;
        temp = fibo(Case,i);
    }
    for(int i=0;i<n;i++){
        cout << cnt[i][0] << " " << cnt[i][1] << '\n';
    }

}