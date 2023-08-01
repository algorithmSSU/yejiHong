#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<long long> n);

long long N, M;
vector<long long> tree;


int main(){

    cin >> N >> M;

    long long answer = 0;

    for (int i = 0; i < N;i++){
        long long temp;
        cin >> temp;
        tree.push_back(temp);
    };

    sort(tree.begin(), tree.end());

    answer = solution(tree);

    cout << answer << endl;

    return 0;
};

long long solution(vector<long long> n)
{

    long long start = 0;
    long long end = n.back();
    long long answer = 0;

    // 최소 값이 최대 값보다 작은 경우 계속 탐색
    while(start<=end){

        //어떤 임의의 수부터 시작해서 필요한 길이를 가져갈 수 있도록
        // 계속 탐색을 해주어야 하는데, 
        //주어진 최대값과 최소값(0)의 중간 값을 시작으로 탐색 시작

        long long middle = (start + end) / 2;
        long long tmp = 0;



        
        for (int i = 0; i < n.size();i++){
            if(middle<n[i]){
                tmp += n[i] - middle;
            };
        };

        // 잘린 나무 길이가 가져가려는 길이와 같으면 답 
        if(tmp==M){
            answer = middle;
            break;
        };
        // 잘린 나무 길이가 가져가려는 길이보다 크면
        // 절단기 높이를 더 높여 주어야 함-> 절단기 높이=(최대+최소)/2
        // 즉 최대 혹은 최소 값을 올려주어야 함-> 최소 값 올려주자
        // 최소 값을 중간값 +1로 설정
        if(tmp>=M){
            start = middle + 1;
            answer = middle;
        // 잘린 나무 길이가 가져가려는 길이보다 작으면
        // 절단기 높이를 낮추어 주어야 함 -> 절단기 높이=(최대+최소)/2
        // 즉 최소 혹은 최대 값을 올려주어야 함-> 최대 값을 내려주기
        // 최대 값을 중간값 -1로 설정
        }else{
            end = middle - 1;
        };
        
    };
    return answer;
}

/*

10 15 17 20

5 7 10 = 22
최소값이 최대값보다 작을 때

최소값 : 0
최대값 : 20
max : 20
min : 10
max : 20
min : 25

if(tmp>m){
    min=middle;
    answer =middle;
}
else{

    answer= middle;
}






최소값 = 중간값
최소값 : 10
최대값 : 20
중간값 : 15

else{
    최소값+중간값
    answer = 중간값

}






*/