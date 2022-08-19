#include <iostream>
#include <vector>
#include <algorithm>
/*

반례는 이제 해결했는데
런타임에러가 자꾸......

*/

using namespace std;

int binarysearch(int low, int high, int target);

vector<int> nums;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    };

    sort(nums.begin(), nums.end());

    int m;
    cin >> m;

    for (int i = 0; i < m;i++){
        int temp;
        cin >> temp;
        //cout << binarysearch(0, n, temp) << " " ;
        cout << upper_bound(nums.begin(), nums.end(), temp) - lower_bound(nums.begin(), nums.end(), temp) << " ";
    }
};

int binarysearch(int low, int high, int target){

    int answer = 0;
    if(low>high){
        return answer;
    }else{
        int mid = (low + high) / 2;

        if(nums[mid]==target){
            answer++;

            if(mid==0){
                return answer;
            };
            
            for (int i = 1; i <= mid ;i++){
                if(nums[mid+i]==target){
                    answer++;
                }
                if(nums[mid-i]==target){
                    answer++;
                }
                
            };
            return answer;
        }else{
            if(nums[mid]<target){
                return binarysearch(mid+1,high,target);
            }else{
                return binarysearch(low, mid-1, target);
            };
        };
    };
};



/*

-10 -10 2 3 3 6 7 10 10 10

★ 정렬이 된 배열에서 사용할 것 !
* lower_bound : 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
* upper_bound : 찾으려는 key 값을 초과하는 숫자가 배열 몇 번째에서 처음 등장하는지 

lower_bound-> 시작 위치
upper_bound-> 찾는 값 다음 위치

정렬을 한 상태에서 upper_boud - lower_bound = key 값(찾는 값)의 갯수


*/