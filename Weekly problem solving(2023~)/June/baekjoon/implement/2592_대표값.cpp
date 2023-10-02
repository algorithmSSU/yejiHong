#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    
    map<int,int> m;
    map<int,int>::iterator p;

    int avg= 0;
    for(int i=0;i<10;i++){
        int temp;
        cin >> temp;
        avg+=temp;
        m[temp]++;
    };

    int frq= 0;
    int frquent = 0;
    for(p=m.begin();p!=m.end();p++){
        if(frq<p->second){
            frq = p->second;
            frquent = p->first;
        }
    };

    cout << avg/10 << '\n' << frquent << endl;





}