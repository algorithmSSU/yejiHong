#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices)
{
    string answer = "";
    sort(indices.begin(), indices.end());
    for (int i = 0; i < indices.size(); i++)
    {
        int temp = indices[i] - i;
        my_string.erase(my_string.begin() + temp);
    }

    answer += my_string;
    return answer;
}