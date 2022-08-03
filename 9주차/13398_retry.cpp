#include <iostream>
#include <vector>
using namespace std;
int leftsum[100010];
int rightsum[100010];
int score[100010];

int temparr[100010];
int n;
int main(){

    cin >> n;
    for (int i = 0; i<n;i++){
        cin >> score[i];
    };

    // 연속된 숫자끼리 연산
    leftsum[0] = score[0];
    for (int j = 1; j < n; j++){
        leftsum[j] = max(leftsum[j], leftsum[j - 1] + score[j]);
    };

    temparr[0] = score[0];
    int result = score[0];

    for (int i = 1;i<n;i++){
        temparr[i] = max(leftsum[i-1], temparr[i - 1] + score[i]);
        result = max(result, temparr[i],leftsum[i]);
    }

    cout << result << endl;
};

