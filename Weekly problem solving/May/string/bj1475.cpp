#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    string number;
    map<char,int> record;
    map<char,int>::iterator pointer;

    cin >> number;
    
    char comp;
    int comp_count = 0;
    for(int i=0;i<number.length();i++){
        record[number[i]]++;
        
    }

    int count = 0;
    int count_69 = 0;
    for(auto p : record){
        char now;
        now = p.first;
        if(now=='6' || now=='9'){
            count_69+=p.second;
        }else{
            count= count < p.second ? p.second : count;
        }
        
    }
    
    int a, b;
    a = count_69 / 2;
    b = count_69 % 2;
    count_69=a+b;

    int ans= 0;
    ans = count < count_69 ? count_69:count;

    cout << ans << endl;

    return 0;
}