#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main(){
    vector<int> v;
    stack<int> s;
    stack<int> s2;

    int n;
    cin >> n;

    for(int i =0;i<n;i++){
        int num;
        cin >> num;
        v.emplace_back(num);
    };
    long long int count =0;
    for(int i=0;i<n;i++){
        if(s.empty()){
            s.push(v[i]);
        }else{
            if(s.top()>v[i]){
                s.push(v[i]);
                count += s.size()-1;
            }else{
                
                while(!s.empty() && s.top()<=v[i]){
                    s.pop();
                };
                
                s.push(v[i]);
                count+=s.size()-1;
            }
        }

    }
    cout << count << endl;


}