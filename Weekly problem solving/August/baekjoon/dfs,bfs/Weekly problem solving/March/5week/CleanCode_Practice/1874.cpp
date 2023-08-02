#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define MAX 100000

void snum(int arr[],int size);

void snum(int arr[],int size){
    stack<int> st;
    vector<char> v;

    int arrp = 0;

    for(int i=1;i<=size;i++){
        if(i<=arr[arrp]){
            st.push(i);
            v.push_back('+');
        };
        if(st.top()==arr[arrp]){
            while(st.top()==arr[arrp]){
                st.pop();
                v.push_back('-');
                arrp++;
                if(st.size()==0){
                    break;
                };
            }
        };
    }
    if(st.size()!=0){
        cout << "NO"  << "\n";
    }else{
        for(int i=0;i<v.size();i++){
            cout << v[i] << "\n";
        }
    }
}


int main(){
    int n;
    int arr[MAX];
    vector<char> v;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];    
    };


    snum(arr,n);

}