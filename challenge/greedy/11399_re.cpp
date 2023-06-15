#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;
    int result = 0;
    cin >> n;

    vector<int> num;
    vector<int> sum;

    for (int i = 0;i<n;i++){
        int temp;
        cin >> temp;
        num.push_back(temp);
    };

    sort(num.begin(), num.end());

    for (int i = 0; i < n; i++){
        result += num[i];
        sum.push_back(result);
    };

    result = 0;

    for (int i = 0; i < sum.size();i++){
        result += sum[i];
    };

    cout << result << endl;
};