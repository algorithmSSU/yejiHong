#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<char> tochar(vector<string> dic)
{
    vector<char> v;
    for (int i = 0; i < dic.size(); i++)
    {
        for (int j = 0; j < dic[i].size(); j++)
        {
            v.emplace_back(dic[i][j]);
        }
    }

    return v;
}

bool check(vector<char> v, string str)
{
    bool rt = true;
    map<char, int> m;
    map<char, int>::iterator p;
    int cnt = 0;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            if (v[i] == str[j])
            {
                m[v[i]]++;
            }
        }
    }

    if (m.size() == v.size())
    {
        for (p = m.begin(); p != m.end(); p++)
        {
            if (p->second != 1)
            {
                rt = false;
            }
        }
    }
    else
    {
        rt = false;
    }

    return rt;
}

int solution(vector<string> spell, vector<string> dic)
{
    int answer = 0;
    bool ch = false;
    vector<char> d = tochar(spell);

    for (int i = 0; i < dic.size(); i++)
    {
        bool temp = false;
        temp = check(d, dic[i]);
        if (temp)
        {
            ch = true;
        }
    }

    if (ch)
    {
        answer = 1;
    }
    else
    {
        answer = 2;
    }

    return answer;
}