#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;
using std::pair;



int main(){
    string g;
    float gpa = 0;
    cin >> g;


    for(int i=0;i<g.length();i++){
        char now = g[i];
        switch (now)
        {
        case 'A': gpa+=4;
            break;
        case 'B': gpa+=3;
            break;
        case 'C': gpa+=2;
            break;
        case 'D': gpa+=1;
            break;
        case '+': gpa+=0.3;
            break;
        case '-': gpa-=0.3;
            break;
        case '0': gpa+=0;
            break;
        default:
            break;
        }
    }
    cout << fixed;
    cout.precision(1);
    cout << gpa << endl;


}