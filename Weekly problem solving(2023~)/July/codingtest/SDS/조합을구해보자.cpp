#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s = "123";
    int len = s.size();

    vector<string> answer;

    for (int i = 1; i <= len; i++)
    {
        vector<bool> v(len - i, false);
        v.insert(v.end(), i,true); // 맨 끝에 삽입
        cout << "=============== " << i << "개 ===============\n";
        do
        {
            string temp = "";
            for (int k = 0; k < len; k++)
            {
                if (v[k])
                    temp += s[k];
                    //cout <<"k:"<< s[k] << endl;
            }
            //cout << temp << "\n";
            answer.emplace_back(temp);
        } while (next_permutation(v.begin(), v.end()));
        cout << "===================================\n";
    }

    vector<string>::iterator it;

    for (it = answer.begin(); it != answer.end(); it++)
    {
        cout<< *it << endl;
    }

    return 0;
}
