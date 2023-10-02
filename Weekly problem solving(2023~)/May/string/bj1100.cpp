#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    
    int count=0;
    for(int i=0;i<8;i++){
        string text;
        cin >> text;

        if (i==0 || i%2==0){
            for(int j=0;j<text.length();j++){
                if(j==0 || j%2==0){
                    if(text[j]=='F'){
                        count++;
                    }
                }
            }
        }else{
            for(int j=0;j<text.length();j++){
                if(j%2==1){
                    if(text[j]=='F'){
                        count++;
                    }
                }
            }
        }   
    };

    cout << count << endl;



}