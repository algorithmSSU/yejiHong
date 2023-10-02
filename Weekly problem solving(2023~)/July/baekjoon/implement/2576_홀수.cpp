#include <iostream>
#include <vector>


using namespace std;

int main(){
    
    int sum = 0;
    int minvalue = 101;
    bool ch = false;
    for(int i=0;i<7;i++){
        int temp;
        cin >> temp;
        if(temp%2==1){
            ch = true;
            minvalue = minvalue > temp ? temp : minvalue;
            sum+=temp;
        };
    };

    if(!ch){
        cout << -1 << endl;
    }else{
        cout << sum << '\n' << minvalue << '\n';
    }


    

    

}