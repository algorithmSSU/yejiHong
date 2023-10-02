#include <iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int> &arr, int target, int start, int end);

int n, target;
vector<int> arr;

int main(){
    cin >> n >> target;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    };

    int result = binarysearch(arr, target ,0, n - 1);
    if(result==-1){
        cout << "not found" << "\n";
    }else{
        cout << result + 1 << "\n";
    }
    return 0;
};



int binarysearch(vector<int>& arr, int target,int start, int end){
    while(start<=end){
        int mid = (start + end) / 2;

        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]>target){
            end = mid - 1;
        }
        else{ // arr[mid]<target
            start = mid + 1;
        };
    };
    return -1;
};

/*


start          mid           end
        ★
★<mid
end = mid-1;
______________________________________
start       mid       end
        ★
★<mid
end = mid-1;
______________________________________
start   mid    end
        ★
mid == start
return 0;
______________________________________
*/