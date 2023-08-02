#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int start);
bool visited[10];
vector<int> a[10];

int main()
{

    int count = 0;

    a[0].push_back(1);

    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);

    a[3].push_back(7);
    a[7].push_back(3);

    for (int i = 0; i < 7; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(i);
        }
    }

    cout << "connection: " << count << endl;
};

void dfs(int start)
{

    visited[start] = true;
    cout << start << endl;

    for (int j = 0; j < a[start].size(); j++)
    {
        int x = a[start][j];
        if (!visited[x])
        {
            // cout << x << endl;
            dfs(x);
        }
    }
};