#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> text[5];
int main(){
    string str;
    cin >> str;

    // 정상인지 확인 ---1

    if(str.length()%5!=0){
        cout << -1 << '\n';
        return 0;
    }


    // 문자에 대한 인덱스 저장
    for(int i=0;i<str.length();i++){
        if(str[i]=='q'){
            text[0].emplace_back(i);
        }else if(str[i]=='u'){
            text[1].emplace_back(i);
        }else if(str[i]=='a'){
            text[2].emplace_back(i);
        }else if(str[i]=='c'){
            text[3].emplace_back(i);
        }else if(str[i]=='k'){
            text[4].emplace_back(i);
        }
    }

    // 모두 등장한 횟수 세기
    int cnt = 1e9;
    for(int i=0;i<5;i++){
        int txs = text[i].size();
        cnt = min(txs,cnt);
    }


    // 정상인지 확인 --- 2
    bool flag = true;
    for(int i=0;i<cnt;i++){
        for(int j=0;j<5-1;j++){
            if(text[j][i]>text[j+1][i]){
                flag = false;
                break;
            }
        }
    }

    if(!flag){
        cout << -1 << endl;
        return 0;
    }


    vector<int> start;
    vector<int> end;

    for(int i=0;i<cnt;i++){
        start.push_back(text[0][i]);
        end.push_back(text[4][i]);
    }


    int duck=0;
    int e_idx=0;
    for(int i=0;i<cnt;i++){
        if(start[i]<end[e_idx]){
            duck++;
        }else if(start[i]<end[i]){
            e_idx++;
        }
    }

    // 정상인지체크 ---3
    if(duck==0){
        cout << -1 << '\n';
        return 0;
    }


    cout << duck << endl;





}