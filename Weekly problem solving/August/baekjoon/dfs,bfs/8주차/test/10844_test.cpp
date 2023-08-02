#include <iostream>
using namespace std;
#define mod 1000000000
int arr[101][10]={0,};

int main(){

    int n;
    cin >> n;

    for (int i = 1; i < 10;i++){
        arr[1][i] = 1;
    };

    // 1 2 3 4 5 6 7 8 9

    for (int i = 2; i <= n;i++){
        for (int j = 0; j < 10;j++){
            if(j==0){
                arr[i][0] = arr[i - 1][j+1];
            }else if(j==9){
                arr[i][9] = arr[i - 1][j - 1];
            }else{
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
            };

            arr[i][j] %= mod;
        }
    };

    int result = 0;
    for (int i = 0;i<10;i++){
        result = (result + arr[n][i]) % mod;
    };

    cout << result << endl;
}