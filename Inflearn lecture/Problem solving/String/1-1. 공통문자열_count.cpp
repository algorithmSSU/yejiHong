#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<string> v;

    int len=INT_MAX;

    // 입력받을 때, 가장 길이가 짧은 문자열의 길이 저장
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        v.push_back(temp);
        int temp_len= temp.length();
        len=min(len,temp_len);
    };

    // 가장 짧은 길이만큼만 확인
    // 접두사니까 -> 입력받은 문자열의 각 맨 앞부터 검사했을 때, 다른 경우 종료
    string res ="";
    for(int i=0;i<len;i++){
        string tmp="";
        for(int j=0;j<v.size();j++){
            tmp+=v[j][i];
        };
        /*
        for(auto &s : v){
            tmp+=s[i];
        }*/

        // count(시작위치,종료위치,count할 값); => count할 값이 범위 내에서 몇개 있는지 체크
        int m=count(tmp.begin(),tmp.end(),tmp[0]);
        if(m==n){
            res+=tmp[0];
        }else{
            break;
        }
    }
    cout << res << endl; 
    return 0;
    
};

/*
https://junekkk.tistory.com/20
*/
