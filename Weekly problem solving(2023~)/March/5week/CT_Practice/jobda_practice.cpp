#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
queue<char> q;
int opindex = 0;

void q_fill(string S){
    for(int i=0;i<S.length();i++){
        if(S[i]=='-' || S[i]=='+'){
            opindex=i;
        }
        q.push(S[i]);
    };
};

void pick(queue<char> q){

    queue<char> sq;
    
    int cur = q.front();
    string news="";

    vector<char> before_op;
    for(int i=0;i<opindex;i++){
        before_op.push_back(q.front());
        q.pop();
    };
    
    vector<int> next;
    for(int i=0;i<before_op.size();i++){
        char now = before_op[i];
        string st;
        int count=0;
        st+=now;
        sq = q;
        for(int j=opindex;j<sq.size();j++){
            if(sq.front()!='-'||sq.front()!='+'){
                count++;
                sq.pop();
            }else{
                next.push_back(count);
                sq.pop();
            }
        }
    };

    for(int i=0;i<next.size();i++){
        cout << next[i] << endl;
    }

    
    

};

int op_check(string s){
    int plus, minus =0;
    if(s.find("+")!=string::npos){
        plus = 1; //있음
    }
    if(s.find("-")!=string::npos){
        minus =1; //있음
    }
    return plus+minus; // op가 하나라도 있으면 1 둘다 없으면 0
}


int solution(string S)
{
    int answer = 0;
    int operation = op_check(S);
    if(operation==0){
        
    }else{
        q_fill(S);
        pick(q);
    }


    return answer;
}

int main(){

    string s = "16-+23";
    solution(s);
}