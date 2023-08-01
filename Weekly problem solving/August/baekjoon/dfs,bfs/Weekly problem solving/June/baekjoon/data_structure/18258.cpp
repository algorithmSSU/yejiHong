// 왜 런탐 에러??
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

class Que{
    public:
        Que(){
            front_pointer = 0;
            pointer = -1;
        }
        void push(int n){
            pointer++;
            v.push_back(n);
        };

        int pop(){
            if(front_pointer>pointer){
                return -1;
            }
            return v[front_pointer++];
        };
        int size(){
            int temp = pointer - front_pointer;
            if(temp<0){
                temp = 0;
            }else if(temp==0){
                temp =1;
            }else{
                temp+=1;
            }
            
            return temp;

        };
        bool empty(){
            if(pointer==-1 || pointer<front_pointer){
                return true;
            }else{
                return false;
            }
        };
        int front(){
            if(front_pointer > pointer){
                return -1;
            }else{
                return v[front_pointer];
            }
        };
        int back(){
            if (front_pointer > pointer){
                return -1;
            }else{
                return v[pointer];
            }
        };
    private:
        vector<int> v;
        int front_pointer;
        int pointer;
};


int main(){
    Que queue;
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    vector<int> answer;
    cin >> n;
    stack<int> s;
    s.push(1);

    while(n--){
        string input;
        string number;
        int num;
        cin >> input;
        if(input=="push"){
            cin >> num;
            queue.push(num);
        }else if(input=="front"){
            answer.emplace_back(queue.front());

        }else if(input=="back"){
            answer.emplace_back(queue.back());
        }else if(input=="size"){
            answer.emplace_back(queue.size());
        }else if(input=="empty"){
            answer.emplace_back(queue.empty());
        }else if(input=="pop"){
            answer.emplace_back(queue.pop());
        }
    };
    

    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    };

    return 0;

}