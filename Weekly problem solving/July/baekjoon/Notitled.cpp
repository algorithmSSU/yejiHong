#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    while (b > 0)
    {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int main(){

    int a = 17;
    int b = 52;

    int answer = 0;
    answer = gcd(a,b);
    cout << answer << endl;

    cout << 36%24 << endl;


    
}