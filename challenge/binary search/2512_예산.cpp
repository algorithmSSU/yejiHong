#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(vector<long long>budget);
vector<long long> budget;

int N;
long long total;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long answer = 0;
    
    cin >> N;

    for (int i = 0; i < N;i++){
        int num;
        cin >> num;
        budget.push_back(num);
    };

    cin >> total;

    sort(budget.begin(), budget.end());
    

    answer = solution(budget);

    cout << answer << endl;

};  

long long solution(vector<long long> budget)
{
    long long ans = 0;

    
    long long max = budget.back();
    long long min = 0;


    while(min<=max){
        long long mid = (max + min) / 2;

        long long check = 0;
        for (int i = 0;i<budget.size();i++){
            if(budget[i]>mid){
                check += mid;
            }else if(budget[i]<=mid){
                check += budget[i];
            }
        };

        if(check==total){
            ans = mid;
            break;
        };
        if(check>total){
            max = mid-1;
        }else{
            min = mid + 1;
            ans = mid;
        };
    };
    

    return ans;
}