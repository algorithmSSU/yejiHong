#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int arr[31]={0,};
    int n =28;

    while(n--){
        int id;
        cin >> id;
        arr[id]=1;
    };
    for(int i=1;i<30;i++){
        if(!arr[i]){
            cout << i << '\n';
        }
    }

}