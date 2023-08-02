#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using std::stoi;
using namespace std;

int solution(string s)
{
    int answer = 0;
    string strnum = "";
    string str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    map<string, char> m;

    for (int i = 0; i < 10; i++)
    {
        m[str[i]] = i + '0';
    };

    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        temp+=s[i];
        auto it = m.find(temp);
        if(it!=m.end()){
            strnum+=it->second;
            temp="";
        }else{
            if(s[i]-'0'<=9){
                strnum += s[i];
                temp="";
            }
        }
    };
    answer = stoi(strnum);

    return answer;
};


int main(){
    int ans;
    string s = "one4seveneight";
    ans = solution(s);
    cout << ans << endl;
}