#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> coin ={1,2,3,4,5,7};
    int len = coin.size();

    vector<bool> pos(len-2,false);
    pos.insert(pos.end(),2,true);
    do{
        string temp = "";
        for(int i=0;i<len;i++){
            if(pos[i])
                temp+='0'+coin[i];
        };
        cout << temp << endl;

    }while(next_permutation(pos.begin(),pos.end()));
}