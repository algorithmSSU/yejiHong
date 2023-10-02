#include <iostream>
using namespace std;

int main(){

    
    string A,B;
    A = "koder";
    B = "topcoder";
    string::size_type n;// 체크변수
    n = B.find(A,0);
    if(n==string::npos){
        cout << "no exist" << endl;
    }else{
        cout << "exist" << endl;
    }

}