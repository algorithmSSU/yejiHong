#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int num;
    cin >> num; // 216

    string temp = to_string(num);
    int len = temp.length();

    int start = num - (len * 9);
    // cout << start << endl;

    int sum;
    for (int i = start; i < num; i++)
    {
        int sum = 0;
        string temp = to_string(i);
        // cout << temp << endl;
        for (int j = 0; j < temp.length(); j++)
        {
            char cur = temp[j];
            int n = cur - '0';
            // cout <<"n: "<< n << endl;
            sum += n;
        };
        sum += i;
        // cout << "sum: " << sum << endl;
        if (sum == num)
        {
            cout << i << endl;
            return 0;
        };
    };
    cout << 0 << endl;
    return 0;
};

/*

각 자리수로 올 수 있는 최대 숫자는 9
즉 주어진 숫자에서 주어진 숫자의 자리수 만큼 9를 빼면
주어진 숫자의 최소 값을 구할 수 있다.

ex) 219
219는 3 자리수이다.
219에서 9를 3번 빼면 219의 생성자의 최소 값이 나온다.
219-9-9-9 = 192
따라서 192부터 218까지 탐색해서 생성자를 구하면 된다.

https://gdlovehush.tistory.com/330


*/