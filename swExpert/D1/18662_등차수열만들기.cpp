#include<iostream>
#include<algorithm>
#include<iomanip>
#include<math.h>
using namespace std;

 
int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin >> T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
 
        double res;
        int arr[3] = {0,};
        double a, b;
        for (int i = 0; i < 3; ++i) {
            cin >> arr[i];
        }
 
        a = abs((arr[0] + arr[2]) / 2.0 - arr[1])*1.0;
        b = abs(arr[0] + arr[2] - 2*arr[1])*1.0;
        res = a < b ? a : b;
 
        cout << "#" << test_case << " ";
        cout << fixed << setprecision(1) << res << "\n";
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}