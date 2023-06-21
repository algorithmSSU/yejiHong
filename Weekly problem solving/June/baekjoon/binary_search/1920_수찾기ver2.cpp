#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> list;
vector<int> sample;

void binary_search(int start, int end, int target){
    if(start>end){
        std::cout << 0 << '\n';
        return;
    }else{
        int mid = (start+end)/2;
        if(list[mid]<target){
            start = mid+1;
            binary_search(start,end,target);
        }else if(list[mid]>target){
            end = mid-1;
            binary_search(start,end,target);
        }else if(list[mid]==target){
            //mid==target
            std::cout << 1 << '\n';
            return;
        }
    }
}

int main(){
    std::cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    
    std::cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        std::cin >> temp;
        list.emplace_back(temp);
    };

    sort(list.begin(),list.end());

    
    int start = 0;
    int end = list.size()-1;



    int m;
    std::cin >> m;

    for(int i=0;i<m;i++){
        int temp;
        std::cin >> temp;
        binary_search(start,end,temp);
    }

    return 0;



}