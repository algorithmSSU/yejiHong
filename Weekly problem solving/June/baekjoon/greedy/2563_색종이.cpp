#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
    int answer = 0;
    int n;
    cin >> n;
    vector<pair<int, int> > cd;

    int paper[100][100]={0,};

    for(int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        cd.emplace_back(x,y);
    };

    int cnt = 0;
    for(int j=0;j<cd.size();j++){
        for(int k = cd[j].second; k<cd[j].second+10; k++){
            for(int t = cd[j].first; t<cd[j].first+10;t++){
                if(paper[k][t]==0){
                    paper[k][t] = 1;
                    cnt++;
                }
            }
        }
    };

    cout << cnt << endl;
}