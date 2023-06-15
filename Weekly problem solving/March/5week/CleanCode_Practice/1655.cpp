#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q; // 작은값부터 출력되게(상단에있게)
priority_queue<int,vector<int>,greater<int> > sq;
priority_queue<int,vector<int>,greater<int> > bq;
priority_queue<int,vector<int>,less<int> > bsq;

int main(){

    int n;
    cin >> n;
    vector<int> ans;
    for(int i=0;i<n;i++){
        int temp;
        int m;
        cin >> temp;
        if(q.empty()){
            q.push(temp);
        }else{
            if(q.top()<temp){
                bq.push(temp);
            }else{
                q.push(temp);
            }
        };
        int len = q.size()+bq.size();

        if(len==1){
            m = 0;
        }else{
            m = len / 2 - 1;
        }
        cout << "m:"<< m << endl;
        int qsize, bqsize = 0;
        qsize = q.size(); bqsize = bq.size();
        if(qsize==bqsize){
            for(int i=0;i<m;i++){
                q.push(q.top());
                q.pop();
            }
            ans.push_back(q.top());
            q.push(q.top());
            q.pop();
        }else if(qsize<bqsize){
            for(int i=0;i<m;i++){
                bq.push(bq.top());
                bq.pop();
            }
            ans.push_back(bq.top());
            bq.push(bq.top());
            bq.pop();
        }else if(qsize>bqsize){
            for (int i = 0; i < m; i++)
            {
                q.push(q.top());
                q.pop();
            }
            ans.push_back(q.top());
            q.push(q.top());
            q.pop();
        }
    };


    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }

    

}

//마지막거 ㅏ하나만 이상