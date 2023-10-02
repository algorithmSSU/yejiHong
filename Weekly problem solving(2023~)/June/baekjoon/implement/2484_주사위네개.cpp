#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n = 0;
    cin >> n;
    int king = 0;

    for(int i=0;i<n;i++){
        int res=0;
        map<int,int> game;
        map<int,int>::iterator p;
        for(int j=0;j<4;j++){
            int temp =0;
            cin >> temp;
            game[temp]++;
        };
        if(game.size()==2){
            int a = 0;
            for(p=game.begin();p!=game.end();p++){
                if(p->second==2){
                    a+=p->first;
                    res = 2000 + a * 500;
                }else if(p->second==3){
                    res = 10000 + p->first * 1000;
                    break;
                }
            };
        }else if(game.size()==1){
            res = 50000 + game.begin()->first * 5000;
        }else if(game.size()==3){
            for(p=game.begin();p!=game.end();p++){
                if(p->second==2){
                    res = 1000 + p->first * 100;
                }
            }
        }else if(game.size()==4){
            int max_noon = 0;
            for(p=game.begin();p!=game.end();p++){
                max_noon = max_noon < p->first ? p->first : max_noon;
            };
            res = max_noon * 100;
        }
        king = res < king ? king : res;
        
    };


    cout << king << '\n';
}