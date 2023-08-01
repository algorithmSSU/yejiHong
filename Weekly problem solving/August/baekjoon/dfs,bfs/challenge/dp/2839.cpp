#include <iostream>
using namespace std;

int sugar[5001] = {0, -1, -1, 1, -1, 1, 2, -1, 2, 3, 2};

int main()
{

    int num;

    cin >> num;

    for (int i = 11; i <= num; i++)
    {
        if (i % 5 == 0)
        {
            int temp = i / 5;
            sugar[i] = temp;
        }
        else if (i % 3 == 0)
        {
            sugar[i] = sugar[i - 3] + 1;
        }
        else
        {
            sugar[i] = sugar[i - 3] + 1;
        }
    };

    cout << sugar[num] << endl;
};

/*

9 : 3 / 3*3
10 : 2 / 5*2
11 : 3 / 3*2 + 5*1
12 : 4 / 3*4
13 : 3 / 3*1 + 5*2
14 : 4 / 3*3 + 5*1
*/