#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<string> v;
    cin >> n;

    
    for(int i=0;i<n;i++){
        string first, second;
        string nickname = "god";
        cin >> first >> second;
        nickname+=second;
        v.emplace_back(nickname);
    
    }
    cout << '\n';
    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }


}