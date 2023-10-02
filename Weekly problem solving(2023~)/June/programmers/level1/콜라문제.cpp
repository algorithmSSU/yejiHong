#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n)
{

    int answer = 0;

    int give = 0;
    int receive = 0;
    while (n >= a)
    {
        int share = n / a;
        give = a * share;
        receive = b * share;
        n = n - give + receive;
        answer += receive;
    }

    return answer;
}