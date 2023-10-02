#include <iostream>
#include <vector>
#include <string>

using namespace std;
using std::stoi;

struct stack
{

    int arr[10000];
    int last;

    void init()
    {
        last = -1;
    }
    void push(int data)
    {
        arr[++last] = data;
    }
    bool empty()
    {
        return (last < 0);
    }
    int pop()
    {
        if (empty())
        {
            return -1;
        }
        return arr[last--];
    }
    int size()
    {
        return last + 1;
    }
    int top()
    {
        if (empty())
        {
            return -1;
        }
        return arr[last];
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;


    stack s;
    s.init();
    vector<int> v;
    
    for(int i=0;i<n;i++){
        string str;
        int num;
        cin >> str;
        if(str=="push"){
            cin >> num;
            s.push(num);
        }
        if(str=="pop"){
            v.push_back(s.pop());
            //cout << s.pop() << endl;
        }
        if(str=="size"){
            v.push_back(s.size());
            //cout << s.size() << endl;
        }
        if(str=="empty"){
            v.push_back(s.empty());
            //cout << s.empty() << endl;
        }
        if(str=="top"){
            v.push_back(s.top());
            //cout << s.top() << endl;
        }
    }


    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }



    return 0;


}