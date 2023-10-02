#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

struct student{
    string name;
    int a;
    int b;
    int c;
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<student> v;

    for(int i=0;i<n;i++){
        student s;
        string nam;
        int math,eng,sci;
        cin >> nam >> math >> eng >> sci;
        s.name = nam;
        s.a =math; s.b = eng; s.c = sci;
        v.emplace_back(s);
    }

    student smart;
    smart.a=0;
    smart.b=0;
    smart.c=0;
    smart.name = "yeji";
    for(int i=0;i<v.size();i++){
        smart = smart.a < v[i].a ? v[i] : smart;
    };

    



    int b_count = 1;
    int c_count = 1;
    for(int i=0;i<v.size();i++){
        if(smart.b<v[i].b){
            b_count++;
        };
        if(smart.c<v[i].c){
            c_count++;
        }
    };

    cout << smart.name << " " << b_count << " " << c_count << endl;




}