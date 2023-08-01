#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;
int click=0;

void bfs(int start,int target){
    queue<pair<int,int> > q;
    
    q.push(make_pair(start,0));

    while(!q.empty()){
        int next = q.front().first;
        int cost = q.front().second;
        q.pop();

        if (next >= G || next < 0)
        {
            click = cost;
            return;
        }

        if(next<=G){
            q.push(make_pair(next+U,++cost));
            q.push(make_pair(next-D,++cost));   
        }
    }

}


int main(){

    cin >> F >> S >> G >> U >> D;
    int ans = 0;

    cout << click << '\n';

    

    
    
}