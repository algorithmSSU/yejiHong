#include <string>
#include <regex>
#include <iostream>

using namespace std;

int main()
{

    string str1 = "- and backend and senior and - 150";

    // 공백+- 와 and를 제거
    str1 = regex_replace(str1, regex("[ -]+"), "");
    str1 = regex_replace(str1, regex("and"), "");

    cout << str1 << endl; // aaabbb
    return 0;
}