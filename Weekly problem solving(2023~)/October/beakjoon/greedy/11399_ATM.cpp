#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int,int> > P;


void input(){
    cin >> N;
    for(int i=1;i<=N;i++){
        int p;
        cin >> p;
        P.emplace_back(p,i);
    }

    sort(P.begin(),P.end());
}

int sol(){
    int res=0;
    int result=0;
    for(int i=0;i<P.size();i++){
        res+=P[i].first;
        result+=res;
    }
    return result;
}
int main(){
    ios_base::sync_with_stdio(false);
    int answer = 0;
    input();
    answer = sol();
    cout << answer << endl;

}