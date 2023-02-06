// 5 10 9 18 17

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;


int n,k;
int visited[100001] = {0,};
int solution(int n){
    int answer;

    vector<int> v;
    int temp=0;


    if(n==k){
        answer=0;
        return answer;
    }else if(k%2==0){
        temp = k/2;
        answer=0;
    }else{
        temp = (k/2)+1;
        answer=2;
    }

    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        answer++;

        if(temp==cur){
            return answer;
        };
        
        
        vector<int> comp;
        
        int a,b,c;
        a = cur-1;
        b = cur+1;
        c = cur*2;
        comp.push_back(a);
        comp.push_back(b);
        comp.push_back(c);
        
        
        vector<int> m;
        for(int i=0;i<comp.size();i++){
            int x;
            if(temp==comp[i]){
                return answer;
            }
            if(temp<comp[i]){
                x = comp[i]-temp;
            }else{
                x= temp-comp[i];
            }
            m.push_back(x);  
        };
        
        
        int index = min_element(m.begin(),m.end())-m.begin();
        
        q.push(comp[index]);
    };

    return answer;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    int answer;

    answer = solution(n);
    cout << answer<< endl;

}