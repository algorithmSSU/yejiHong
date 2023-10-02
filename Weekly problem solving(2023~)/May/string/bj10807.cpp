#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;  
    cin >> n;
    vector<int> v;

    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        v.emplace_back(num);
        
    };
    int me;
    int count =0;
    cin >> me;
    for(int i=0;i<v.size();i++){
        if (me==v[i]){
            count++;
        }
    }

    cout << count << endl;
}