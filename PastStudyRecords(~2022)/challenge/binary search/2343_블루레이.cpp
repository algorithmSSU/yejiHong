#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX = 100000;


/*


코드를 봐도 이해가 안감..

이건 고수님께 설명을듣고 다시 분석해보기


*/



int N, M;

int blueray[MAX];



bool func(int mid){ //20
    int sum = 0;

     //블루레이 수
    int num = 1;
    for (int i = 0; i < N;i++){
        //곡 하나가 최대 녹음시간보다 길 수 없습니다.
        if (blueray[i] > mid)
        return false;

        
        sum += blueray[i]; // 1
        
        if (sum > mid) //  ...21 > 20
        {
            sum = blueray[i]; // 
            num++;
        };

    };
    return M >= num;
};

int main()
{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cin >> N >> M;

    int sum = 0;

    for (int i = 0; i < N; i++){

        cin >> blueray[i];

        sum += blueray[i]; // 총 녹음 시간
    };

    /*최소값과 최대값 정해주기*/
    int low = 1, high = sum;

    int result = 0;

    while (low <= high){
    int mid = (low + high) / 2; //mid는 최대 녹음 시간

    if (func(mid)){
        result = mid;
        high = mid - 1;
        }else
        {
            low = mid + 1;
        };
};

cout << result << "\n";

return 0;
};


/*

1,2,3,4,5,6,7,8,9

mid : 20
if(func(mid)){

}



*/