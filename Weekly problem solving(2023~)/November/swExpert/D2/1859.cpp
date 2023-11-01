#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;
    int test_case;
    
    cin >> T;

    vector<long long> answer;

    for(test_case = 1;test_case<=T; ++test_case){
        int sub_test;

        cin >> sub_test;
        vector<int> sub;


        for(int i=0;i<sub_test;i++){
            int num;
            cin >> num; 
            sub.emplace_back(num);
        }

        // 마지막 값을 기준으로
        int max_value = sub[sub.size()-1];
        int idx = sub.size()-2; // 맨 끝 값 앞부터 시작


        long long item_count = 0;
        long long item_sum = 0;
        long long total_benefit = 0;
        bool flag = true;
        for(int k = idx; k>=0; k--){
            if(max_value >= sub[k]){
                flag = true;
                item_count++;
                item_sum+=sub[k];
            }else if(max_value < sub[k]){
                flag = false;
                // 이전까지 발생한 이익 정산 -> 여기서만 해주면,마지막 값보다 큰 값이 중간에 나오지 않는 경우 정산못함
                total_benefit += (max_value * item_count) - item_sum;
                // 최대값 갱신(기준바꿔주어야함)
                max_value = sub[k];
                item_count = 0;
                item_sum = 0;
            }

        }

        //flag 로 한번 더 확인
        // flag == true then 정산할게 남아 있음
        if(flag){
            total_benefit += (max_value * item_count) - item_sum;
        }

        answer.emplace_back(total_benefit);
    }

    int tag = 1;
    for(auto it : answer){
        cout << "#" <<  tag++ << " " << it << '\n';
    }

    


}