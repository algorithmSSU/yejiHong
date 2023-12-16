#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N,M; // 각 배열의 길이(단어갯수), 교환 횟수 M

map<string,int> A;
map<string,int> B;

void input(){
    for(int j=0;j<2;j++){
        for(int i=0;i<N;i++){
            string temp;
            cin >> temp;
            if(j==0){
                A[temp]++;
            }else if(j==1){
                B[temp]++;
            }
        }
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> M;

    input();

    for(int i=0;i<M;i++){
        string ta, tb;
        cin >> ta >> tb;

        auto ita = A.find(ta);
        auto itb = B.find(tb);

        if(ita->first == ta && itb->first ==tb){
            // 둘다 가지고 있는 경우에
            if(ita->second>=1 && itb->second >=1){
                ita->second--;
                itb->second--;
                A[tb]++;
                B[ta]++;
            }
        }
    }



    for(auto it : A){
        if(it.second==1){
            // 1이면 있다는거, 0이면 없다는 거
            cout << it.first << " "; 
        }
    }

    

	
}