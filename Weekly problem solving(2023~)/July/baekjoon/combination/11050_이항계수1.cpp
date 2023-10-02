#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m;
    cin >> n  >> m;
    
    int count = m;
    int mom=1;
    int child = 1;
    while(count--){
        mom*=n--;
        child*=m--;
    };

    cout << mom/child << '\n';

}