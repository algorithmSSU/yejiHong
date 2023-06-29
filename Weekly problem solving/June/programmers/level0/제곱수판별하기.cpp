#include <iostream>
#include <math.h>
 
using namespace std;

int main(){
    int n;
    n = sqrt(144);
    cout << n << endl;
}
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(int n)
{
    int answer = 0;
    int sqr = sqrt(n);

    if ((sqr * sqr) == n)
    {
        answer = 1;
    }
    else
    {
        answer = 2;
    }

    return answer;
}