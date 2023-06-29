#include <string>
#include <vector>

using namespace std;

int solution(string A, string B)
{
    int answer = -1;
    // 끝에만 비교해주고 이동한 거리만큼 다른 거에도 적용 -> b와 다르면 -1

    int start = A.length() - 1;
    int until = start * 2 + 1;
    int count = 0;

    if (A == B)
    {
        return 0;
    }
    for (int i = start; i >= 0; i--)
    {
        count++;
        string text = "";
        text += A[i];
        for (int j = i + 1; j < until; j++)
        {
            if (j >= A.length())
            {
                int temp = 0;
                temp = j - A.length();
                text += A[temp];
            }
            else
            {
                text += A[j];
            }
        };
        until--;
        if (text == B)
        {
            answer = count;
            return answer;
        };
    }

    return answer;
}