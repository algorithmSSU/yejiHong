#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/**
 * 이 문제는 해당 수가 3의 배수임을 알기 위한 공식을 알아야 풀수 있다.
 * 일단 30의 배수니까 어떻게 하든 끝의 자리가 0이여야 한다. 받은 숫자중에 0이 없으면 -1 출력 
 * 
 * 
 * ⭐️hint)해당 수의 모든 자릿수 합이 3의 배수가 되면 된다.
 * ex) 80875542 = 8+0+8+7+5+5+4+2 = 39 , 39는 3의 배수
 * 
 * 모든 자릿수의 합이 3의 배수가 되고 && 0이 포함되어 있으면
 * 숫자를 내림차순하여 차례대로 더해주면 (맨 마지막에 0이 가겠지)
 * 30의 배수을 구할 수 있다.
 * 
 * 
 * 
*/
bool compare(int a,int b){
    return a>b;
}
int main(){

    string input;
    vector<int> numbers;
    cin >> input;

    int sum = 0;
    bool flag_zero= false;
    for(int i=0;i<input.length();i++){
        int n = input[i]-'0';
        numbers.emplace_back(n);
        sum+=n;
        if(n == 0){
            flag_zero=true;
        }
    }

    if(!flag_zero){
        cout << -1 << endl;
        return 0;
    }

    if(sum%3!=0){
        cout << -1 << endl;
        return 0;
    }

    sort(numbers.begin(),numbers.end(),compare);

    string answer;
    for(auto it : numbers){
        answer+=it+'0';
    }

    cout <<answer << endl;

}