#include <iostream>
#include <vector>

using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int total;
    int n;
    cin >> total;

    cin >> n;
    
    int ans=0;
    for(int i=0;i<n;i++){
       int bill, c, res;
       cin >> bill >> c;
       res = bill*c;
       ans+=res;
    };

    if(ans==total){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}