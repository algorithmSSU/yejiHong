#include <iostream>
#include <queue>
#include <stack>
#include<algorithm>
using namespace std;
using std::pair;

void conference(vector<pair<int, int>> s);
void conf(vector<pair<int, int>> s);
int main(){

    int N;
    priority_queue<pair<int, int>> pq;
    vector<pair<int, int>> s;
    stack<pair<int, int>> st;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        pq.push(make_pair(b, a)); // second,first 순서로 저장
    };


    for (int i = 0; i < N;i++){
        int front = pq.top().first;
        int second = pq.top().second;
        st.push(make_pair(front, second));
        //cout << pq.top().first << pq.top().second << endl;
        pq.pop();
    };

    for (int i = 0; i < N;i++)
    {
        int first = st.top().first;
        int second = st.top().second;
        s.push_back(make_pair(first, second));
        st.pop();
    };
    ;

    unique(s.begin(), s.end());
    sort(s.begin(), s.end());
/*
    cout << "=====vector====" << endl;
    // priority queue를 통해 오름차순으로 정렬된 stack
    
    for (int j = 0; j < N;j++){
        cout << s[j].first << s[j].second << endl;
    };

    cout << "====result====" << endl;

    */

    conf(s);
    //conference(s);
};

void conf(vector<pair<int,int>> s){
    int count;
    int temp;
    temp = 0; 
    for (int i = 0; i < s.size();i++){
        if(temp<=s[i].second){
            //cout << "temp: " << temp << endl;
            //cout << s[i].second << endl;
            temp = s[i].first;
            count++;
        }
    };
    cout << count << endl;
};