#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;

struct student{
    string name;
    int day;
    int month;
    int year;
};

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    stack<student> minimum;
    stack<student> maximum;
    

    int idx=0;
    while(n--){
        string name;
        int d, m, y;
        student st;
        cin >> name >> d >> m >> y;
        st.name = name;
        st.day= d;
        st.month = m;
        st.year = y;
        if(minimum.empty() && maximum.empty()){
            minimum.push(st);
            maximum.push(st);
        }else{
            //bool flag= true;
            // young
            if(minimum.top().year <st.year){
                minimum.pop();
                minimum.push(st);
            }else if(minimum.top().year<=st.year && minimum.top().month<st.month){
                minimum.pop();
                minimum.push(st);
            }else if(minimum.top().year<=st.year && minimum.top().month<=st.month && minimum.top().day<st.day){
                minimum.pop();
                minimum.push(st);
            }

            // old
            if(maximum.top().year >st.year){
                maximum.pop();
                maximum.push(st);
            }else if(maximum.top().year>=st.year && maximum.top().month>st.month){
                maximum.pop();
                maximum.push(st);
            }else if(maximum.top().year>=st.year && maximum.top().month>=st.month && maximum.top().day>st.day){
                maximum.pop();
                maximum.push(st);
            }
        };
        //cout << minimum.top().name << endl;
        //cout << maximum.top().name << endl;
    };


    cout << minimum.top().name << endl;
    cout << maximum.top().name << endl;
}