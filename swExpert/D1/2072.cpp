#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int test_case;
    int T;

    cin >> T;

    vector<int> answer;

    for(test_case = 1; test_case <= T; ++test_case){
        
        // 홀수 갯수
        int odd = 0;
        // 10개의 수
        for(int i=0;i<10;i++){
            int num;
            cin >> num;
            if(num%2!=0){
                odd+=num;
            }
        }
        answer.emplace_back(odd);
    }

    int tag = 1;
    for(auto it : answer){
        cout << "#" << tag++ << " " << it << '\n';
    }


    return 0;




}