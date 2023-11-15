#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N;
int M;
int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int *card;
    vector<int> answer;

    cin >> N;
    card= new int[N];

    for(int i=0;i<N;i++){
        cin >> card[i];
    }

    cin >> M;
    //정렬 필수
    sort(card,card+N);


    for(int i=0;i<M;i++){
        int x;
        cin >> x;
        
        int start =0;
        int end = N-1;
        
        bool flag = false;
        while(start<=end){
            int mid = (start+end)/2;

            if(card[mid]==x){
                flag = true;
                break;
            }
            if(card[mid]>x){
                end = mid-1;
            }else if(card[mid]<x){
                start =mid+1;
            };
        }
        if(flag){
            answer.emplace_back(1);
        }else{
            answer.emplace_back(0);
        }
        
    }

    for(auto it : answer){
        cout << it << " ";
    }cout << '\n';
    

}