#include <iostream>
#include <vector>

using namespace std;

int fib_count= 0;
int fibonacci_count = 0;


int fib(int n){
    
    if(n==1 || n==2){
        fib_count++;
        cout << n << endl;
        return 1;
    }
    else{
        //fib_count++;
        return fib(n-1) + fib(n-2);
    }
    
}

int dp[100001]={0,};

int main(){

    int n;
    int a,b;
    dp[1] = 1;
    dp[2] = 1;
    cin >> n;
    a = fib(n);



    for(int i=3;i<=n;i++){
        fibonacci_count++;
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout << fib_count << " " << fibonacci_count << '\n';


}