#include <iostream>
#include <string.h>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    int n;
    string input, answer;
    cin >> n;
    cin >> input;
    stack<int> s;

    for(int i=input.length()-1;i>=0;i--){
        s.push(input[i]);
    };
    if(n<=3){
        cout << input << endl;
        return 0;
    }else{
        int front = n % 3;

        for (int i = 0; i < front; i++)
        {
            answer += s.top();
            s.pop();
        };
        if(front!=0){
            answer += ',';
        }
        
        int cnt = 0;
        while (!s.empty())
        {
            answer += s.top();
            s.pop();
            cnt++;
            if (cnt % 3 == 0)
            {
                answer += ',';
            }
        };
        answer.pop_back();

        cout << answer << endl;
    }
    
    
    
}