#include <iostream>
#include <vector>

using namespace std;

int main(){

    int dest, line, n;
    vector<vector<int> > info;

    int dest_row = 0; // 역의 행,
    for(int i=0;i<n;i++){
        for(int j=0;j<line;j++){
            int stn;
            cin >> stn;
            if(stn == dest){
                dest_row=i;
            }
            info[i].emplace_back(stn);
        };
    };

    int log[1001] = {false,};

    // 역이 있는 행의 맨 앞 머리
    int bts = info[dest_row][0];
    int move = 0;
    while (info[0][0] != bts){
        for(int i=0;i<n;i++){
            for(int j=0;j<line;j++){
                
            }
        }

        bts = info[][0];
    }
}