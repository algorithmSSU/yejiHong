#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> babbling)
{

    vector<string> baby = {"aya", "ye", "woo", "ma"};
    int answer = 0;
    
    bool check = false;
    for (int i = 0; i < babbling.size();i++)
    {
        string str = "";
        for (int j = 0; j < babbling[i].size(); j++)
        {
            str += babbling[i][j];
            auto it = find(baby.begin(), baby.end(), str);
            if (it != baby.end())
            {
                //std::cout << str << endl;
                str = "";
            }
        };
        if (str.empty())
        {
            answer++;
        }
    }
    return answer;
}

int main(){

    vector<string> input = { "ayaye",
                             "uuuma",
                             "ye",
                             "yemawoo",
                             "ayaa" };

    std::cout << solution(input) << endl;
}