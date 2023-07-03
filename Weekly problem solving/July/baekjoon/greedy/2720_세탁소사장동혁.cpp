#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    vector<int> v;
    int answer[1000][1000]={0,};
    cin >> n;

    int cal[4] = {25,10,5,1};

    

    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        v.push_back(num);
    };

    for(int i=0;i<v.size();i++){
        int temp = 0;
        int cur = v[i];
        for(int a=0;a<4;a++){
            if(cur>=cal[a]){
                answer[i][a] = cur / cal[a];
                temp = cur - answer[i][a] * cal[a];
                //cout << temp << endl;
                cur= temp;
            }else{
                answer[i][a] = 0;
            }
        }
    };

    
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            cout << answer[i][j] << " ";
        };
        cout << '\n';
    }
    

}