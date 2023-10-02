#include <iostream>
#include <vector>

using namespace std;

int main(){

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);


    int arr[100001]={0,};
    int layer[100001]={0,};
    int n,line;
    cin >> n >> line;
    

    int idx = 1;
    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        arr[i]=num;
    }

    for(int i=1;i<=n;i++){
        layer[i]=layer[i-1]+arr[i];
    }

    

    int answer = 0;
    while(line--){
        int start, end;
        cin >> start >> end;
        int temp=start-1;
        answer=layer[end];
        answer-=layer[temp];
        cout << answer << '\n';
    }

    
}