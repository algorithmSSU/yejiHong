#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;

vector<int> snack;
int check(int n);
void solution();
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M;i++){
        int tmp;
        cin >> tmp;
        snack.push_back(tmp);
    };

    sort(snack.begin(), snack.end());

    solution();
};

int check(int mid)
{
    int c = 0;
    for (int i = 0; i < M; i++)
    {
        c += snack[i] / mid;
    };
    return c < N;
};

void solution()
{

    int answer;
    int left = 1;
    int right = snack.back();

    while(left<=right){
        int mid = (left + right) / 2;

        if(check(mid)){
            right = mid - 1;
        }else{
            answer = answer > mid ? answer : mid;
            left = mid + 1;
        };
    };
    cout << answer << endl;
};
