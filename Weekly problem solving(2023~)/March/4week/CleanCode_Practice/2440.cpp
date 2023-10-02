#include <iostream>

using namespace std;


void printstar(int n);

int main(){
    int n;
    cin >> n;
    printstar(n);
    
};

void printstar(int n){
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}