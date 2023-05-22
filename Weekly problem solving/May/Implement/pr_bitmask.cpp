#include <iostream>
using namespace std;

int main(){


    int n=5;
    int mask =0;

    while(n--){
        int num;
        cin >> num;
        mask |= (1 <<num);
        cout << mask << endl;
    }
}