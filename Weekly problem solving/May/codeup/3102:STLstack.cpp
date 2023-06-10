#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
using std::stoi;


class st{
public:
    st(){
        arr = new int[201];
        cursor=-1;
    }
    void push(int num){
        if(cursor < 201){
            cursor++;
            arr[cursor] = num;
        }
    }
    int top(){
        if(empty()){
            return -1;
        }else{
            return arr[cursor];
        }
        
    };

    void pop(){
        if(!empty()){
            cursor--;
        }else{
            cursor = -1;
        }
    }

    bool empty(){
        if(cursor==-1){
            return true;
        }else{
            return false;
        }

    }
    int size(){
        if(!empty()){
            return cursor + 1;
        }else{
            return 0;
        }
        
    }
    
private:
    int cursor;
    int*arr;

};


int main(){
    st stack;
    vector<int> answer;
    int n;
    cin >> n;

    while(n--){
        string input;
        cin >> input;
        if(input=="push("){
            int num;
            char x;
            cin >> num;
            cin >> x;
            stack.push(num);
            
        }else if(input=="top()"){
            //cout << stack.top() << endl;
            answer.emplace_back(stack.top());

        }else if(input=="pop()"){
            stack.pop();

        }else if(input=="size()"){
            //cout << stack.size() << endl;
            answer.emplace_back(stack.size());

        }else if(input=="empty()"){
            int check = stack.empty();

            if(check==1){
                answer.emplace_back(-5);
            }else if(check==0){
                answer.emplace_back(-4);
            }

        }
    }

    for(int i=0;i<answer.size();i++){
        if(answer[i]==-5){
            cout << "true" << endl;
        }else if(answer[i]==-4){
            cout << "false" << endl;
        }else{
            cout << answer[i] << endl;
        }
    }


}