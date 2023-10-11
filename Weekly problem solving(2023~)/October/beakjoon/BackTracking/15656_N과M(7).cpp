#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> arr;
int out[8];
bool visited[8]={false,};
int n,m;


void backT(int cnt){
    if(m==cnt){
        for(int i=0;i<cnt;i++){
            cout << out[i] << " ";
        }
        cout << '\n';

        return;
    }
    for(int i=0;i<n;i++){
        out[cnt] = arr[i];
        backT(cnt+1);

    }

}


int main(){
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        int temp;
        cin >> temp;
        arr.emplace_back(temp);
    }

    sort(arr.begin(),arr.end());

    backT(0);
    
}