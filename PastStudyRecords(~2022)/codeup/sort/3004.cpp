#include <iostream>
#include <vector>
using namespace std;

struct number{
    int num;
    int index;
    int nidx;
};


// 사용자 정렬 함수 헷갈린다


bool compare(const number &a, const number &b){
    if(a.num==b.num){ // num값이 같다면,
        return a.num>b.num; // num값이 더 큰게 앞으로 가도록!
    }
    return a.num<b.num; // num값이 같지 않다면, num값이 더 큰 값이 뒤로 가도록!
}


bool compare2(const number &a, const number &b){
    return a.index < b.index;// 이 조건이 true 이면 앞으로 가도록
}

int main(){
    int n;

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<number> v;
    cin >> n;

    for(int i=0;i<n;i++){
        number num;
        int x;
        cin >> x;
        num.index= i;
        num.num = x;
        v.push_back(num);
    };
    sort(v.begin(), v.end(), compare);

    for(int i=0;i<n;i++){
        v[i].nidx = i;
    };

    sort(v.begin(),v.end(),compare2);

    for(int i=0;i<n;i++){
        cout << v[i].nidx << " ";
    };
    cout << endl;
    
}