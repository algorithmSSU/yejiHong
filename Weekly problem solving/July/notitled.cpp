#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
    string text;
    text = "hello yeji hello hello holy helly what the hell";

    int pos = 0;


    string find_text = "hello";
    int size = find_text.size();
    while(1){
        int idx = text.find(find_text,pos);
        if(idx!=string::npos){
            text.erase(idx,size);
            std::cout << text << endl;
            
        }else{
            break;
        }
    };
    remove(text.begin(),text.end(),' ');
    std::cout << text << endl;


    vector<int> a;
    vector<int>::iterator p;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    queue<int> q;
    q.front();

    stack<int> s;
    //s.pop();

    for(p=a.end();p!=a.begin();p--){
        s.push(*p);
    }
}