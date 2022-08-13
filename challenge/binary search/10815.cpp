#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> nums;

int binarysearch(int low, int high, int target);

int binarysearch(int low, int high, int target){

    if(low>high){
        return 0;
    }else{
        int mid = (low + high) / 2;
        if(nums[mid]==target){
            return 1;
        }else if(nums[mid]>target){
            return binarysearch(low, mid - 1, target);
        }else{
            return binarysearch(mid + 1, high, target);
        }
    }

};
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n;

    for (int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    };

    sort(nums.begin(), nums.end());

    cin >> m;

    for (int i = 0; i < m;i++){
        int temp;
        cin >> temp;
        cout << binarysearch(0, n, temp) << " ";
    }
};

/*

-10 2 3 6 10


*/
