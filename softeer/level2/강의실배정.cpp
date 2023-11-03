#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


int N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int answer = 0;

    vector<pair<int,int>> lecture;
    stack<pair<int,int>> stack;
    cin >> N;

    for(int i=0;i<N;i++){
        int open,close;
        cin >> open >> close;
        lecture.emplace_back(close,open);
    }

    sort(lecture.begin(),lecture.end());

    stack.push(lecture[0]);

    for(int i=1;i<lecture.size();i++){
        if(stack.top().first > lecture[i].second){
            continue;
        }else if(stack.top().first <= lecture[i].second){
            stack.push(lecture[i]);
        }
    }

    cout << stack.size() << endl;


}