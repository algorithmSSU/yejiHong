#include <stdio.h>
#include <math.h>
#include <cmath>

using namespace std;
int main()
{
    float a, b;
    scanf("%f %f", &a, &b);

    float temp1 = a * (b / 30);
    float temp2 = a * 1;
    int res = (int)temp1 + (int)temp2;

    printf("%d", res);
}