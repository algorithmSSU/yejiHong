#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db)
{
    string answer = "";

    bool idflag = false;

    for (int i = 0; i < db.size(); i++)
    {
        bool idcheck = false;
        answer = "fail";
        for (int j = 0; j < db[i].size(); j++)
        {
            if (j == 0)
            {
                if (id_pw[j] == db[i][j])
                {
                    idcheck = true;
                }
                else
                {
                    break;
                }
            }
            else if (j == 1)
            {
                if (id_pw[j] == db[i][j])
                {
                    if (idcheck)
                    {
                        answer = "login";
                        return answer;
                    }
                }
                else if (id_pw[j] != db[i][j])
                {
                    if (idcheck)
                    {
                        answer = "wrong pw";
                        return answer;
                    }
                }
            }
        }
    }

    return answer;
}