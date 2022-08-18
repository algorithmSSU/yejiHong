#include <iostream>
#include <vector>


using namespace std;
using std::pair;



vector<int> findparent(vector<pair<int,int>> arr);

int n;
vector<pair<int, int>> v;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n;i++){
        int first, second;
        cin >> first >> second;
        v.push_back(make_pair(first, second));
    }
};

vector<int> findparent(vector<pair<int, int>> arr){
    vector<int> p(n);

    
    
};