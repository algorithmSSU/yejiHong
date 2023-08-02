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

    map<string, vector<pair<int, int>>>::iterator ptr;
    for (ptr = summary.begin(); ptr != summary.end();ptr++){
        for (int i = 0; i < ptr->second.size();i++){
            cout << ptr->first << ptr->second[i].first << " " << ptr->second[i].second << endl;
        }
    }

    return answer;
};
vector<string> geners = {"classic", "pop", "classic", "classic", "pop"};
vector<int> plays = {500, 600, 150, 800, 2500};

int main()
{
    vector<int> ans;

    ans = solution(geners, plays);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
};