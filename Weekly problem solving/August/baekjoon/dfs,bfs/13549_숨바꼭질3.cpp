#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long int n,k;
long long int Time = 0;
long long int answer = 1e9;
bool visited[1000001]={false,};

void bfs(int now,int target){
    
    deque<pair<long long int,long long int> > q;
    q.push_back(make_pair(now, Time));

    while(!q.empty()){
        long long int pos = q.front().first;
        long long int t = q.front().second;
        q.pop_front();
        visited[pos]=true;


        if(pos==target){
            answer = answer > t ? t : answer;
        }

        long long int n1 = pos-1;
        long long int n2 = pos + 1;
        long long int n3 = pos*2;


        if(n3>=0 && !visited[n3] && n3<=100001){
            visited[n3]=true;
            q.push_front(make_pair(n3, t));
        };
        if (!visited[n1] && n1 >= 0)
        {
            visited[n1] = true;
            q.push_back(make_pair(n1, t + 1));
        }
        if(!visited[n2] && n2<=target){
            visited[n2] = true;
            q.push_back(make_pair(n2, t + 1));
        };
        
        

    }

}


int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    bfs(n, k);

    cout << answer << '\n';
}