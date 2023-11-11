#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    string x,y;
    string nx,ny;
    string answer;
    cin >> x >> y;

    for(int i=x.length()-1;i>=0;i--){
        nx+=x[i];
    }
    for(int j=y.length()-1;j>=0;j--){
        ny+=y[j];
    }

    int X = stoi(nx);
    int Y = stoi(ny);
    int SUM = X+Y;

    answer = to_string(SUM);
    reverse(answer.begin(),answer.end());
    SUM = stoi(answer);
    cout << SUM << endl;
    
    

    
}