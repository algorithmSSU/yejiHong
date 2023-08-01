#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int answer = 0;
    cin >> n;

    vector<int> num;
    vector<int> num2;
    

    for (int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        num.push_back(temp);
    };

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        num2.push_back(temp);
    };

    sort(num.begin(), num.end());
    sort(num2.begin(), num2.end(), greater<>());

    for (int i = 0; i < n;i++){
        answer += num[i] * num2[i];
    };

    cout << answer << endl;
};


/*




*/