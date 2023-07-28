#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector<int> ans[10];
    for(int i=0;i<n;i++){
        int num;
        int max = -1e9;
        int min = 1e9;
        cin >> num;
        for(int j=0;j<num;j++){
            int number;
            cin >> number;
            max = max < number ? number : max;
            min = min > number ? number : min;
        }
        ans[i].emplace_back(min);
        ans[i].emplace_back(max);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}