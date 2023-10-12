#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int arr[9];
int *arr_;
int answer[9];
bool visited[9]={false,};
int n,m;
set<vector<int> > s;
void backT(int cnt){
    if(cnt==m){
        vector<int> temp;
        for(int i=0;i<cnt;i++){
            temp.emplace_back(answer[i]);
        }

        s.insert(temp);
        return;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            answer[cnt]=arr_[i];
            backT(cnt+1);
            visited[i]=false;
        }

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    arr_ = new int[n];

    for(int i=0;i<n;i++){
        cin >> arr_[i];
    }

    sort(arr_,arr_+n);

    backT(0);

    for(auto it : s){
        for(auto vi : it){
            cout << vi << " ";
        }
        cout << '\n';
    }
}