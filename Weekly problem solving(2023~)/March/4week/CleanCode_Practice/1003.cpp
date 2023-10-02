#include <iostream>
#include <vector>
using namespace std;

int a[40]={0,};
void fibo(int n);
pair<int, int> ans[40];
int c=0;



int main(){
    int n;
    vector<int> v;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        fibo(a);
    };

    for(int i=0;i<n;i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
};

void fibo(int n){
    pair<int, int> record[40];
    record[0]=make_pair(1,0);
    record[1]=make_pair(0,1);

    for(int i=2;i<=n;i++){
        int first = record[i-2].first + record[i-1].first;
        int second = record[i-2].second + record[i-1].second;
        record[i]=make_pair(first,second);
    };

    ans[c] = make_pair(record[n].first,record[n].second);
    c++;
}