#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int> key;

void make_key(vector<string> keymap)
{

    for (int i = 0; i < keymap.size(); i++)
    {
        for (int j = 0; j < keymap[i].length(); j++)
        {
            if (key.find(keymap[i][j]) == key.end())
            {
                key[keymap[i][j]] = j + 1;
            }
            else
            {
                if (key[keymap[i][j]] == j + 1)
                {
                    continue;
                }
                else
                {
                    key[keymap[i][j]] = key[keymap[i][j]] > j + 1 ? j + 1 : key[keymap[i][j]];
                }
            }
        }
    }
}

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;
    vector<int> temp_answer;
    make_key(keymap);

    int temp = 0;

    for (int i = 0; i < targets.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < targets[i].length(); j++)
        {
            if (key.find(targets[i][j]) != key.end())
            {
                temp += key[targets[i][j]];
            }
            else
            {
                flag = false;
                answer.emplace_back(-1);
                break;
            }
        };
        if (flag)
        {
            answer.emplace_back(temp);
        }

        temp = 0;
    };

    return answer;
}

int main(){


    

}