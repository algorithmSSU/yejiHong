#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/*
이분탐색
1. 정렬
2. 최소, 최대 지점을 구하자 (최고,최악)
3. 최소 <- 중간 -> 최대 (중간)
4. 중간부터 중간인 지점에서 모두 수용이 가능한지 체크
   수용안된다 -> 최소지점 = 중간 재설정
   수용된다 -> 최대지점 = 중간 재설정
   최소 > 최대 -> 종료
*/

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    sort(times.begin(),times.end());
    long long Min = 1;
    long long Max = (long long)times.back() * n;


    while(Min<=Max){
      long long temp = 0;
      long long mid = (Min+Max)/2;
      for(int i=0;i<times.size();i++){
        temp+=(mid/(long long)times[i]);
      }
      if(temp>=n){
        Max= mid-1;
        answer = mid;

      }else{
        Min=mid+1; 
      }

    } 
    return answer;
};
