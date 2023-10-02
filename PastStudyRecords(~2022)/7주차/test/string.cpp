#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using std::stoi;
using namespace std;
using std::find;
bool isminus(string text);
void min(string text);

int main()
{

    string text;
    cin >> text;
    string str;
    stack<int> number;
    queue<char> mix;

    int result;

    // 18+2+1-6-5-1
    // 18+2-1

    // 18,0,2,-1,1


    /*
    vector를 돌면서 원소가 -1이면 그 다음 인덱스 값에 *-1 을 해주고 더해줌
    */
    for (int i = 0; i < text.length();i++){
        mix.push(text[i]);
    };

    while(!mix.empty()){
        char temp;
        temp = mix.front();
        mix.pop();

        //str += temp;

        if(temp!='+'|| temp!='-'){
            str += temp;
        }

        if(temp=='+'){
            int num = stoi(str);
            number.push(num);
            number.push(0);
            str = "";
        };
        
        
        if(temp=='-'){
            int num = stoi(str);
            number.push(num);
            number.push(-1);
            str = "";
        };

        if(mix.size()==0){
            int num = stoi(str);
            number.push(num);
            str = "";
        }

    };
    int minus;

    /*
    while(!number.empty()){
        cout << number.top() << endl;
        number.pop();
    }*/

    while (!number.empty())
    {
        int cur = number.top();
        number.pop();
        if(cur==-1){
            result = result * -1;
            
        }
        else{
            result += cur;
            cout <<"result: " << result << endl;
        }
        
    };

    cout << result << endl;
};

void min(string text){
    string str;
    stack<int> number;
    queue<char> mix;

    int result;

    for (int i = 0; i < text.length();i++){
        mix.push(text[i]);
    };

    while(!mix.empty()){
        char temp;
        temp = mix.front();
        mix.pop();

        //str += temp;

        if(temp!='+'|| temp!='-'){
            str += temp;
        }

        if(temp=='+'){
            int num = stoi(str);
            number.push(num);
            number.push(0);
            str = "";
        };
        
        
        if(temp=='-'){
            int num = stoi(str);
            number.push(num);
            number.push(-1);
            str = "";
        };

        if(mix.size()==0){
            int num = stoi(str);
            number.push(num);
            str = "";
        }

    };
    int minus;

    /*
    while(!number.empty()){
        cout << number.top() << endl;
        number.pop();
    }*/

    while (!number.empty())
    {
        int cur = number.top();
        number.pop();
        if(cur==-1){
            result = result * -1;
            
        }
        else{
            result += cur;
            cout <<"result: " << result << endl;
        }
        
    };

    cout << result << endl;
};