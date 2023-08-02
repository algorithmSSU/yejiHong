#include <iostream>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    priority_queue<int> pq;
    vector<int> ans;

    std::cin >> n;

    for(int i=0;i<n;i++){
       int num;
       std::cin >> num;
       pq.push(num);

       stack<int> temp;

       int pqlen = pq.size();
       int mid = pqlen/2;
       int midr = pqlen/2+1;
       if(pqlen>=2 && pqlen%2==0){
        while(midr--){
            temp.push(pq.top());
            pq.pop();
        };
        int tp = temp.top();
        temp.pop();
        if(tp<temp.top()){
            ans.push_back(tp);
        }else{
            ans.push_back(temp.top());
        }
        while(!temp.empty()){
            pq.push(temp.top());
            temp.pop();
        }
       }
       else if (pqlen % 2 == 1)
       {
        while(mid--){
            temp.push(pq.top());
            pq.pop();
        };
        ans.push_back(temp.top());
        while (!temp.empty())
        {
            pq.push(temp.top());
            temp.pop();
        }
       }
    };

    for(int i=0;i<ans.size();i++){
        std::cout << ans[i] << endl;
    };





}