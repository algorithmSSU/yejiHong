#include <iostream>
#include <vector>

using namespace std;
using std::pair;

#define MAX 100001

void findparent(vector<pair<int,int>> arr);

int n;
vector<pair<int, int>> v;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    vector<int> ans;

    for (int i = 0; i < n-1;i++){
        int first, second;
        cin >> first >> second;
        v.push_back(make_pair(first, second));
    }

    findparent(v);
};

void findparent(vector<pair<int, int>> arr){
    vector<int> p[MAX];
    vector<int> ans;


    for (int i = 0; i < arr.size();i++){
        if(arr[i].first ==1){
            p[1].push_back(arr[i].second);
            p[arr[i].second].push_back(1);
        }else if(arr[i].second == 1){
            p[1].push_back(arr[i].first);
            p[arr[i].first].push_back(1);
        }else{
            p[arr[i].first].push_back(arr[i].second);
            p[arr[i].second].push_back(arr[i].first);
        }
    };


    for (int i = 2; i <= n;i++){
        cout << p[i][0] << endl;
    }
};

/*

예제의 출력과 동일하게 나오지만,
문제에서 노드의 순서에 의존적인 방법이었다.
오답!

*/

