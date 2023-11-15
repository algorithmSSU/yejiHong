#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


map<long long,int> numdict;
map<long long,int> :: iterator p;
int main(){

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        long long num;
        cin >> num;

        numdict[num]++;
    }

    //sort(numdict.begin(),numdict.end());

    long long MV=0;
    int Mx=-1;
    for(p=numdict.begin();p!=numdict.end();p++){
        if(Mx < p->second){
            MV = p->first;
            Mx = p->second;
        }
    }

    cout <<  MV << endl;

    


}