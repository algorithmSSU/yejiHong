#include <iostream>
#include <vector>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int map[301][301]={0,};
    int row,col = 0;
    int line = 0;
    vector<int> answer;
    vector<pair<int,int> > cd;

    cin >>row >> col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> map[i][j];
        }
    };

    cin >> line;
    while(line--){
        int y1,x1,y2,x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1-=1;
        x1-=1;
        y2-=1;
        x2-=1;
        cd.emplace_back(y1,x1);
        cd.emplace_back(y2,x2);
    };


    for(int i=0;i<cd.size();i=i+2){
        int sum = 0;
        for(int y = cd[i].first; y <= cd[i+1].first;y++){
            for(int x = cd[i].second; x<=cd[i+1].second;x++){
                sum+=map[y][x];
            };
        };
        answer.emplace_back(sum);
    };

    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }
    
    
}