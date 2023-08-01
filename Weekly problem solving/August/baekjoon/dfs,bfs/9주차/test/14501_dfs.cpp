#include <iostream>
#include <algorithm>
using namespace std;


/*포인터로 미리 선언 후 input 사이즈로 만들어주기*/
int *p;
int *t;
int *dp;
int n;
int max_pay;


void solution(int x,int sum);
int main(){

    cin >> n;

    p = new int[n + 1];
    t = new int[n + 1];
    dp = new int[n + 1];

    for (int i = 0; i < n;i++){
        cin >> t[i] >> p[i];
    };

    solution(0, 0);
    cout << max_pay;
};

/*함수로 받은 시작날짜부터 끝날짜까지 반복하면서 탐색*/
/*그 과정에서 나온 최대 금액을 저장한다.
반복문을 돌리면서 재귀하는데, 이 반복문이 시작날짜부터 끝날짜로
되어 있기 때문에, 위에서 말한 것처럼 하루를 건너뛰는 것도
이 과정에서 자연스럽게 구현된다.*/


void solution(int x,int sum){
    if(x>n){ // 입력 사이즈보다 커지면 종료
        return;
    };
    max_pay = max(max_pay, sum); // 최대값을 계속 갱신해줌
    for (int i = x; i < n;i++){
        solution(t[i] + i, sum + p[i]);
    };
};