//#include <iostream>

// 답변기다리기
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q; // 작은값부터 출력되게(상단에있게)

int main(){

    int n;
    vector<int> v;
    //cin >> n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp;
        //cin >> temp;
        scanf("%d",&temp);
        q.push(temp);
        priority_queue<int, vector<int>, greater<int> > sq;
        sq =q;
        if(i<=1){
            v.push_back(q.top());
        }else{
            if(q.size()>2 && q.size()%2==1){
                // q size 가 2보다 크면
                int p = q.size()/2;
                //priority_queue<int, vector<int>, greater<int> > sq;
                //sq= q;
                for(int i=0;i<p;i++){
                    sq.pop();
                };
                int mid;
                mid = sq.top();
                //cout << mid << endl;
                v.push_back(mid);
        
            }else if(q.size()>2 && q.size()%2==0){
                int p= q.size()/2-1;
                //priority_queue<int, vector<int>, greater<int> > sq;
                //sq = q;
                for (int i = 0; i < p; i++)
                {
                    sq.pop();
                };
                int mid;
                mid = sq.top();
                // cout << mid << endl;
                v.push_back(mid);
            }
        };
    };
        
    for(int i=0;i<v.size();i++){
        //cout << v[i] << "\n";
        printf("%d\n",v[i]);
    }
    return 0;

}