#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;
    vector<int> num;
    vector<int> minnum;
    int sum = 0;
    int w;
    
    cin >> n;

    for (int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        num.push_back(temp);
        sum += temp;
    };

    sort(num.begin(), num.end());

    int result = 0;
    for (int i = 0; i < num.size();i++){
        int temp;
        temp = num[i] * (num.size() - i);
        result = max(temp, result);
    };

    cout << result << endl;
};
