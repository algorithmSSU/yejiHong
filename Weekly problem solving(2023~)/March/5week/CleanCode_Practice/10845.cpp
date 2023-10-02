#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define SIZE 1000

class que{
    public:
        que(){
            cursor = 0;
            header = 0;
        }
        void push(int n);
        int pop();
        int size();
        bool empty();
        int front();
        int back();

    private:
        int cursor;
        int header;
        int arr[SIZE];
};
void que::push(int n)
{
        if (cursor < SIZE)
        {
            arr[cursor] = n;
            cursor++;
        }
};

int que::pop()
{
        if (empty())
        {
            return -1;
        }
        else
        {
            int temp;
            temp = arr[header];
            header++;
            return temp;
        }
};

int que::size()
{
        return cursor - header;
};

bool que::empty()
{
        if (cursor == header)
        {
            return 1;
        }
        else
        {
            return 0;
        }
};
int que::front()
{
        if (empty())
        {
            return -1;
        }
        else
        {
            int temp;
            temp = arr[header];
            return temp;
        }
};

int que::back()
{
        if (empty())
        {
            return -1;
        }
        else
        {
            int temp;
            int now = cursor - 1;
            temp = arr[now];
            return temp;
        }
}

int main(){
    

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    vector<int> v;
    que q;

    for(int i=0; i<n; i++){
        string str;
        int m;
        cin >> str;
        if (str=="push"){
            cin >> m;
            q.push(m);
        }else if(str=="front"){
            cout << q.front()<< endl;
        }else if(str=="back"){
            cout << q.back() << endl;
        }else if(str=="size"){
            cout << q.size() << endl;
        }else if(str=="pop"){
            cout << q.pop() << endl;
        }else if(str=="empty"){
            cout << q.empty() << endl;
        }
    };
    return 0;
};


