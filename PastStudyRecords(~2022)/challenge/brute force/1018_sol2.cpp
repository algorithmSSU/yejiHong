#include <iostream>
using namespace std;
#include <algorithm>
int matrix[51][51];

int bw[8][8];
int wb[8][8];

int check(int x, int y);

int main(){

    int n, m;
    int min_value = 2500;

    cin >> n >> m;

    /*matrix 입력받고*/

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if(c=='B'){
                matrix[i][j] = 1;
            }else{
                matrix[i][j] = 0;
            };
        };
    };


    /*black/white 정답지*/

    for (int i = 0; i < 8;i++)
    {
        for (int j = 0; j < 8;j++){
            if((i+j)%2==0){
                bw[i][j] = 0;
            }else if((i+j)%2==1){
                bw[i][j] = 1;
            };
        };
    };


    /*white/black 정답지*/

    for (int i = 0; i < 8;i++)
    {
        for (int j = 0; j < 8;j++){
            if((i+j)%2==0){
                wb[i][j] = 1;
            }else if((i+j)%2==1){
                wb[i][j] = 0;
            };
        };
    };

    /*Matrix와 정답지 두개를 비교하면서
    비교가 더 작은 정답지 카운트를 리턴*/
    int cnt1, cnt2;
    int Min = 99999;
    for (int x = 0; x <= n-8;x++){
        for (int y = 0; y <= m-8; y++){
            for (int i = 0; i < 8; i++){
                for (int j = 0; j < 8;j++){
                    if(matrix[i+x][j+y]!=wb[i][j]){
                        cnt1++;
                    }
                    if(matrix[i+x][j+y]!=bw[i][j]){
                        cnt2++;
                    };
                };
            };
            if (cnt1<cnt2){
                if(Min>cnt1){
                    Min = cnt1;
                };
            }else{
                if(Min >cnt2){
                    Min = cnt2;
                };
            };
            cnt1 = 0;
            cnt2 = 0;
        }
    }
    cout << Min-8;
    return 0;
};

