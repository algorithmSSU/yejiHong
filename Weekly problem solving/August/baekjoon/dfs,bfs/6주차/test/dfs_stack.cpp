#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> vertexs[100];
bool visited[100];
int N;
void dfs(int n);

int main(){
    int N;
    cin >> N;
    int a, b;

    for (int i = 0; i < N;i++){
        cin >> a >> b;
        vertexs[a].push_back(b);
        vertexs[b].push_back(a);
    };

    for (int j = 1; j < N;j++){
        if(!visited[j]){
            dfs(j);
        }
    }
};

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
            if(!visited[temp]){
                cout << temp << " ";
                visited[temp] = true;
                stack.push(x);
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

/*
1 2 3 4 5 6
2 1 1 2 2 3
3 4 6
  5
stack : front ~ last


stack : 1
stack : pop()-> 1
1과 연결된 원소들 : 2, 3 (stack.push(2); stack.push(1); visited[2]=true; break)
cout << 2;


stack : 1 2
stack : pop()-> 2
2와 연결된 원소들 : 1, 4, 5 (stack.push(4); stack.push(2); visited[4]=true; break;)
cout << 4;


stack : 1 2 4
stack : pop()-> 4
4와 연결된 원소들 : 2 (visited[2]==true; 이미 방문함)

stack : 1 2
stack : pop()-> 2
2와 연결된 원소들 : 1, 4, 5 (stack.push(5); stack.push(2); visited[5]=true; break;)
cout << 5;

stack : 1 2
stack : pop()-> 2
2와 연결된 원소들 : 1, 4, 5 (visited[1,4,5]==true; 이미 방문함)

stack : 1
stack : pop()->1
1과 연결된 원소들 : 2, 3(2는 이미 방문함, stack.push(3); stack.push(1); visited[3]=true; break;)
cout << 3;

stack : 1 3
stack : pop()-> 3
3고 연결된 원소들 : 1, 7(1은 이미 방문함, stack.push(7); stack.push(3); visited[7]=true; break;)
cout << 7;






*/