#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> nums;
int binarysearch(int low, int high, int target);

int main()
{

    for (int i = 0; i < 30; i++)
    {
        nums.push_back(i * 2);
    };

    if (binarysearch(0, nums.size(), 22))
    {
        cout << "exist" << endl;
    }
};

int binarysearch(int low, int high, int target)
{
    if (low > high)
    {
        return 0;
    }
    else
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return 1;
        }
        else if (nums[mid] < target)
        {
            return binarysearch(mid + 1, high, target);
        }
        else
        {
            return binarysearch(low, mid - 1, target);
        };
    };
};