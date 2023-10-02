#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    string input;

    cin >> n;
    cin >> input;


    int count_a,count_b;
    char ans;
    count_a = std::count(input.begin(),input.end(),'A');
    count_b = std::count(input.begin(),input.end(),'B');

    if(count_a==count_b){
        cout<< "Tie" << endl;
    }else{
        ans = count_a < count_b ? 'B' : 'A';
        cout << ans << endl;
    }
    



}