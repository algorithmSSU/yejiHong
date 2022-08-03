#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> map;
 // 2칸 0으로 초기화

int N;
void input(){

    cin >> N;
    for (int i = 0; i < N;i++){
        string s;
        cin >> s;
        for (int j = 0; j < s.length();j++){
            map[i][j] = s[j] - '0'; // char -> int
        };
    };
};

void print(vector<vector<int>> m){
    for (int i = 0; i < m.size();i++){
        for (int j = 0; j < m[0].size();j++){
            cout << m[i][j];
        }
        cout << "\n";
    };
}

// x좌표,y좌표,한변의길이,map,0or1카운팅
void dfs(int x, int y, int size, vector<vector<int>> &map, vector<int> &count){
    bool only_one, only_zero;

    for (int i = x; i < x+size;i++){
        for (int j = y; y < y+size;j++){
            if(map[i][j]==0){
                only_one = false;
            };
            if(map[i][j] ==1){
                only_zero = false;
            };
        };
    };

    if(only_zero==true){
        count[0]++;
        return;
    };

    if(only_one==true){
        count[1]++;
        return;
    };

    dfs(x, y, size / 2, map, count);
    dfs(x, y+size/2, size / 2, map, count);
    dfs(x+size/2, y, size / 2, map, count);
    dfs(x + size / 2, y + size / 2, size / 2, map, count);
};

vector<int>solution(vector<vector<int>> arr){
    vector<int> check(2, 0);

    dfs(0, 0, arr.size(), map, check);
    return check;
}