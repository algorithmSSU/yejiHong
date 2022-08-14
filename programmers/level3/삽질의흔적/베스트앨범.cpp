#include <iostream>
#include <string>
#include <map>
#include <vector>
using std::pair;
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<string, int> m;
    map<string, vector<pair<int, int>>> summary;
    string maximum = "";

    for (int i = 0; i < genres.size(); i++)
    {
        m[genres[i]] += plays[i];
        summary[genres[i]].push_back(make_pair(plays[i], i));
    };

    for (int j = 0; m.size(); j++)
    {
    }

    return answer;
};

int main()
{
}