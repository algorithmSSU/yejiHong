#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <set>
#include <algorithm>
#include <map>
using std::stoi;
using namespace std;

int solution(string numbers);
void dfs();
bool isdecimal(int num);

vector<string> numlist;
vector<string> new_numbers;
vector<string> list;
queue<string> make_decimal;
set<int> set_num;

int main()
{
    string text;
    cin >> text;
    cout << solution(text) << endl;
    return 0;
};

int solution(string numbers)
{
    int answer = 0;
    map<int, int> m;

    for (int i = 0; i < numbers.length(); i++)
    {
        string temp;
        int ntemp;
        ntemp = numbers[i] - '0';
        temp = to_string(ntemp);
        make_decimal.push(temp);
        numlist.push_back(temp);
    };

    // sort(numlist.begin(), numlist.end());

    do {
        string s = "";
        for (int i = 0; i < numlist.size(); i++)
        {
            s += numlist[i];
            cout << s << endl;
            if (isdecimal(stoi(s))){
                m[stoi(s)]++;
            }
                
            
        }
    } while (next_permutation(numlist.begin(), numlist.end()));

    answer = m.size();
    return answer;
};

bool isdecimal(int num)
{
    if (num < 2)
    {
        return false;
    }
    int a = (int)sqrt(num);
    for (int i = 2; i <= a; i++)
    {
        if (num % i == 0)
        {
            return false;
        };
    };
    return true;
};