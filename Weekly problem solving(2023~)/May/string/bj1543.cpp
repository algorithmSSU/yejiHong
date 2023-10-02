#include <iostream>
#include <string.h>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main(){

    string input, search;

    getline(cin,input);
    getline(cin,search);
    //cin >> input;
    //cin >> search;

    stack<char> s;
    deque<char> q;

    for(int i=0;i<search.length();i++){
        if(search[i]==' '){
            q.push_back('*');
        }else{
            q.push_back(search[i]);
        }   
        
    }
    for (int j=input.length()-1;j>0;j--){
        if(input[j]==' '){
            s.push('*');
        }else{
            s.push(input[j]);
        }
    }


    int count = 0;
    int tcount =0;
    int move = 0;
    while(!s.empty()){
        if(q.front()==s.top()){
            move++;
            count++;
            int tq = q.front();
            q.pop_front();
            q.push_back(tq);
            s.pop();
            
        }else{
            count=0;
            move=0;
            s.pop();
        }


        cout << move << endl;
        if(move==q.size() && count!=q.size()){
            count=0;
            move=0;
        }else if(move==q.size() && count==q.size()){
            count=0;
            tcount++;
            move = 0;
        }
    }

    cout << tcount << endl;


    
}