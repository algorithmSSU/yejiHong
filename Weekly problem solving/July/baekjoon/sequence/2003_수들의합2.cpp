#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m;
    int arr[10001];
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> arr[i];
    };

    int save[10002];


    int cnt = 0;
    for(int i=0;i<=n;i++){
        save[i+1] = arr[i+1] + save[i];
        if(arr[i]==m || save[i+1]==m){
            cnt++;
        }else{
            if(save[i+1]>m){
                int temp = save[i+1]-save[i]+arr[i];
                if(temp==m){
                    cnt++;
                }
            }else if(save[i+1]<m){
                save[i+1]=save[i+1]-save[i]+arr[i];

            }
        };
    };

    cout << cnt << endl;
    

    
}