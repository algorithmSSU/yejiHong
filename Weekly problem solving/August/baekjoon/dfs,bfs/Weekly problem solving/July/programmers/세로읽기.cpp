#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c)
{
    string answer = "";

    //vector<vector<char> > v;
    char v[1024][1024];

    int y = 0;
    int x = 0;
    for (int i = 0; i < my_string.length(); i++)
    {
        if (x != 0 && x % m == 0)
        {
            y++;
            x = 0;
        };
        v[y][x] = my_string[i];
        x++;
    };

    int idx = my_string.length() / m;

    for (int i = 0; i < idx; i++)
    {
        answer += v[i][c-1];
    }
    return answer;
}

int main(){
    string str = "ihrhbakrfpndopljhygc";
    int m = 4;
    int c = 2;
    string ans;
    ans = solution(str,m,c);
    cout << ans << endl;
}