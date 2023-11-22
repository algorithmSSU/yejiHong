#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
int cnt = 0;



void dfs(int num){
    if(num>=N){
        if(N==num){
            cnt++;
        }
        return;
    }
    for(int i=1;i<=3;i++){
        dfs(num+i);
    }
}
int main(){
    int Case;
    cin >> Case;
    while(Case--){
        cin >> N;
        dfs(0);
        cout << cnt << endl;
        cnt = 0;
    }
    

}