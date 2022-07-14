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
        pq.push(make_pair(a, b));
    };


    for (int i = 0; i < N;i++){
        int front = pq.top().first;
        int second = pq.top().second;
        st.push(make_pair(front, second));
        cout << pq.top().first << pq.top().second << endl;
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

    cout << "=====vector====" << endl;
    // priority queue를 통해 오름차순으로 정렬된 stack
    
    for (int j = 0; j < N;j++){
        cout << s[j].first << s[j].second << endl;
    };

    cout << "====process====" << endl;

    conf(s);
    //conference(s);
};

void conference(vector<pair<int, int>> v)
{
    int size = v.size();
    int start = 0;
    int index = 0;
    int min_value = 24;
    int count = 1;

    while(1){

        if(start == v.size()-1){
            break;
        };
        for (int i = start; i < v.size();i++){
            int temp = v[i].second;
            if(min_value>temp){
                min_value = temp;
                index = i;
            };
            if(min_value==temp){
                continue;
                count++;
            }
        };
        for (int j = start; j <size;j++){
            int temp = v[j].first;
            if(min_value<temp){
                //cout << j << endl;
                start = j;
                count++;
                break;
            }else if(min_value>temp && j==size-1){
            
                //continue;
                start = 0;
                v.erase(v.begin() + index);
            }
        };
        min_value = 24;
    };
    cout << count;

    //cout << "min_value: "<< min_value << endl;

};

void conf(vector<pair<int,int>> s){
    int count;
    int temp;
    temp = s[0].second;
    for (int i = 0; i < s.size();i++){
        if(temp<=s[i].second){
            temp = s[i].first;
            count++;
        }
    };
    cout << count << endl;
};