#include <string>
#include <vector>

using namespace std;

string solution(string my_string)
{
    string answer = "";

    for (int i = 0; i < my_string.length(); i++)
    {
        if (my_string[i] < 97)
        {
            answer += my_string[i] + 32;
            // answer+=tolower(my_string[i]); // 모든 문자를 소문자로
        }
        else
        {
            answer += my_string[i] - 32;
            // answer+=toupper(my_string[i]); // 모든 문자를 대문자로
        }
    }
    return answer;
}