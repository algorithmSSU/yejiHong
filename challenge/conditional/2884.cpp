#include <iostream>

using namespace std;

void alarm(int T, int M);

int main(){

    int Time, Minute;
    cin >> Time >> Minute;

    alarm(Time, Minute);
    return 0;
};

void alarm(int T, int M){
    int result_time;
    int temp = M - 45;
    int result_minute;

    if(temp<0){
        result_minute = 60 + temp;
        result_time = T - 1;
        if(result_time==-1){
            result_time = 23;
        }
    }else{
        result_minute = temp;
        result_time = T;
    };

    cout << result_time << " " << result_minute << endl;
};