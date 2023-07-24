#include <iostream>
#include <algorithm>
using namespace std;
int house[1001][3];
int main()
{
    int N;
    cin >> N;

    int input[3];

    house[0][0]=0;
    house[0][1]=0;
    house[0][2]=0;

    for(int i=1;i<=N;i++){
        cin >> input[0] >> input[1] >> input[2];
        house[i][0] = min(house[i-1][1],house[i-1][2])+input[0];
        house[i][1] = min(house[i-1][2],house[i-1][0])+input[1];
        house[i][2] = min(house[i-1][1],house[i-1][0])+input[2];
    };

    cout << min(min(house[N][0],house[N][1]),house[N][2]) << '\n';
}