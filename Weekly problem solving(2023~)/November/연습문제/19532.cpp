#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    double a,b,c,d,e,f;
    cin >> a >> b>> c >> d>> e>> f;

    double x = d * (-1*b);
    double y = d * (-1*c);
    
    x+= a * e;
    y+= a * f;

    
    double ry = y/x;

    double rx = (c-(b*ry))/a;
    

    cout << rx << " " << ry << endl;


    
}