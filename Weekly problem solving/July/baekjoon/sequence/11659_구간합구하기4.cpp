#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> answer;
    int n, m;
    cin >> n >> m;
    
    int arr[100001];
    int layer[10000]={0,};

    for(int i=1;i<=n;i++){
        cin >> arr[i];
        layer[i]=arr[i]+layer[i-1];
    };

    for(int i=0;i<m;i++){
        int start,end,sum;
        sum = 0;
        cin >> start >> end;
        sum=layer[end]-layer[start-1];
        answer.emplace_back(sum);
    };

    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }

}