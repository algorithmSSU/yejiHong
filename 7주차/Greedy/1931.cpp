#include <iostream>
#include <vector>
#include <algorithm>

/*
회의실 배정

끝나는 시간에 집중
끝나는 시간이 가장 빠른 것부터 시작
끝나는 시간보다 시작시간이 큰 것 중 끝나는 것이 빠른 것부터 시작
...반복

pair자료구조 이용하면 좀 더 쉽게 짤 수 있음
first, second -> 시작시간, 끝나는시간

*/


using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    int savetime = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (savetime <= a[i].second)
        {
            savetime = a[i].first;
            ans++;
        }
    }
    cout << ans << endl;
};