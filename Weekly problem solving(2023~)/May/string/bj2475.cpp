#include <iostream>
#include <vector>


using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    int ans =0;
    for(int i=0;i<5;i++){
        int tmp;
        cin >> tmp;
        ans+=pow(tmp,2);


    };

    cout << ans%10 << endl;
}