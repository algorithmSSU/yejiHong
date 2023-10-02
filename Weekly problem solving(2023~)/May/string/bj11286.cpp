#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>


using namespace std;

struct  comp
{
    bool operator()(int a, int b){
        if(abs(a)==abs(b)){
            return a>b;
        }else{
            return abs(a) > abs(b);
        }
    };
};

void solution(int n){
    priority_queue<int,vector<int>,comp> pq;

    while(n--){
        int num;
        cin >> num;

        if(num==0){
            if(pq.empty()){
                cout << 0 << '\n';
            }
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }else{
            pq.push(num);
        }
    }
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    solution(n);
    
    return 0;
}

