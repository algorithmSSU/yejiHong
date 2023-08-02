#include <string>
#include <vector>
#include <math.h>
using namespace std;

int isodd(int num)
{
    if (num % 2 == 1)
    {
        return 1;
    }
    return 0;
};

int solution(int a, int b)
{
    int answer = 0;
    int check = 0;
    check += isodd(a);
    check += isodd(b);

    if (check == 2)
    {
        answer = pow(a, 2) + pow(b, 2);
    }
    else if (check == 1)
    {
        answer = 2 * (a + b);
    }
    else if (!check)
    {
        answer = abs(a - b);
    }

    return answer;
}