#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string my_string)
{
    int answer = 0;

    int op = 0;
    string temp = "";
    int num = 0;
    for (int i = 0; i < my_string.length(); i++)
    {
        if (my_string[i] != ' ')
        {
            if (isdigit(my_string[i]))
            {
                temp += my_string[i];
            }
            else
            {
                if (my_string[i] == '+')
                {
                    op = 0;
                }
                else if (my_string[i] == '-')
                {
                    op = 1;
                }
            }
        }
        else if (my_string[i] == ' ')
        {
            if (!temp.empty())
            {
                if (op == 0)
                {
                    answer += stoi(temp);
                }
                else if (op == 1)
                {
                    answer -= stoi(temp);
                }
            };
            temp = "";
        }
    };

    if (!temp.empty())
    {
        if (op == 0)
        {
            answer += stoi(temp);
        }
        else if (op == 1)
        {
            answer -= stoi(temp);
        }
    };

    return answer;
};
