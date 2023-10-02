#include <iostream>
#include <string.h>
#include <vector>
#include <set>
using namespace std;


// bitmasking 방법

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int num = 0;
    int bitmask = 0;
    while(n--){
        string input;
        cin >> input;

        if(input=="add"){
            cin >> num;
            bitmask|= (1<<num);
        }else if(input=="remove"){
            cin >> num;
            bitmask&= ~(1<<num);
        }else if(input=="check"){
            cin >> num;
            if(bitmask&(1<<num)){
                cout << '1' << endl;
            }else{
                cout << '0' << endl;
            }
        }else if(input=="toggle"){
            cin >> num;
            bitmask^=(1<<num);
        }else if(input=="all"){
            bitmask = (1<<21)-1;
        }else if(input=="empty"){
            bitmask = 0;
        }
    };
    return 0;
}