#include <iostream>
#include <vector>
#include <math.h>
#include <set>
using namespace std;
int solution(vector<int> nums);
bool isdecimal(int num);
bool isdecimal(int num)
{
    if (num < 2)
    {
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
int main(){

    vector<int> nums = {1, 2,7,6,4};
    int answer = 0;
    answer = solution(nums);
    cout << answer << endl;
    return 0;
};

int solution(vector<int> nums){
    int answer = 0;
    set<int> decimal;
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                sum = nums[i] + nums[j] + nums[k];
                if (isdecimal(sum))
                {
                    //decimal.insert(sum);
                    cnt++;
                };
            };
        };
    };

    answer = cnt;
    return answer;
};