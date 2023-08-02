#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<string> v, vt;
    int n, m;
    string s;
    cin >> n >> m;

    // n 까지 데이터 먼저 입력받고
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());

    // m 까지 데이터를 받으면서 n을 입력받았던 vector에서 이중탐색 후 새로담아줌
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (binary_search(v.begin(), v.end(), s))
        {
            vt.push_back(s);
        }
    }
    sort(vt.begin(), vt.end());
    cout << vt.size() << "\n";

    /*
    for(int i=0;i<vt.size();i++){
        cout << vt[i] <<endl;
    }

    */
    for (auto o : vt)
    {
        cout << o << "\n";
    }
};



/*

시간초과 ->이중 for문을 쓰면 시간복잡도 문제가 발생
이중 for문의 경우 시간복잡도가 O(n^2) 1만 * 1만 = 1억 -> 대략1초
만약 1억개의 데이터가 들어오는데 실행시간이 1초인 문제를 풀려면
무조건 O(n) 이나 O(Log N)의 시간복잡도로 문제를 풀어야한다..

*/