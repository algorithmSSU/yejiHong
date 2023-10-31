#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <string>
#include <stack>
using namespace std;
int T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int test_case;
    int T;

    cin >> T;

    vector<long long> answer;

    for(test_case =1; test_case <= T; ++test_case){
        int subtest;
        cin >> subtest;

        vector<int> num_list;

        for(int i=0;i<subtest;i++){
            int num;
            cin >> num;
            num_list.push_back(num);
        }

        long long Max = num_list[num_list.size()-1];

        // 더해줄 아이템 갯수
        long long item = 0;

        // 아이템 원래 값저장
        long long item_sum = 0;


        // 총이익
        long long result = 0;

        bool flag = true;
        for(int i=num_list.size()-2;i>=0;i--){
            flag = true;
            if(num_list[i] <= Max){
                item_sum+= num_list[i];
                item++;
                
            // 만약 더 큰 값이 나온다면, 기존 큰 값일 때 이익더해준다
            // 만약 더 큰 값이 나오지 않는다면 기존 큰 값 이익은 어디서 계산?
            }else if(num_list[i] > Max){
                flag = false;
                result+= (item * Max) - item_sum;
                
                // Max 값 초기화
                Max = num_list[i];
                item = 0;
                item_sum = 0;
            }
        }

        if(flag){
            result+= (item * Max) - item_sum;
        }
        answer.emplace_back(result);
    }

    int tag= 1;
    for(auto it : answer){
        cout << "#" << tag++ << " " << it << '\n';
    }
   
    return 0;
}