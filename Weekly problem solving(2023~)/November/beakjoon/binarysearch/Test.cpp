#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int answer[40000000]={0,};
int main(){
    vector<int> v;
    vector<int> M;
    
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        v.emplace_back(num);
    }

    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int num;
        cin >> num;
        M.emplace_back(num);
    }


    sort(v.begin(),v.end());

    for(int i=0;i<m;i++){
        if(binary_search(v.begin(),v.end(),M[i])){
            answer[i]++;
        }
    }

    for(int j=0;j<m;j++){
        cout << answer[j] << " ";
    }
    cout << '\n';
}