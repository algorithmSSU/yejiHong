#include <iostream>
#include <vector>


//거꾸로 뒤져보자
using namespace std;

int main(){
    int a,b;
    int answer =0;
    cin >> a >> b;

    while(a<=b){
        answer++;
        if(a==b){
            break;
        };

        if(b%2==0){
            b/=2;
        }else if(b%10==1){
            b--;
            b/=10;
        }else{
            break;
        }
    };
    if(a==b){
        cout << answer << endl;
    }else{
        cout << -1 << endl;
    }

}