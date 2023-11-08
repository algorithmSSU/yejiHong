#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main(){

    vector<int> gredient = {2, 1, 1, 2, 3, 1, 2, 3, 1};
    vector<int> patty = {1,2,3,1};
    int gs = gredient.size();
    int ps = patty.size();

    int answer =0;

    string G;
    string P;

    for(int i=0;i<gredient.size();i++){
        G+='0'+gredient[i];
    }
    for(int j=0;j<patty.size();j++){
        P+='0'+patty[j];
    }


    int cnt = 0;
    int pi = 0;
    int cursor = 0;


    while(cursor<=gs){
        
        while(cursor<gs && G[cursor++] == P[pi++]){
            cout << cursor << endl;
            // cursor++;
            // pi++;
            cnt++;
        };
        
        if(cnt==ps){
            answer++;
            //cout << "cursor" << cursor << endl;
            G.erase(cursor-4,4);
            cursor = cursor-4 < 0 ? 0 : cursor-4;
            pi=0;
            cnt=0;
        }
        cursor++;
        pi=0;
        cnt=0;
    }

    cout << G << endl;

    cout << answer << endl;
}