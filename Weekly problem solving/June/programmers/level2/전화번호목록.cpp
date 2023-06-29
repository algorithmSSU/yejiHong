#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    map<string, int> checknum;

    for (int i = 0; i < phone_book.size(); i++)
    {
        checknum[phone_book[i]] = 1;
    };

    for (int i = 0; i < phone_book.size(); i++)
    {
        string text = "";
        for (int j = 0; j < phone_book[i].length(); j++)
        {
            text += phone_book[i][j];
            if (checknum[text] && text != phone_book[i])
            {
                answer = false;
            }
        }
    }

    return answer;
}