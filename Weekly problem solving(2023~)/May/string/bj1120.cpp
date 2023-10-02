#include <iostream>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;

int check(string a,string b){
    int sz = a.length();
    int count=0;
    for(int i=0;i<sz;i++){
        if(a[i]==b[i]){
            continue;
        }else{
            count++;
        }
    }
    return count;
};


int main(){

   ios_base::sync_with_stdio(false);
   cin.tie(0);

   string A,B;
   int max_len=0;

    cin >> A >> B;

    for(int i=0;i<=B.size()-A.size();i++){
        int cnt =0;
        for(int j=0;j<A.size();j++){
            if(A[j]==B[i+j]){
                cnt++;
            };
        };
        max_len = max_len > cnt ? max_len : cnt;
    };
    cout<< A.size()-max_len << endl;




}