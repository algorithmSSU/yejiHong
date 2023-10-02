#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> c;
int N, M;
int solution(vector<int> num);
int main(){
    cin >> N >> M;

    for (int i = 0; i < N;i++){
        int temp;
        cin >> temp;
        c.push_back(temp);
    };

    sort(c.begin(), c.end());

    cout << solution(c) << endl;
};

int solution(vector<int> num){

    int answer = 0;
    int max = num.back(); // 9
    int min = 0;
    
    while(min<=max){
        
        int mid = (max + min) / 2;

        int start = num.front();
        int diff = 0;
        int set_count = 1;
        for (int i = 1; i < N;i++){
            if(num[i]-start>=mid){
                set_count++;
                start = num[i];
            };
        };

        if(set_count<M){
            max = mid - 1; // 범위를 좁힌다.
        }else{
            answer = mid;
            min = mid + 1; // 범위를 넓힌다.
        }
    };
    return answer;
};

/*

1 2 4 8 9
mid : 4

1->2 : 1
1->4 : 3
1->8 : 7 >= mid







*/