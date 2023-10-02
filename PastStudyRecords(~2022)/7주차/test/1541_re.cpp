#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
using std::invalid_argument;
using std::stoi;

void min(string t);
bool check(string t);
int main(){

    string text;
    cin >> text;

    min(text);
};


bool check(string t){
    for (int i = 0; i < t.length();i++){
        if(t[i]=='-'){
            break;
        };
        if(i==t.length()-1 && t[i]!='-'){
            return false;
        };
    };
    return true;
};

void min(string t){
    int front, back;
    int front_sum = 0;
    int back_sum = 0;
    int start = 0;
    int result;
    int index;
    int answer;
    string str;
    string front_str, back_str;
    vector<int> num_list;

    if(check(t)==true){
        // - index 찾기
    for (int i = 0; i < t.length();i++){
        if(t[i]=='-'){
            index = i;
            break;
        };
    };

    //cout << "index:" << index << endl;


    /*front*/
    for (int i = 0; i <= index;i++){
        char cur = t[i];

        //cout << cur << endl;


        if(cur!='+' || cur!='-'){
            str += cur;
        };
        if(cur=='+'||cur=='-'){
            int num = stoi(str);
            front_sum += num;
            str = "";
        };
    };
    //cout << front_sum << endl;
    str = "";

    /*back*/
    for (int j = index+1; j < t.length();j++)
    {
        char cur = t[j];

        //cout << cur << endl;

        if (cur != '+' || cur != '-')
        {
            str += cur;
        };
        if (cur == '+' || cur == '-')
        {
            int num = stoi(str);
            back_sum += num;
            str = "";
        };
        if(j==t.length()-1){
            int num = stoi(str);
            back_sum += num;
            str = "";
        }

        
    };
    cout << front_sum - back_sum << endl;
    return;


    };


    if(check(t)==false){
        for (int i = 0; i < t.length();i++){
            char cur = t[i];
            if (cur != '+' || cur != '-')
            {
                str += cur;
            };
            if (cur == '+' || cur == '-')
            {
                int num = stoi(str);
                back_sum += num;
                str = "";
            };
            if(i==t.length()-1){
                int num = stoi(str);
                back_sum += num;
                str = "";
            };
        };

        cout << back_sum << endl;
        return;
    };

    //cout << "back_sum:"<< back_sum << endl;



    
};


