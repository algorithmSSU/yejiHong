#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int pipe_count(string s);

int pipe_count(string s){
    stack<char> st;
    int count = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            st.push(s[i]);
        }else{
            st.pop();
            if(s[i-1]=='('){
                count+=st.size();
            }else{
                count++;};
        }
    }
    return count;
};


int main(){
    string str;
    cin >> str;

    cout<< pipe_count(str) << endl;
}


/*

가장 간단한 형태에서 정확한 규칙을 찾자

*/