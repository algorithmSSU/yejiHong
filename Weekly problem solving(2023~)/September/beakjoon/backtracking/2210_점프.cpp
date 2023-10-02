#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

char Map[5][5];
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
map<string,int> dict;
char pos[6];

void input(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> Map[i][j];
        }
    }
}

void search(int y,int x,int cnt){
    if(cnt==6){
        string str;
        for(auto it : pos){
            str+=it;
        }

        dict[str]+=0;
        return;
    }
    for(int i=0;i<4;i++){
        int ny = dy[i]+y;
        int nx = dx[i]+x;
        if(ny>=0 && nx>=0 && ny<5 && nx<5){
            pos[cnt] = Map[ny][nx];
            search(ny,nx,cnt+1);
        }
    }
}





int main(){
    input();

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            string text;
            text+=Map[i][j]+'0';
            search(i,j,0);
        }
    }

    map<string,int> :: iterator it;
    // for(it=dict.begin();it!=dict.end();it++){
    //     cout << it->first << " ";
    // }

    cout << dict.size() << '\n';

}