#include <iostream>
#include <vector>

using namespace std;

int main(){
    int test;
    cin >> test;

    vector<string> answer;

    for(int i=0;i<test;i++){
        int play;
        cin >> play;

        int player[2]={0,};
        for(int j=0;j<play;j++){
            char x,y;
            cin >> x >> y;
            if(x=='R' && y=='P'){
                player[1]++;
            }else if (x == 'R' && y == 'S'){
                player[0]++;
            }else if (x == 'P' && y=='R'){
                player[0]++;
            }else if (x=='S' && y=='R'){
                player[1]++;
            }else if(x=='P' && y=='S'){
                player[1]++;
            }else if(x=='S' && y=='P'){
                player[0]++;
            }
        };
        if(player[0] < player[1]){
            answer.emplace_back("Player 2");
        }else if(player[0] > player[1]){
            answer.emplace_back("Player 1");
        }else{
            answer.emplace_back("TIE");
        }
    };


    for(int i=0;i<answer.size();i++){
        cout << answer[i] << endl;
    }
}