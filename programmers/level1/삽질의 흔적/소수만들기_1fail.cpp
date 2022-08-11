#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;



int solution(vector<int> nums);
bool isdecimal(int num);
int main(){

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(4);

    int ans;
    ans = solution(nums);
    cout << ans << endl;
};

bool isdecimal(int num){
    if(num<2){
        return false;
    }
    int a = (int)sqrt(num);
    for (int i = 2; i <= a; i++)
    {
        if (num % i == 0)
        {
            return false;
        };
    };
    return true;
};

int solution(vector<int> nums)
{
    int answer = -1;
    set<int> ans;

    sort(nums.begin(), nums.end());
    
    do{
        int sum = 0;
        for (int i = 0; i < 3; i++){
            sum += nums[i];
        };
        if (isdecimal(sum))
        {
            ans.insert(sum);
        };
        //cout << sum << endl;

    } while (next_permutation(nums.begin(), nums.end()));

    return ans.size();
}

