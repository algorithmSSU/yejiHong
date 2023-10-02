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
    int answer=0;

    queue< pair<int, int> > q;
    q.push(make_pair(n,answer));

    while(!q.empty()){
        int cur = q.front().first;// 수빈이가 있는 위치
        int answer = q.front().second; // 연산횟수
        q.pop(); 

        if(cur==k){
            return answer;
        };
        
        int a,b,c;
        a = cur-1; // 현재 위치에서 -1
        b = cur+1; // 현재 위치에서 +1
        c = cur*2; // 현재 위치에서 * 2
        
        // -1
        if(0<=a && visited[a]==0){
            visited[a]=1;
            q.push(make_pair(a,answer+1));
        };

        // +1
        if (b<= k && visited[b] == 0)
        {
            visited[b] = 1;
            q.push(make_pair(b, answer+1));
        };

        // *2
        if (c <= k + 1 && visited[c] == 0)
        {
            visited[c] = 1;
            q.push(make_pair(c, answer + 1));
        }

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

/*

1️⃣ 현재위치 -1
2️⃣ 현재위치 +1
3️⃣ 현재위치 *2

✅ 위 3가지 경우를 같은 수준(=연산 횟수)에서 카운팅해주어야함

- 빼기 1️⃣ : 0보다 큰 경우에 다시 그 수에서 세 가지 연산을 할 수 있도록 queue push
- 더하기 2️⃣ : 동생의 위치보다 작을 경우 다시 그 수에서 세 가지 연산을 할 수 있도록 queue push
- 곱하기 3️⃣ : 동생의 위치보다 작을 경우 다시 그 수에서 세 가지 연산을 할 수 있도록 queue push
(곱하기의 경우 동생의 위치 +1 을 해주어서 동생의 크기 보다 작은 수로 들어가, 다음 연산 때 더하기를 만나게)


*/