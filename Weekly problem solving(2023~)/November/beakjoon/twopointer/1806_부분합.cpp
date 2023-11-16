#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
////// 바킹됵

int N, S;
int arr[100001];
int save[100001]={0,};
vector<int> ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> S;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    
    for(int i=1;i<=N;i++){
        if(arr[i]==S){
            ans.push_back(1);
        }
        save[i] = save[i-1]+arr[i];// 누적값
        if(save[i] == S){
            ans.push_back(i);
        }
        if(save[i]-save[i-1] + arr[i-1] == S){
            ans.push_back(2);
        }
    }

    if(!ans.empty()){
        sort(ans.begin(),ans.end());
        cout << ans.front() << endl;
    }else{
        cout << 0 << endl;
    }
    

    


}