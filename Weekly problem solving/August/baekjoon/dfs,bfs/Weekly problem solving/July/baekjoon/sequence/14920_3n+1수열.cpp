#include <iostream>
#include <vector>

using namespace std;

int main(){
    int arr[100001];

    int n;
    cin >> n;

    int cnt = 1;
    
    while(n!=1){
        cnt++;
        if(n==1){
            break;
        };

        if(n%2==0){
            n/=2;
        }else if(n%2==1){
            n=n*3+1;
        }
    };

    cout << cnt << endl;
}