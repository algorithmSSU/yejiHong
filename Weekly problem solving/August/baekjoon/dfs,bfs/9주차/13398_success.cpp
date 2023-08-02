#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int leftsum[100010];
int rightsum[100010];
int score[100010];

int temparr[100010];
vector<int> result;
int n;

int main(){

    cin >> n;

    int left, right;
    int lidx;
    for (int i = 0;i<n;i++){
        cin >> score[i];
    };

    leftsum[0] = score[0];
    for (int i = 1; i < n;i++){
        leftsum[i] = max(leftsum[i - 1] + score[i], score[i]);
    };

    // 새로운 자리에서 앞 연산을 더한 것 vs 새로운 자리 값

    /*leftsum 전체 확인*/
    // for (int i = 0; i < n;i++)
    // {
    //     cout << leftsum[i] << " ";
    // };

    // cout << "\n";

    /*
    
    각 인덱스 마다 연속적으로 합산했을 때,
    최대값이 올 수 있게 저장해둔 뒤,
    다시 그 배열을 이용해서 연속최대값을 구함

    */
   
    temparr[0] = score[0];
    int result = score[0];
    for (int i = 1; i < n; i++)
    {
        temparr[i] = max(leftsum[i - 1], score[i] + temparr[i - 1]);
        result = max(result,max(leftsum[i] ,temparr[i]));
    };

    cout << result << endl;

    return 0;
};