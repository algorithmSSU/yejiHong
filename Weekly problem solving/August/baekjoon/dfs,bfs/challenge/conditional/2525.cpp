#include <iostream>

using namespace std;

int main(){
    int t, m, need;
    int result_time, result_minute;

    cin >> t >> m;
    cin >> need;

    int temp = m + need;
    if(temp>=60){
        int over_t, over_m;
        over_t = temp / 60;
        over_m = temp % 60;
        result_time = t + over_t;
        if(result_time >=24){
            result_time = result_time - 24;
        }
        result_minute = over_m;
    }else{
        result_time = t;
        result_minute = temp;
    };

    cout << result_time << " " << result_minute << endl;
};