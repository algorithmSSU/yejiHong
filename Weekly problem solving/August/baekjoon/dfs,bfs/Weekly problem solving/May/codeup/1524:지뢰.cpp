#include <iostream>
#include <string.h>

using namespace std;

char arr[12][12];

int dy[8]={0,0,1,-1,-1,-1,1,1};
int dx[8]={-1,1,0,0,-1,1,-1,1};

int search(int y,int x){

    int ny,nx =0;
    int count =0;

    if (arr[y][x] == 1) // 지뢰닷
    {
        return -1;
    }
    for(int i =0;i<8;i++){
        ny = y+dy[i];
        nx = x+dx[i];
        if(ny<0 || ny>10 || nx<0 || nx>10){
            continue;
        }else if(arr[ny][nx]=='1'){
            count++;
        }
    }
    return count;
}


int main(){

    //cin.tie(0);
    //ios_base::sync_with_stdio(false);
    string line;
    int a,b,ans;
    int n =9;

    for(int i=0;i<n;i++){
        string input;
        getline(cin,input,'\n');
        //😨
        remove(input.begin(),input.end(),' ');
        for(int c=0;c<input.length();c++){
            arr[i][c]=input[c];
        }
        input="";
            
    }

    cin >> a >> b;
    a =a-1;
    b =b-1;
    ans = search(a, b);

    if(ans<0){
        cout << -1 << endl;
    }else if(ans>0){
        cout << ans << endl;
    }else{
        cout << 0 << endl;
    }
    
}