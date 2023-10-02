#include <iostream>
#include <vector>

using namespace std;


int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int diff = 1;
    while(n>diff){
        n = n-diff;
        diff++;
    }

    if (diff % 2 == 1)
        cout << diff + 1 - n << '/' << n << endl;
    else
        cout << n << '/' << diff + 1 - n << endl;


}


