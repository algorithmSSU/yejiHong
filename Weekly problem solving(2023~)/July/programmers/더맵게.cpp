#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> sc, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < sc.size(); i++)
    {
        pq.push(sc[i]);
    };
    bool ch = false;
    while (1)
    {
        if (!pq.empty() && pq.top() >= K)
        {
            break;
        };
        if (pq.size() < 2 || pq.empty())
        {
            ch = true;
            break;
        }
        int a = pq.top();
        pq.pop();
        int made = a + pq.top() * 2;
        pq.pop();
        pq.push(made);
        answer++;
    };

    if (ch)
    {
        answer = -1;
    }

    return answer;
}