#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> numbers)
{
    int answer = -1;

    int sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i];
    }
    int hap = 0;
    for (int j = 0; j < 10; j++)
    {
        hap += j;
    };

    answer = hap - sum;
    return answer;
};

int main(){

    vector<int> nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(8);
    nums.push_back(9);

    int ans = solution(nums);
    cout << ans << endl;
}