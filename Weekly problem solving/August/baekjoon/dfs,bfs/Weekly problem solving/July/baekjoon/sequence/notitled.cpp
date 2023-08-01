#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> number;

    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        number.emplace_back(tmp);
    }
    
    int in = 1;
    int de = 1;
    int result = 1;



    for(int i=0;i<n-1;i++){
        if(number[i]<=number[i+1]){
            in++;
        }else{
            in = 1;
        };
        if(number[i]>=number[i+1]){
            de++;
        }else{
            de = 1;
        };
        int save = de >= in ? de : in;
        result = save >= result ? save : result;
    };

    cout << result << '\n';

}