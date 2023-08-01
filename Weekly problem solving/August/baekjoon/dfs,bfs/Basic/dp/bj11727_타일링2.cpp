#include <iostream>
#include <string.h>

using namespace std;

int d[1001]={0,};

int dp(int x){
    if(x==1) return 1;
    if(x==2) return 3;
    if(d[x]!=0) return d[x];

    return d[x] = dp(x-1) + dp(x-2);
}





int main(){

    int answer;
    answer = dp(4);
    cout << answer << endl;

}