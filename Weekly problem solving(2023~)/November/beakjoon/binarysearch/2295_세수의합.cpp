#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<long long> v;
    vector<long long> v2;
    cin >> N;
    for(int i=0;i<N;i++){
        long long num;
        cin >> num;
        v.emplace_back(num);
    }
    //원본배열정렬
    sort(v.begin(),v.end());

    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            long long m = v[i]+v[j];
            v2.emplace_back(m);
        }
    }  

    // 값이 큰 v[i]부터 확인하기 때문에 발견을 하면 바로 출력하고 종료
    // v 배열은 정렬을 따로 안해도 되지만, 정렬을 하면 발견하자마자 (바로큰값으로) 종료할 수있음
    sort(v2.begin(),v2.end());// i+j 
    for(int i = N-1; i>0; i--){
        for(int j=0;j<i;j++){
            if(binary_search(v2.begin(),v2.end(),v[i]-v[j])){
                cout << v[i] << endl;
                return 0;
            }
        }
    }
    
}