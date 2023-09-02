#include <iostream>
#include <vector>

using namespace std;


int answer = 0;
void dfs(vector<int> numbers,int target, int sum, int index){
    if(index==numbers.size()){
        if(sum==target){
            answer++;
        }
        return;
    }
    // 한 숫자에서 가질 수 있는 경우의 수는 +/- 여서 2가지
    // 매 두개의 분기로 나누어져서 계산됨
    dfs(numbers,target,sum+numbers[index],index+1);
    dfs(numbers,target,sum-numbers[index],index+1)
}

int solution(vector<int> numbers,int target){
    dfs(numbers,target,0,0);

}