#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int solution(string numbers);
vector<char> numlist;

char nums[1000];

vector<string> list;
queue<string> make_decimal;
void dfs(string start);

int main(){
    string text;
    cin >> text;

    cout << solution(text) << endl;

    return 0;
};

int solution(string numbers){
    int answer;

    for (int i = 0;i<numbers.length();i++){
        string temp;
        int ntemp;
        ntemp = numbers[i] - '0';
        temp = to_string(ntemp);
        make_decimal.push(temp);
        list.push_back(temp);
    };

    for (int j = 0; j<list.size();j++){
        dfs(list[j]);
    }

    return 0;
};



void dfs(string start){

    vector<string> new_numbers;
    queue<string> decimal;
    decimal = make_decimal;
    string cur;
    string next;
    string new_num;
    cur = start;

    while(!decimal.empty()){
        next = decimal.front();
        decimal.pop();
        
        if(next==start){
            continue;
        };
        new_num = cur + next;
        new_numbers.push_back(new_num);
        cur = new_num;
        if (decimal.empty())
        {
            break;
        }
    };
    

    for (int i = 0; i < new_numbers.size(); i++)
    {
        cout << new_numbers[i] << endl;
    }
};
