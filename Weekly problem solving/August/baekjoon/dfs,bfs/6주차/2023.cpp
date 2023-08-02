/*신기한 소수
수빈이가 세상에서 가장 좋아하는 것은 소수이고, 취미는 소수를 가지고 노는 것이다.
요즘 수빈이가 가장 관심있어 하는 소수는 7331이다.

7331은 소수인데, 신기하게도 733도 소수이고, 73도 소수이고, 7도 소수이다.
즉, 왼쪽부터 1자리, 2자리, 3자리, 4자리 수 모두 소수이다! 수빈이는 이런 숫자를 신기한 소수라고 이름 붙였다.

수빈이는 N자리의 숫자 중에서 어떤 수들이 신기한 소수인지 궁금해졌다. N이 주어졌을 때, 수빈이를 위해 N자리 신기한 소수를 모두 찾아보자.*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
vector<int> v;
vector<int>::iterator ptr;
queue<int> q;

void solution(int s, int n);
int sosu_check(int num);

int sosu[4] = {2, 3, 5, 7};
int hol[6] = {1, 2, 3, 5, 7, 9};

int main()
{

    int n;
    cin >> n;

    // solution(2, n);
    for (int i = 0; i < 4; i++)
    {
        solution(sosu[i], n);
    }
};

/*소수 판별*/
int sosu_check(int num) /*number 제곱근 사용*/
{
    int i;
    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
};

/*신기한 소수 출력*/
void solution(int s, int n)
{ // 2,3,5,7
    int p;
    int temp;
    int num;
    string str;
    int size;

    temp = s;
    q.push(temp);

    while (!q.empty())
    {
        int num = q.front();
        str = to_string(num);
        size = str.length();
        if (size == n)
        {
            break;
        }
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            temp = num * 10 + hol[i];
            if (sosu_check(temp) == 1)
            {
                // cout << "temp:" << temp << " " << endl;
                q.push(temp); // 23,29
            }
            else
            {
                continue;
            };
        };
    };

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    };
    /* // 디버깅용
    for (ptr = v.begin(); ptr < v.end();ptr++){
        cout << *ptr << endl;
    }
    */
}