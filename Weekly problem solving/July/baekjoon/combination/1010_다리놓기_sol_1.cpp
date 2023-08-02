#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<long long int> answer;
    cin >> n;

    for(int i=0;i<n;i++){
        long long int a;
        long long int b;
        long long ans = 1;
        int child = 1;
        cin >> a>> b;
        for(int j=b;j>b-a;j--){
            ans*=j;
            ans/=child++;
        };
        answer.emplace_back(ans);

        
    };

    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }

}