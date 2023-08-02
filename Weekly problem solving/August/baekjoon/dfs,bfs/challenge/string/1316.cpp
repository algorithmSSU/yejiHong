#include <iostream>
#include <vector>
#include <string>

using namespace std;
int count;

int checker(string text);
int main()
{

    int n;
    vector<string> v;
    int count = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        v.push_back(temp);
    };

    for (int i = 0; i < n; i++)
    {
        count += checker(v[i]);
    };

    cout << count << endl;
};

int checker(string text)
{
    vector<char> a;

    char start = text[0];
    a.push_back(start);

    for (int i = 1; i < text.length(); i++)
    {
        char cur = text[i];
        if (start == cur)
        {
            continue;
        }
        else
        {
            for (int i = 0; i < a.size(); i++)
            {
                if (cur == a[i])
                {
                    // cout << text << endl;
                    return 0;
                };
            };
            start = cur;
            a.push_back(cur);
        };
    };

    return 1;
};