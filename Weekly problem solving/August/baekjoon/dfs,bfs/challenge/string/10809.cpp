#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
using namespace std;
using std::fill_n;

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                  'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

bool visited[26];

int main()
{
    int index[26];
    fill_n(index, 26, -1);

    string str;

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (str[i] == alpha[j] && !visited[j])
            {
                visited[j] = true;
                index[j] = i;
                break;
            }
        };
    };

    for (int i = 0; i < 26; i++)
    {
        if (index[i] == -1)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << index[i] << " ";
        }
    }
};

/*1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1*/