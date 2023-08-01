#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// https://www.acmicpc.net/problem/5430
// 답변기다리기

using namespace std;
vector<string> answer;


void process(){
    string order, source;
    int n;
    vector<int> v;

    cin >> order;
    cin >> n;
    cin >> source;

    int end = n+(n-1);
    for(int i=1;i<=end;i++){
        int c;
        if(source[i]!=',' && source[i]!=']'){
            c = int(source[i]) - '0';//char to int
            v.emplace_back(c);
        }
    };
    
    int cursor = 0;
    int bcursor = v.size()-1;
    int way = 0;
    for(int i=0;i<order.size();i++){
        if(order[i]=='R'){
            way++;  
        };
        if(order[i]=='D'){
            if(v.size()==0 || cursor<0){
                answer.emplace_back("error");
                return;
            }
            if(way%2==1){
                bcursor--;    
            }else if(way%2==0){
                cursor++;
            }
    }};

    if(way%2==1){
        if(v.size()!=0 && bcursor<0){
            //answer.emplace_back("[]");
            answer.emplace_back("error");
        }else{
        string st = "[";
        for(int i=bcursor;i>=cursor;i--){
            char c = v[i] + '0';
            if(i==cursor){
                st+=c;
            }else{
                st += c;
                st += ',';
            }
        };
        st+="]";
        answer.emplace_back(st);}
    }else{
        if (cursor > v.size())
            answer.emplace_back("error");
            //answer.emplace_back("[]");
        else
        {
        string st = "[";
        for (int i = cursor; i < v.size(); i++)
        {
            char c = v[i] + '0';
            if (i == v.size() - 1)
            {
                st += c;
            }
            else
            {
                st += c;
                st += ',';
            }
        };
        st += "]";
        answer.emplace_back(st);
        }
    }
};

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        process();
    }
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << endl;
    };


    return 0;
}


// 왜 메모리초과??..