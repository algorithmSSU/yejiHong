#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    int test_case;
    int T;
    
    cin >> T;

    for(test_case = 1; test_case<=T; ++test_case){
        if(test_case<=9){
            if(test_case%3==0){
                cout << "-" << " ";
            }else{
                cout << test_case << " ";
            }
        }else if(test_case>9){
            string str = to_string(test_case);
            int cnt = 0;
            for(int c=0;c<str.length();c++){
                if(str[c]=='3' || str[c]=='6' || str[c]=='9'){
                    cnt++;
                }
            }
            if(cnt!=0){
                for(int k = 0;k<cnt;k++){
                    if(k==cnt-1){
                        cout << "-" << " ";
                    }else{
                        cout << "-";
                    }
                }
            }else if(cnt==0){
                cout << str << " ";
            }
            
        }
    }

    return 0;

}