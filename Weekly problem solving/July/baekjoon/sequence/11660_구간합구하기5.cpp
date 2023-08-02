#include <iostream>
#include <vector>


using namespace std;

int arr[1025][1025] = {
    0,
};
int linesum[1025][1025] = {
    0,
};

int main(){
    int n, m;
    vector<int> answer;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        int sum = 0;
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
            sum+=arr[i][j];
            linesum[i][j]=sum;
        }
    };

    for(int i=0;i<m;i++){
        int x1,y1,x2,y2;
        int res= 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j=x1;j<=x2;j++){
            res+=linesum[j][y2] - linesum[j][y1-1];
        };
        answer.emplace_back(res);
    };

    for(int i=0;i<answer.size();i++){
        cout << answer[i]<< '\n';
    }
    
    
    return 0;

}