#include <iostream>

using namespace std;
#define MAX 1000
class stack
{
public:
    stack(){
        arr = new int[MAX];
        cur = 0;
    }
    int pop();
    int top();
    void push(int num);
    bool isempty();

private:
    int *arr;
    int cur;
};


void stack::push(int num){
    if(isempty()){
        arr[0] = num;
    }else{
        arr[cur] = num;
        cur++;
    };
};

int stack::pop(){
    if(isempty()){
        return -1;
    }else{
        return arr[cur];
        cur--;
    }

};

int stack::top(){
    if(isempty()){
        return -1;
    }else{
        return arr[cur];
    };
};

bool stack::isempty(){
    if(cur<=0){
        return true;
    };
    return false;
};

int main()
{

    stack s;

    int n;
    cin >> n;
}