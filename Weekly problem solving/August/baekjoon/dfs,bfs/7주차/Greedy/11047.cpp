#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> v;
int N;
int K;

void coin_min(int num);
int main(){

    
    cin >> N >> K;

    for (int i = 0; i < N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    };

    coin_min(K);
    
};

void coin_min(int num){
    int result;
    int count = 0; // runtime error의 원인..? 초기화 반드시 해주자 
    for (int i = N-1; i >= 0;i--){
        if(num==0){
            break;
        }
        if(num>=v[i]){
            result = num / v[i];//4200/1000 = 4
            //cout << "result:" << result << endl;
            count += result;
            num = num - result * v[i]; // 4200-4*1000 = 200
        }else{
            continue;
        }
    };

    cout << count << endl;
};