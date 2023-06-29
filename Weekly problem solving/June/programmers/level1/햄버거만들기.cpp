#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient)
{
    int answer = 0;

    // 문자열로만들어주기
    string str;
    for (int i = 0; i < ingredient.size(); i++)
    {
        str += ingredient[i] + '0';
    };
    

    // 문자열에서 str.find / str.erase 사용해서 쓱 지우고 찾고 쓱 지우고 찾고
    int pos = 0;
    while (true)
    {
        size_t ret = str.find("1231", pos);
        if (ret == string::npos)
        {
            break;
        }
        else
        {
            str.erase(ret, 4);
        };
        if (ret > 2)
        {
            pos = ret - 3;
        };
        answer++;
    }

    return answer;
};

int main(){
    
}