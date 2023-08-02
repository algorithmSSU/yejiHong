#include <iostream>
#include <vector>

using namespace std;

int main(){
    int answer = 0;
    int n,m;
    cin >> n >> m;

    int arr[100001];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    };


    int startidx = 0;
    int endidx = 0;
    int len = 0;
    int sum = 0;
    int minlen = 1e9;


    while(endidx<=n){
        if(sum>=m){
            minlen = minlen < endidx - startidx ? minlen : endidx-startidx;
            sum-=arr[startidx++];
        }else if(endidx == n){
            break;
        }else{
            sum+=arr[endidx++];
        }

    };
    if(minlen==1e9)
        answer = 0;
    else{
        answer = minlen;
    }

    cout << answer << '\n';


}