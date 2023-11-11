#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int arr[3]={1,7,14};

    int N;
    int cnt=0;
    cin >> N;

    if(N==1){
        cout << 1 << endl;
        return 0;
    }

    while(N!=0){
        if(N<7){
            cnt+=N;
            N=0;
        }else if(N<14){
            cnt+=N/arr[1];
            N%=arr[1];
        }else if(N>=14){
            cnt+=N/arr[2];
            N%=arr[2];
        }
    }
    cout << cnt << endl;

}