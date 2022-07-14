#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using std::stoi;

/*

문자열 중에 - 가 있으면
마이너스를 만나기 전, 후 숫자들을 분리해서
before = 마이너스를 만나기 전 숫자들의 합
after = 마이너스 이후의 숫자들의 합

before - after = 정답

*/

void min(string text);

int main()
{

    string text;
    cin >> text;
    min(text);
}

void min(string text)
{
    string str;
    stack<int> number;
    queue<char> mix;

    int result;

    for (int i = 0; i < text.length(); i++)
    {
        mix.push(text[i]);
    };

    while (!mix.empty())
    {
        char temp;
        temp = mix.front();
        mix.pop();

        // str += temp;

        if (temp != '+' || temp != '-')
        {
            str += temp;
        }

        if (temp == '+')
        {
            int num = stoi(str);
            number.push(num);
            number.push(0);
            str = "";
        };

        if (temp == '-')
        {
            int num = stoi(str);
            number.push(num);
            number.push(-1);
            str = "";
        };

        if (mix.size() == 0)
        {
            int num = stoi(str);
            number.push(num);
            str = "";
        }
    };

    while (!number.empty())
    {
        int cur = number.top();
        number.pop();
        if (cur == -1)
        {
            result = result * -1;
        }
        else
        {
            result += cur;
            // cout <<"result: " << result << endl;
        }
    };

    cout << result << endl;
};

/*


제출 시 오류가 나는데 왜 나는지 이해가 안감




*/