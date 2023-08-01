#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
using std::pair;


/*다시다시다시*/
/*https://yabmoons.tistory.com/617*/



/*모든 숫자를 하나씩 제거 하면서(無~인덱스마지막꺼까지)
연속수열의 최대값을 갱신해주면됨*/
/*예를 들어 [0]+[1]보다 [1] 이 더 큰 경우
[1]만 저장
*/

int num[100010];
int leftsum[100010];
int rightsum[100010];
vector<int> list;
int continue_max(int index);
int n;
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        num[i] = x;
    };

    int size = sizeof(num) / sizeof(int);
    //cout << size << endl;
    
    for (int i = -1; i < n;i++){
        int answer = continue_max(i);
        list.push_back(answer);
    };

    cout << *max_element(list.begin(), list.end()) << endl;

    
};

int continue_max(int index){
    int answer = 0;
    int temp = 0;
    int left_sum, right_sum;
    if(index==-1){
        rightsum[0] = num[0];
        for (int i = 1; i < n;i++){
            rightsum[i] = max(rightsum[i - 1] + num[i], num[i]);
            answer = max(answer, rightsum[i]);
        };
    };
    if(index==0){
        rightsum[1] = num[1];
        for (int i = 2; i < n;i++){
            rightsum[i] = max(rightsum[i - 1] + num[i], num[i]);
            // 이전값+현재값 vs 현재값 -> 더큰값을 rightsum에 저장
            answer = max(answer, rightsum[i]);// answer 갱신
        };
    }else if(index==n-1){
        leftsum[n - 2] = num[n - 2]; // n-1번째(마지막)을 제거했다고 가정
        for (int i = n - 3; i > 0;i--){
            leftsum[i] = max(leftsum[i + 1] + num[i], num[i]);
            answer = max(answer, rightsum[i]);
        };
    }else{
        if(index==1){
            temp = num[0];//0번째 값
            leftsum[n - 1] = num[n - 1];
            for (int i = n - 2; i > index; i--){
                leftsum[i] = max(leftsum[i + 1] + num[i], num[i]);// 맨뒤에서 부터 
                answer = max(leftsum[i], answer);
            };
            answer += temp;
        }else{
            rightsum[0] = num[0];
            leftsum[n - 1] = num[n - 1];
            //cout << "index:" << index << endl; // index 확인

            //왼쪽부터 제거할 인덱스까지 최대 값 구하기
            for (int i = 1; i < index;i++){
                rightsum[i] = max(rightsum[i - 1] + num[i], num[i]);
                answer = max(answer, rightsum[i]);
                left_sum = answer;
                //cout << "left:" << answer << endl;
            };
            //오른쪽부터 제거할 인덱스까지 최대 값 구하기
            for (int i = n - 2; i > 0;i--){
                leftsum[i] = max(leftsum[i + 1] + num[i], num[i]);
                answer = max(answer, leftsum[i]);
                right_sum = answer;
                //cout << "right:" << answer << endl;
            };
            answer = left_sum + right_sum;
        };
    };

    return answer;
};
