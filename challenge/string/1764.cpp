#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

vector<string> nopeople;
vector<string> sub;
int main(){

    int n, m;
    cin >> n >> m;
    int size = n + m;

    for (int i = 0; i < size;i++){
        string temp;
        cin >> temp;
        nopeople.push_back(temp);
        if(i>=n){
            for (int j = 0; j < n;j++){
                if(nopeople[j]==nopeople[i]){
                    sub.push_back(nopeople[j]);
                }
            }
        }
    };
    cout << sub.size() << endl;
    for (int i = 0; i < sub.size();i++){
        cout << sub[i] << endl;
    }
};