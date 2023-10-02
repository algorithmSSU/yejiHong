#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer=0;
    queue<int> load;


    // 다리의 길이만큼 값을채워준다(init:0)
    for(int i=0;i<bridge_length;i++){
        load.push(0);
    };

    int idx = 0;
    int until_weight=0;

    // 다리에 채워진 값이 모두 사라질때 까지 반복한다.
    while(!load.empty()){
        answer++;
        until_weight-=load.front();// 앞에 있는 무게를 뺀다.
        load.pop(); // 맨 앞에 있는 값을 다리 queue에서 아예 빼준다.

        // 주어진 트럭을 모두 확인한다.
        if(idx<truck_weights.size()){

            // 다리 위에 있는 트럭의 누적 무게에 새로 넣어줄 트럭의 무게를 더했을 때 다리가 수용한 무게면,
            if(until_weight+truck_weights[idx]<=weight){
                until_weight+=truck_weights[idx]; // 다리에 올려주고 (다리 누적 무게에 더해주고)
                load.push(truck_weights[idx]); // 다리에 올려준다 (다리 queue에 올려준다)
                idx++; // 다음 트럭을 가리킨다.
            }else{
                load.push(0); // ⭐️ 못 넣으면 0을 넣어주고 다시 돌면서 앞에서부터 빼주는..
            };
        }
        
    }

    return answer;
};

int main(){
    int ans = 0;
    vector<int> truck = {7,4,5,6};
    int bl = 2;
    int weight = 10;

    ans = solution(bl,weight,truck);

    cout << ans << endl;
    
}