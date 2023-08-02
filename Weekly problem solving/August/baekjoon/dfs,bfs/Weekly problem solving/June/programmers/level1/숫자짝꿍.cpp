#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;



bool comapare(int a, int b){
    if(a<b){
        return b;
    };
    return a;
}

string solution(string X, string Y)
{
    string answer = "";
    vector<int> num;
    map<char, int> m1;
    map<char, int> m2;

    for (int i = 0; i < X.length(); i++)
    {
        m1[X[i]]++;
    };
    for (int i = 0; i < Y.length(); i++)
    {
        m2[Y[i]]++;
    };

    map<char, int>::iterator p1;
    map<char, int>::iterator p2;


    for(int i=9;i>=0;i--){
        int num = min(m1[i+'0'],m2[i+'0']);
        for(int j=0;j<num;j++){
            answer+= i+'0';
        }
    };

    if(answer=="")
        return "-1";
    else if(answer[0]=='0')
        return "0";
    else
        return answer;
};


int main(){

    string X = "100";
    string Y = "2345";
    string ans = "";
    ans = solution(X,Y);

    cout << ans << endl;

    
}