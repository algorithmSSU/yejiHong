#include <iostream>
#include <string>
#include <vector>

using namespace std;

char * check;

void gocheck(vector<string>v){
    
    string text = v[0];

    if(v.size()==1){
        for(int i=0;i<text.length();i++){
            check[i] = text[i];
        };
        return;
    };

    for(int i=1;i<v.size();i++){
        for(int j=0;j<text.length();j++){
            if(v[i][j]==text[j] && check[j]!='?'){
                check[j]=text[j];
            }else{
                check[j]='?';
            }
        }
    }
}


int main(){
    int n;
    int size;
    vector<string> v;
    cin >> n;


    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        v.emplace_back(temp);
    };


    size = v[0].length();
    check = new char[size];

    gocheck(v);


    for(int i=0;i<size;i++){
        cout << check[i];
    }
    cout << endl;
    
}