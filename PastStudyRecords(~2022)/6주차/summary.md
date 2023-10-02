# 7. BFS, DFS

# BFS

BFS 는 너비우선탐색으로, 연결된 요소들을 하나씩 모두 방문 한 뒤, 연결된 요소의 연결 요소를 차례대로 모두 방문하는 방식

## QUEUE 자료 구조 이용

FIFO

: 정점에 연결된 가까운 연결요소들부터 방문

```cpp
#include <iostream>
#include <vector>
#include <qeueu>

using namespace std;
vector<int> v[1000];
bool visited[1000];

void dfs(int start){
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while(!q.empty()){ // queue에 원소가 있을 때 계속 반복
		int index= q.front();
		q.pop() // 맨 앞 요소 삭제
		cout << index << " ";
		
		for (int i=0; i< v[index].size(); i++){
			int element = v[index][i];
			if(!visited[element]){
				q.push(element);
			}else{
				continue;
		}
	}
```

# DFS

DFS 는 깊이우선탐색으로, 정점과 연결된 연결요소 하나하나를 끝까지 파고드는 방식

## STACK 자료 구조 이용

FILO

: 현재 정점에서 갈 수 있는 점들까지 탐색

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> v[1000];
bool visited[1000];

void dfs(int n){
    int x;
    visited[n] = true;
    cout << n << " ";

    stack<int> stack;
    stack.push(n);

    while(!stack.empty()){
        x = stack.top();
        stack.pop();
        for (int i = 0; i < vertexs[x].size();i++){
            int temp;
            temp = vertexs[x][i];
            if(!visited[temp]){ // 연결요소 중 방문하지 않았다면, 해당 연결요소부터 다시
                cout << temp << " ";
                visited[temp] = true;
                stack.push(x);// 아직 방문하지 않은 연결요소가 있을 수도 있기 때문
                stack.push(temp);
                break;
            }
            else
            {
                continue;
            };
        };
    }
}
```

## 재귀 이용

: 해당 정점부터 다시 탐색을 시작하는 방식으로 진행

```cpp
#include <iostream>
#include <vector>

using namespace std;
vector<int> v[1000];
bool visited[1000];

void dfs(int start)
{

    visited[start] = true;// 방문한 지점 체크
    cout << start << endl;

    for (int j = 0; j < a[start].size(); j++)
    {
        int x = a[start][j];
        if (!visited[x]) // 방문하지 않았다면, 체크 후, 다시 그 지점부터 방문
        {
            dfs(x);
        }
    }
};
```

---

# vector container

vector는 동적으로 배열처럼 생성해줄 수 있는 컨테이너이다.

vector<int> a;

a.push_back(1);

a.push_back(2);

a.push_back(3);

→ a= {1,2,3}

### **배열**

vector<int> a[10];

10개의 원소를 가지는 배열인데, 그 배열이 담을 수 있는 데이터 타입이 vector<int> 라는 것.

a[1].push_back(1);

a[1].push_back(2);

→ a 배열의 1번째 인덱스 위치에 1을 삽입

→ a 배열의 1번째 인덱스 위치에 2을 삽입

→ a[1] = {1,2}

### **pair**

#include <pair>

vector<pair<int,int>> coordinate;

int 타입을 쌍으로, 좌표처럼 두 개의 int 타입을 한쌍으로 취급해서 원소로 가질 수 있는 것

생성 시

coordinate(**make_pair**(int x, int y));

이런식으로 만들면 된다.