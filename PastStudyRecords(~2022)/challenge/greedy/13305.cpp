#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n;
vector<int> f;
vector<int> d;
int min_cost();
int total_oil_cost;

int main()
{
    // 도시 개수
    cin >> n;

    // 도시 별 도로의 길이
    for (int i = 0; i < n - 1; i++)
    {
        long long temp;
        cin >> temp;
        d.push_back(temp);
    };


    // 도시 별 주유 가격
    for (int j = 0; j < n; j++)
    {
        long long temp;
        cin >> temp;
        f.push_back(temp);
    };
    // 제일 왼쪽 도시에서 제일 오른쪽 도시로 가는 최소 비용 계산
    cout << min_cost() << endl;
};

int min_cost()
{
    long long min_oil_cost;
    
    // 우선, 첫 번째 도시의 주유 비용을 최소 주유 비용으로 지정
    min_oil_cost = f[0];

    // 두번째 주유소 까지 최소비용 = 첫번째 주유소 비용 * 두번째 오기까지 거리
    total_oil_cost += min_oil_cost * d[0];



    // 두번째 주유소부터 ~ 끝까지
    for (int i = 1; i < n - 1; ++i)
    {   
        // 앞 선 주유소 비용과 2번째 주유소~ 지점의 비용 비교

        // 앞 선 주유소 비용이 더 싸다면
        // 앞 선 주유소 비용으로 그 다음 주유소 까지 비용 계산(최소비용업데이트)
        if (min_oil_cost < f[i])
        {
            total_oil_cost += min_oil_cost * d[i];
        }
        // 현재 주유소 비용이 더 싸다면
        // 현재 주유소 비용으로 그 다음 주유소 까지 비용 계산(최소비용업데이트)
        else
        {
            min_oil_cost = f[i];
            total_oil_cost += min_oil_cost * d[i];
        };
    };

    return total_oil_cost;
};


/*


일단 시작할 때 최소 비용은 2번째 주유소까지 갈 때 필요한
연료의 비용이다.
최소 2번째 주유소까지는 움직여야 하기 때문에, 
첫번째 주유소 리터당 비용 * 두번째 지점까지 갈 때 거리 = 최소비용

그리고 2번째 이후 부터는 앞서 계산된 주유비용과 현재 주유소의 주요비용
을 비교해서 더 작은 값으로 그 다음 주유소 까지의 거리를 곱해서
최소 주유 비용을 업데이트해나가면된다.

즉 앞 주유소 비용과 현재 지점의 주유소 비용을 비교해서
더 적은 주요소 비용으로 그 다음 주요소까지 간 다음(거리를 곱해서 최소 주유비용을 구한다음)
또 위치한 주유소 비용과 이전 주유소 비용을 비교해서
더 적은 주유소 비용으로 목적지까지 계산하면 된다. (for loop)


*/