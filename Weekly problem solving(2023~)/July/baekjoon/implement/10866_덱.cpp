#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e5;

class Deque
{
private:
    int data[MAX];
    int index_front;
    int index_back;
public:
    Deque();
    bool empty();
    void push_front(int x);
    void push_back(int x);
    void pop_front();
    void pop_back();
    int front();
    int back();
    int size();
};

Deque::Deque()
{
    index_front = 0;
    index_back = 0;
}

bool Deque::empty()
{
    return index_front == index_back;
}

void Deque::push_front(int x)
{
    data[index_front] = x;
    index_front = (index_front - 1 + MAX) % MAX;
}

void Deque::push_back(int x)
{
    index_back = (index_back + 1) % MAX;
    data[index_back] = x;
}

void Deque::pop_front()
{
    index_front = (index_front + 1) % MAX;
}

void Deque::pop_back()
{
    index_back = (index_back - 1 + MAX) % MAX;
}

int Deque::front()
{
    return data[(index_front + 1) % MAX];
}

int Deque::back()
{
    return data[index_back];
}

int Deque::size()
{
    return (index_back - index_front + MAX) % MAX;
}

int main()
{
    Deque dq;
    vector<int> answer;

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        string input;
        cin >> input;
        if (input == "push_front"){
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if (input == "push_back"){
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if (input == "pop_front"){
            if(dq.empty()){
                answer.emplace_back(-1);
            }else{
                answer.emplace_back(dq.front());
                dq.pop_front();
            }
        }else if(input == "pop_back"){
            if(dq.empty()){
                answer.emplace_back(-1);
            }else{
                answer.emplace_back(dq.back());
                dq.pop_back();
            }
        }else if (input == "size"){
            answer.emplace_back(dq.size());
        }else if (input == "empty"){
            answer.emplace_back(dq.empty());
        }else if(input =="front"){
            if(dq.empty()){
                answer.emplace_back(-1);
            }else{
                answer.emplace_back(dq.front());
            }
        }else if(input =="back"){
            if(dq.empty()){
                answer.emplace_back(-1);
            }else{
                answer.emplace_back(dq.back());
            }
        }
    };

    for(int i=0;i<answer.size();i++){
        cout << answer[i] << endl;
    }

    
    return 0;
}