#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int answer =0;
    string input;
    string goal = "love";
    getline(cin, input, '\n');

    int idx = 0;
    int count = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == goal[idx])
        {
            count++;
            if (idx < goal.length() - 1)
            {
                idx++;
            }
            else
            {
                idx=0;
            }
        }
        else
        {
            if (idx <= 0)
            {
                idx = 0;
            }
            else if (idx > 0)
            {
                idx--;
                count--;
            }
        }
    }

    answer = count/goal.length();
    cout << answer << endl;

    return 0;
}