#include <string>
#include <vector>

using namespace std;

int solution(string t, string p)
{
    int answer = 0;
    int end = t.length() - p.length() + 1;

    long long p_int = stoull(p);
    int cnt = 0;
    for (int i = 0; i < end; i++)
    {
        string T = t.substr(i, p.length());
        long long t_int = stoull(T);
        if (p_int >= t_int)
        {
            cnt++;
        }
    }
    answer = cnt;
    return answer;
}