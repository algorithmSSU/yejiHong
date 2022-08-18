#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


/*런타임에러 ?? -> 답변기다리기

알고리즘 분류에 따라 어떻게 접근할지를 생각하는게 중요..

*/
int N;
vector<int> num;
void solution(vector<int> num);

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N;i++){
        int temp;
        cin >> temp;
        num.push_back(temp);
    };

    sort(num.begin(), num.end());

    solution(num);

    return 0;
};

void solution(vector<int> num)
{
    int MAXVALUE = 2000000001;
    int left = 0;
    int right = N - 1;

    int finalL, finalR;
    int sum;
    while (left < right)
    {
        sum = num[left] + num[right];
        if(abs(sum)<MAXVALUE){
            MAXVALUE = abs(sum);
            finalL = num[left];
            finalR = num[right];
        };
        if(sum>0){
            right-- ;
        }else{
            left++;
        }
    };

    cout << finalL << " " << finalR << endl;

    return;
};

/*

-99 -2 -1 4 98


이분탐색
mid 를 어떻게 정해주어야 하는가..

min = 0
max = 5
mid = 2

for(int i=0;i<n;i++){

}


*/