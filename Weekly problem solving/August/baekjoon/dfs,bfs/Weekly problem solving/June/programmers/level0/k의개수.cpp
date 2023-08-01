#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int i, int j, int k)
{
    int answer = 0;

    char K = k + '0';
    for (int s = i; s <= j; s++)
    {
        string text = "";
        char ch;
        int idx = 0;
        if (s == k)
        {
            answer++;
        }
        else
        {
            text += to_string(s);
            answer += count(text.begin(), text.end(), K);
        }
    };

    return answer;
}