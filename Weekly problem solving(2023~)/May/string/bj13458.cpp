#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<long long int> v;
    long long int n, super, sub, manager;
    long long int res;
    res = 0;

    cin >> n;

    for(int i=0;i<n;i++){
        long long int temp;
        cin >> temp;
        v.emplace_back(temp);
    }

    // 감독관, 부감독관
    cin >> super >> sub;


    for(int i=0;i<v.size();i++){
        long long int tt = v[i] - super; // 감독관은 1명만
        res++;
        if(tt>=sub){   
            res+=tt/sub;
            if(tt%sub!=0){
                res++;
            }
        }else if(tt>0){
            res++;
        }else{
            continue;
        }
    };

    cout << res << endl;
    
    return 0;
}