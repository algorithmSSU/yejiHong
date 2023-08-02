#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    int n;
    int answer = 0;
    cin >> n;

    vector<string> number;
    map<char, int> dict;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        number.emplace_back(input);
    };
    for (int i = 0; i < number.size(); i++)
    {
        for (int j = 0; j < number[i][j]; j++)
        {
            int w = number[i].size() - 1 - j;
            dict[number[i][j]] += pow(10, w);
        }
    };

    vector<pair<int, char> > final;

    map<char, int>::iterator p;
    for (p = dict.begin(); p != dict.end(); p++)
    {
        final.emplace_back(p->second, p->first);
    }
    sort(final.begin(), final.end());
    reverse(final.begin(), final.end());

    int start = 9;
    for (int i = 0; i < final.size(); i++)
    {
        answer += final[i].first * start;
        start--;
    };

    cout << answer << endl;
}