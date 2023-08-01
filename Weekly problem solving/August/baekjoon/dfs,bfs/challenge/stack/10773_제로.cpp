#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    stack<int> s;
    int answer = 0;
    for(int i=0; i<n;i++){
        int temp;
        cin >>temp;
        if(temp!=0){
            s.push(temp);
        }else{
            s.pop();
        };  
    };
    
    while(!s.empty()){
        answer+=s.top();
        s.pop();
    };
    
    cout << answer << endl;
    
}