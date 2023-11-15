#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int *card;
int lower_bound(int target){
    int st = 0;
    int en = N;

    while(st<en){
        int mid = (st+en)/2;
        if(card[mid]>=target){
            en = mid;
        }else{
            st = mid+1;
        }
    }
    return st;
}

int upper_bound(int target){
    int st = 0;
    int en = N;
    while(st<en){
        int mid = (st+en)/2;
        if(card[mid]>target){
            en =  mid;
        }else{
            st = mid+1;
        }
    }
    return st;
}



int main(){
    
    int *answer;
    cin >> M;
    card =new int[M];
    for(int i=0;i<M;i++){
        cin >> card[i];
    }

    cin >>  N;
    answer = new int[N];

    sort(card,card+N);


    for(int i=0;i<N;i++){
        int target;
        cin >> target;

        // 가장 오른쪽에 있는 target 위치 - 가장 왼쪽에 있는 target 위치
        answer[i]=upper_bound(target) - lower_bound(target);
    }

    for(int i=0;i<N;i++){
        cout << answer[i] << " ";
    }
    cout << '\n';
  
}