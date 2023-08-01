#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<int> answer;
    cin >> n;

    int arr[100001]={0,};
    int line_sum[100001]={0,};

    for(int i=1;i<=n;i++){
        cin >> arr[i];
        line_sum[i]=arr[i]+line_sum[i-1];
    };

    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        int temp = line_sum[b]-line_sum[a-1];
        answer.emplace_back(temp);
    };

    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }


    


}