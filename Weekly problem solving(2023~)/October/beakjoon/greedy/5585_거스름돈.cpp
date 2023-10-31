#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> money= {500,100,50,10,5,1};

    int pay = 0;
    int cnt = 0;

    cin >> pay;
    pay = 1000 - pay;

    while(pay){
        for(int i=0;i<money.size();i++){
            if(money[i]<=pay){
                int s = pay/money[i];
                cnt+=s;
                pay -= money[i]*s;
                
            }
        }
    }

    cout << cnt << endl;

}