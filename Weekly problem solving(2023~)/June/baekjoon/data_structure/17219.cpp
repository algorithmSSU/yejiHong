//map structure

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{

    vector<string> ans;
    map<string, string> m;
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int line, search;
    cin >> line >> search;

    while (line--)
    {
        string input;
        string password;
        cin >> input >> password;
        m[input] = password;
    };

    while (search--)
    {
        string input;
        string value;
        cin >> input;
        value = m[input];
        ans.emplace_back(value);
    };

    for (auto i : ans)
    {
        cout << i << endl;
    }
}