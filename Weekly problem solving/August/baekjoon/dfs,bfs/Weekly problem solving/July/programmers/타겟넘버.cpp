#include <iostream>
#include <vector>


using namespace std;

int cnt = 0;
void dfs(vector<int>numbers,int target,int sum,int index){
    if(index==numbers.size()){
        if(sum==target){
            cnt++;
        }
        return;
    }

    dfs(numbers,target,sum+numbers[index],index+1);
    dfs(numbers,target,sum-numbers[index],index+1);
};





int solution(vector<int>numbers,int target){
    //int ans = 0;

    dfs(numbers,target,0,0);

    return cnt;
}





int main(){

    vector<int> numbers = {1,1,1,1,1};
    int target = 5;
    int answer = 0;

    answer = solution(numbers,target);
    cout << answer << '\n';


}