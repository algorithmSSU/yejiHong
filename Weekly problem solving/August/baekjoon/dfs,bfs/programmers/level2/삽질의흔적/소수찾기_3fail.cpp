#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <set>
using std::stoi;
using namespace std;

int solution(string numbers);
void dfs();
bool isdecimal(int num);


vector<int> numlist;
vector<string> new_numbers;
vector<string> list;
queue<string> make_decimal;
set<int> set_num;




int main()
{
    string text;
    cin >> text;
    cout << solution(text) << endl;
    return 0;
};

int solution(string numbers)
{
    int answer = 0;

    for (int i = 0; i < numbers.length(); i++)
    {
        string temp;
        int ntemp;
        ntemp = numbers[i] - '0';
        temp = to_string(ntemp);
        make_decimal.push(temp);
        list.push_back(temp);
    };
    
    dfs();

    for (int i = 0; i < numlist.size(); i++)
    {
        set_num.insert(numlist[i]);
        //cout << numlist[i] << endl;
    };
    answer = set_num.size();
    return answer;
};

bool isdecimal(int num){
    if(num<2){
        return false;
    }
    int a = (int)sqrt(num);
    for (int i = 2; i<=a;i++){
        if(num%i==0){
            return false;
        };
    };
    return true;
};
void dfs()
{
    queue<string> temp_queue;
    string cur;
    string next;
    string new_num;
    string nowcur;

    for (int i = 0; i < make_decimal.size();i++)
    {
        cur = make_decimal.front();
        nowcur = cur;
        new_numbers.push_back(cur);
        make_decimal.pop();
        temp_queue = make_decimal;
        new_num = "";
        next = "";
        while(!temp_queue.empty()){
            next = temp_queue.front();
            temp_queue.pop();
            //cout <<"next:" << next << endl;
            new_num = cur + next;
            new_numbers.push_back(new_num);
            cur = new_num;
        };
        make_decimal.push(nowcur);
    };

    for (int i = 0; i < new_numbers.size(); i++)
    {
        int num;
        num = stoi(new_numbers[i]);
        cout << num << endl;
        if(isdecimal(num)){
            numlist.push_back(num);
        }else{
            continue;
        };
    };
};

