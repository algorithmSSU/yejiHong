#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
using std::pair;

int dp[500][500];


/*
???모르겠음 다시 도전,,,
*/


int main(){

    int n;
    cin >> n;
    vector<pair<int, int>> v;

    for (int i = 0; i < n;i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    };

    for (int i = 0; i < n;i++){
        dp[i][i] = 0;
    }
};

