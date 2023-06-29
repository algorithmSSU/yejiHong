#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(string my_string)
{
    string answer = "";

    map<char, int> dict;

    for (int i = 0; i < my_string.length(); i++)
    {
        if (dict.find(my_string[i]) == dict.end())
        {
            dict[my_string[i]]++;
            answer += my_string[i];
        }
        else
        {
            continue;
        }
    }

    return answer;
}