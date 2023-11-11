#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define MAX 1004
int v[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int answer =0;


    cin >> n;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    // ⭐️가장 큰 값의 인덱스 구하기
    // max_element(배열+1,배열+크키+1)-배열
    int maxIndex = max_element(v+1,v+n+1)-v;
    cout << maxIndex << endl;

    bool f1 = true;
    bool f2 = true;
    for(int i=1;i<=maxIndex-1;i++){
        if(v[i-1]>v[i]){
            f1 = false;
        }
    }
    for(int j=maxIndex+1;j<n;j++){
        if(v[j]<v[j+1]){
            f2 = false;
        }
    }

    if(f1&&f2){
        for(int i=0;i<n;i++){
            answer+=v[i];
        }
        cout << answer << endl;
    }else{
        cout << 0 << endl;
    }
}
