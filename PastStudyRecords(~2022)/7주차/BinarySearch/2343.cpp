#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
9 3
1 2 3 4 5 6 7 8 9

9개의 강의 수
3개로 분류해야함
이 때 가능한 블루레이 크기 중 최소를 출력 = 17
<최소 : 나누어진 크기 중 가장 큰 값>
최소를 가장 작게 만들어야 함.

123 456 '789' : 최소 24
123 '4567' 89 : 최소 22
1234 '567' 89 : 최소 18
12345 67 '89' : 최소 17

123 456 789 -> 6 15 24
123 4567 89 -> 6 22 17
1234 567 89 -> 10 18 17
12345 67 89 -> 15 13 17
먼저 입력된 숫자순서대로 큰 그룹 3개로 분류하고
3개 중 가장 큰 값을 가지는 그룹에서 가장 첫번째 값을 
이전 그룹에 포함시켜 계산한다.
가장 왼쪽 그룹에 원소를 옮겼을 때,
각 그룹의 최대 값이 가능한 블루레이 크기 중 최소 값

8 4 
24685173

24 68 51 73 -> 6 14 6 10 / 
246 8 51 73-> 12 8 6 10


8 4
1 9 7 6 8 3 10 5
19 76 83 105-> 10 13 11 15
19 76 8310 5 -> 10 13 21 5
19 768 310 5 -> 10 21 13 5
197 68 310 5 -> 17 14 13 5
19 76 8310 5 -> 10 13 21 5
19 76 83 105 -> 10 13 11 15


8 4
10 1 5 8 2 4 3 0
101 58 24 30 -> 11 13 6 3
101 5 824 30 -> 11 5 14 3
101 5 82 430 -> 11 5 10 7
10 15 82 430 -> 10 6 10 7



*/

void bluray_min(vector<int>&a,int group);

vector<int> a;
int main(){

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N;i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    };

    bluray_min(a,M);
};






void bluray_min(vector<int>&a,int group){
    vector<int> arr[10000];
    int sum, m = 0;
    vector<int> s;

    int size = a.size() / group;

    for (int i = 0; i < group;i++){
        for (int j = 0; j < size;j++){
            arr[i].push_back(a[j]);
        };
    };

    while(1){
        for (int i = 0; i < group;i++){
            for (int j = 0; j < arr[i].size();j++){
                sum += arr[i][j];
            };
            s.push_back(sum);
        };

        int min_index = max_element(s.begin(),s.end())-s.end();

        int front, next;
        front = min_index - 1;
        next = min_index + 1;

        if(s[front]<s[next]){
            arr[front].push_back(next);
        }
    }

    // 3개 배열의 벡터 총합 구하기 -> 최대 값 찾기 -> 최대 값을 가지는 배열 인덱스 리턴
    // 최대값을 가지는 배열 인덱스에서 v[0]값을 이 전 배열의 벡터에 삽입
    // 3개 배열의 벡터 총합 구하기 -> 최대 값 찾기 -> 최대 값을 가지는 배열 인덱스 리턴
    // ... 반복
    // 
}