#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

// 입력으로 최 10^5자리가 들어오므로 Int 범위를 함참 넘기 때문에 stoi를 쓰면안됨
// 30의 배수 판정법을 이용하자
// 각 자릿수 더했을 때 3의 배수인지
// 맨 끝이 0으로 끝나는지


// char to int : char - '0'
// int to char : int + '0'


int main(){
    string s;
    priority_queue<int,vector<int>,less<int> > q;
    cin >> s;
    
    for(int i =0;i<s.length();i++){
        int d;
        d = s[i] - '0';// char to int
        q.push(d);
    };
    

    string ns;
    char c;
    int checksum=0;
    while(!q.empty()){
        checksum+=q.top();
        c = q.top() + '0';
        ns+=c;
        q.pop();
    }
    
    if(checksum%3==0 && ns[ns.size()-1]=='0'){
        cout << ns << endl;
    }else{
        cout << -1 << endl;
    }



}