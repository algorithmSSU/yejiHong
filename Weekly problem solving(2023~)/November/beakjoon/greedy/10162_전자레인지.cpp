#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int button[3]={300,60,10};
    int answer[3]={0,0,0};
    ios_base::sync_with_stdio(false);
    int T;
    cin >>T;

    int cnt = 0;
    for(int i=0;i<3;i++){
        if(T>=button[i]){
            answer[i] =T/button[i];
            T%=button[i];
        }
    }
    if(T!=0){
        cout << -1 << endl;
    }else{
        for(auto it : answer){
            cout << it << " ";
        }
        cout << '\n';
    }
    return 0;
}