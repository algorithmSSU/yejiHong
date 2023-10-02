#include <string>
#include <vector>

using namespace std;

string solution(string code)
{
    string answer = "";
    bool flag = false;

    for (int i = 0; i < code.length(); i++)
    {
        if (code[i] == '1')
        {
            if (flag == true)
            {
                flag = false;
            }
            else
            {
                flag = true;
            }
        };
        if (!flag && i % 2 == 0 && code[i] != '1')
        {
            answer += code[i];
        }
        else if (flag && i % 2 == 1 && code[i] != '1')
        {
            answer += code[i];
        }
    };

    if (answer == "")
    {
        answer = "EMPTY";
    }
    return answer;
}