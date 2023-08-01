#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using std::pair;
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<pair<int,string>> str;
    set<string> s;

    for (int i = 0; i < n;i++){
        string temp;
        cin >> temp;
        s.insert(temp);
    };

    set<string>::iterator iter;
    for (iter = s.begin(); iter != s.end();iter++)
    {
        str.push_back(make_pair((*iter).length(), *iter));
    };

    sort(str.begin(), str.end());

    for (int i = 0; i < str.size();i++){
        cout << str[i].second << endl;
    };
};

/*

1. 중복 문자를 걸러내기 위해, 처음에는 set 자료 구조로 저장.
2. set iterater 를 통해 set 에 담긴 문자열을 vector자료 구조로 옮겼음
이때, (문자열의 길이, 문자열) 을 pair 로 묶었음
3. sort를 통해 문자열 길이에 따라 오름차순 정렬되도록 함!
pair에서 first를 기준으로 정렬시킬 때는 별다른 설정을 안해주어도 됨.

sort(v.begin(), v.end()); // 오름차순
sort(v.begin(), v.end(), less<>()); // 오름차순
sort(v.begin(), v.end(), greater<>()); // 내림차순

second 를 기준으로 정렬시키고 싶다하면,
bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    };
};

sort(v.begin(), v.end(), compare); 이렇게!!!


*/