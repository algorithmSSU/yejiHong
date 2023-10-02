#include <iostream>
#include <vector>
// 수열 - 슬라이딩 윈도우 방식 
// iter 을 돌때 윈도우사이즈보다 i가 커지면 앞에값 계속 빼주면서 값 갱신
using namespace std;

int main(){

    int n, day;
    vector<int> temp;
    cin >> n >> day;

    int arr[100001];

    for(int i=0;i<n;++i){
        cin >> arr[i];
    };


    int start = 0;
    int sum = 0;
    int maxsum = -1e9;

    for(int i=0;i<n;++i){
        sum+=arr[i];

        if(i>=day-1){
            maxsum = maxsum >= sum ? maxsum : sum;
            sum-= arr[start++];
        }
    };

    cout << maxsum << '\n';
    
}