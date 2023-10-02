#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

struct info{
    string name;
    int grade;
    int index;
};

// 비교함수
bool compare(const info &a, const info &b){
    if(a.grade==b.grade){
        return a.index < b.index;
    }
    return a.grade>b.grade;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int student, top;
    cin >> student >> top;

    vector<info> student_list;
    

    for(int i=0;i<student;i++){
        info st;
        string n;
        int g;
        cin >> n >> g;
        st.name = n;
        st.grade = g;
        st.index=i;
        student_list.push_back(st);
    };

    sort(student_list.begin(),student_list.end(),compare);

    for(int i=0;i <top;i++){
        cout << student_list[i].name << endl;
    }



}