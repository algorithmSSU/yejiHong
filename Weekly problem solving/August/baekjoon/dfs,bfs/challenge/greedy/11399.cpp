#include <iostream>
#include <algorithm>
using namespace std;

int n, i;

int p[1000];

int main(){
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> p[i];
    };

    sort(p, p + n);

    int sum = 0;

    for (int j = 0; j < n;j++){
        sum += p[j] * (n - j);
    };
    /*
    

    */
    cout << sum << endl;
    return 0;
};