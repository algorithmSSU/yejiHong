// A->B->C->D->E <depth check>
// That is, the problem of checking whether a graph with depth 4 exists

#include <iostream>
#include <vector>

using namespace std;

vector<int> v[2000]; // The size of the vector each array element has
bool visited[2000];  // visit log
bool d;              // depth check

void dfs(int n, int depth);

int main()
{

    int N, M;
    int count;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < M; i++)
    {
        dfs(i, 0);

        if (d)
        { // depth check
            break;
        }
    }

    cout << d << endl;
};

void dfs(int n, int depth)
{

    if (depth == 4)
    {
        d = true;
        return;
    }

    visited[n] = true;

    for (int i = 0; i < v[n].size(); i++)
    {
        int p = v[n][i];
        if (visited[p])
        {
            continue;
        };
        if (!visited[p])
        {
            dfs(p, depth + 1);
        }
    };
    visited[n] = false;

    /*Since we need to check the depth at every vertex,
    we have to iterate through all the vectors in the array
    and then change the history of the array to false.*/
};

/**/
