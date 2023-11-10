#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int solution(vector<int> ingredient){

    string patty = "1231";
    string g;

    int answer =0;
    int gi =0;
    int pi =0;

    for(int i=0;i<ingredient.size();i++){
        g+=ingredient[i]+'0';
        // 맨 뒷부분과 같다면

        cout << g << endl;
        if(g[i] ==patty[patty.length()-1]){
            // patty 랑 확인할 수 있을 만큼 크기가 더 크다면
            if(g.size() >= patty.size()){
                gi = i;
                pi = patty.size()-1;
                int same = 0;
                for(int k=0;k<patty.size();k++){
                    if(g[gi] == patty[pi])
                    gi--;
                    pi--;
                    same++;
                }
                if(same == patty.size()){
                    for(int d=0;d<same;d++){
                        g.pop_back();
                    }
                    answer++;
                }
            }
        }
    }

    cout << g << endl;
    return answer;

}


int main(){
    vector<int> ig = {2, 1, 1, 2, 3, 1, 2, 3, 1};
    int answer = solution(ig);

    cout << answer << endl;

    
}