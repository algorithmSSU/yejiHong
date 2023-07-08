#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> num;

    int ans =1;
    int big=1;
    int small =1;

    for(int i=0;i<n;i++){
        int number;
        cin >> number;
        num.emplace_back(number);
    };

    for(int i=0;i<n-1;i++){
        if(num[i]<=num[i+1]){
            big++;
        }else{
            big=1;
        }
        if(num[i]>=num[i+1]){
            small++;
        }else{
            small=1;
        }
        cout << big << " " << small << endl;
        int save = big<=small ? small : big;
        ans = ans <= save ? save : ans;
    }

    cout << ans << endl;

}