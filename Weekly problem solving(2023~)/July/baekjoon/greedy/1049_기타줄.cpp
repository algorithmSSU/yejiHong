#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    int answer =0;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    vector<int> pack;
    vector<int> piece;

    for(int i=0;i<m;i++){
        int p1, p2;
        cin >> p1 >> p2;
        pack.emplace_back(p1);
        piece.emplace_back(p2);
    }

    sort(pack.begin(),pack.end());
    sort(piece.begin(), piece.end());


    int case1, case2, case3;
    
    if(n>=6 && n%6!=0){
        int tep = n/6;
        case1 = (tep + 1) * pack.front();
        //cout << "case1 :" << case1 << endl;
    }else if(n<6){
        case1 = 1 * pack.front();
    }else if(n>=6 && n%6==0){
        case1 = n/6+1 * pack.front();
    };
    
    case2 = n/6*pack.front() + n%6*piece.front();
    case3 = n*piece.front();
    
    answer = min(case1,case2);
    answer = min(answer,case3);


    cout << answer << '\n';


}
