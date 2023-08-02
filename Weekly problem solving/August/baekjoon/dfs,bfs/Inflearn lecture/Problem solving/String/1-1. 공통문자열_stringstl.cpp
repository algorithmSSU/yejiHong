#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    int n;
    vector<string> v;
    cin >> n;

    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        v.push_back(temp);
    }

    string res = v[0]; // 맨 앞에꺼 담아서
    for(int i=1;i<v.size();i++){
        while(v[i].find(res)!=0)// 접두사! 니까 찾으려는 문자가 인덱스 0에 위치해야함.
        {
            res = res.substr(0,res.size()-1);
            // 0부터 맨 앞 문자의 크기를 1씩 감소시킨 문자가 있는 지 비교
            };    
    };
    cout << res << endl;
    return 0;
}