#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int step[301];
int n;
int dp[301]={0,};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> step[i];
    }
    dp[1]=step[1]+step[2];

    int idx=2;
    int i=2;
    while(i<=n){
        if(i+2==n){
            dp[idx++]=step[i+2];
            break;
        }else if(i+1==n){
            dp[idx++]=step[i+1];
            break;
        }else{
            if(step[i+1]<step[i+2]){
                dp[idx++]=step[i+2];
                i+=2;
            }else{
                dp[idx++]=step[i+1];
                i+=1;
            }
        }   
    }

    int sum = 0;
    for(int i=1;i<idx;i++){
        sum+=dp[i];
    }
    cout << sum << endl;

    


    

}