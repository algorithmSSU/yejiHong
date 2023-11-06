#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    int T;
    int test_case;
    cin >> T;

    vector<int> answer;
    string a, b;

    for(test_case=1;test_case<=T;++test_case){
        cin >> a >> b;
        int cnt =0;
        for(int j=0;j<a.length();j++){
            if(a[j]!=b[j])
                cnt++;
        }
        cout << "Hamming distance is " << cnt << "." << endl; 
    }

    
}