#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    int *nums;
    int *ans;
    cin >> n;
    nums = new int[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    sort(nums,nums+n);
    cin >> m;
    ans = new int[m];
    for(int i=0;i<m;i++){
        int num;
        cin >> num;
        int left = lower_bound(nums,nums+n,num)-nums;
        int right = upper_bound(nums,nums+n,num)-nums;
        ans[i] = right-left;
    }

    for(int j=0;j<m;j++){
        cout << ans[j] << " ";
    }

    
}