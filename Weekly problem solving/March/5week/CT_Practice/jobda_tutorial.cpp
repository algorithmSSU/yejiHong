#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
using namespace std;
using std::pair;
// 옵션 체크

map<string, int> m;
void make_map(){
    m.insert(pair<string, int>("W", 1));    

}


struct op{
    int type;
    bool check;
    string keyword;
};

op option_check(vector<vector<string> > option, string keyword){
    int s= option.size();
    op ops;
    ops.type = m.at(option[0][0]);
    if(option[0][1]=="T"){
        ops.check = true;
    }else{
        ops.check = false;
    };
    ops.keyword=keyword;
    return ops;
}

// 완전 일치 하는거 찾기

vector<string> seek(vector<string> history, op p){
    int s = history.size();
    vector<string> ans;
    int* arr = new int[s];
    if(p.type == 1 && p.check==true){
        for(int i=0;i<s;i++){
            if(history[i].find(p.keyword)!=string::npos){
                arr[i]= 1;
            }else{
                arr[i]=0;
            }
        }
    }else if(p.type==1 && p.check==false){
        for(int i=0;i<s;i++){
            if (history[i].find(p.keyword) == string::npos)
            {
                arr[i] = 1;
            }
            else
            {
                arr[i] = 0;
            }
        }
    }
    for(int i=0;i<s;i++){
        if(arr[i]==1){
            ans.push_back(history[i]);
        };
    };
    return ans;
}


vector<string> solution(vector<string> history, vector<vector<string> > option, string keyword)
{

    op test;
    vector<string> v;
    make_map();
    test = option_check(option,keyword);
    v = seek(history,test);

    /*
        cout << "[";
        for(int i=0;i < v.size();i++){

            cout << v[i];
            if (i < v.size() - 1)
            {
                cout << ",";
            }
        };
        cout << "]" << endl;
    */

    vector<string> answer;
    answer=v;
    return answer;
};


int main(){
    vector<string> history;
    history.push_back("hello i am david");
    history.push_back("hello kail");
    history.push_back("hi tina");

    vector<vector<string> > option;
    vector<string> o;
    o.push_back("W");
    o.push_back("T");
    option.push_back(o);
    
    string keyword = "hello";

    solution(history,option,keyword);
    return 0;

}