#include <iostream>
using namespace std;

char page[101][101] ={'c',};

void make_star(int n);
void make_star(int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            page[i][j]='*';
        };
    };


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(page[i][j]!='*'){
                cout << ' ';
            }else{
                cout << '*';
            }
        };
        cout << "\n";
    }
}

int main(){

    int n;
    cin >> n;

    make_star(n);

    return 0;
}