#include <iostream>
#include <vector>
using std::pair;
using namespace std;


int arr[15][15]={0,};
void fill();
int dp(int f, int r);

int main(){
    int n;
    vector <pair<int, int> > v;
    cin >> n;

    fill();
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    };

    for(int i=0;i<v.size();i++){
        cout << dp(v[i].first,v[i].second) << endl;
    }


    return 0;
    
}



void fill()
{
    for (int i = 0; i < 15; i++)
    {
        arr[0][i] = i;
    };
    for (int j = 0; j < 15; j++)
    {
        arr[j][1] = 1;
    }
}

int dp(int f, int r)
{
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }

    return arr[f][r];
}
