#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<string> v;
    int len = 101;
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        v.push_back(temp);
        int temp_size = temp.length();
        len = min(len,temp_size);// input words 중 가장 짧은 길이
    };

    string res="";
    for(int i=0;i<len;i++){ // 가장 짧은 길이 만큼만 반복
        set<char> s;
        for(int j=0;j<n;j++){
            s.insert(v[j][i]); // set 은 중복을 허용하지 않음, 따라서 같은 인덱스에 같은 문자 존재하면 set 에는 하나의 문자만 담김
        };
        if(s.size()>1){ // 서로 다른 문자가 있다는 것이므로
            break;
        }else{
            res+=v[0][i]; // set은 index 접근이 불가능
        }
    };
    cout << res << endl;



}