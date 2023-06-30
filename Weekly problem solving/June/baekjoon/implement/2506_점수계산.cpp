#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> grade;
    int answer = 0;

    int before = 0;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        if(temp == 0){
            before = 0;
        }else if(temp==1 && before==0){
            answer++;
            before=1;
        }else if(temp==1 && before!=0){
            answer+=before+1;
            before+=1;
        }
    };

    cout << answer << endl;
    
}