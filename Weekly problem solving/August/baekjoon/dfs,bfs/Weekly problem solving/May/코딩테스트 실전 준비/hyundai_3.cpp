/*

알고리즘 종류 : 문자열, 구현
난이도 : 초중
특징 : 1. string stl 을 좀더 확실히 해 둘 필요가 있을 듯 (erase, remove, find)
      2. 구현에 초점을 둔 문제라서, 어떻게 전체적으로 설계할지,어떤 자료구조를 사용할지, 빠르게 결정짓는것이 중요해보임


*/

#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
using std::stoi;

struct carinfo
{
    int start;
    int end;
    bool cut;
    string name;
    string kind;
    int mem_num;
};

int year[10][10] = {{196801, 198004}, {197512, 198201}, {197702, 200405}, {198607, 202305}, {199910, 199512}, {199406, 202305}, {199904, 200912}, {200006, 202305}, {200612, 202305}}; // 하나 빼먹은듯 ; 

string name[10] = {"Cortina", "Pony", "Porter", "Grandeur", "Elantra", "Aerotown", "Equus", "Santafe", "Tuscani", "Universe"};

bool cur[10] = {true, true, true, false, true, false, true, false, true, false};

string kind[10] = {"Sedan", "Sedan", "Truck", "Sedan", "Sedan", "Bus", "Sedan", "RV", "Coupe", "Bus"};
int mem[10] = {5, 5, 3, 5, 5, 30, 5, 7, 2, 45};

int main()
{
    vector<carinfo> v;
    vector<carinfo> ans;
    string answer;

    for (int i = 0; i < 10; i++)
    {
        carinfo ci;
        ci.start = year[i][0];
        ci.end = year[i][1];
        ci.name = name[i];
        ci.kind = kind[i];
        ci.cut = cur[i];
        ci.mem_num = mem[i];
        v.emplace_back(ci);
    };


    string input;
    int num;

    getline(cin, input, ' ');
    //cin.ignore();
    cin >> num;

    remove(input.begin(),input.end(),',');
    remove(input.begin(),input.end(),' ');
    

    int year = stoi(input);

    // 년도 확인, 인원 확인
    for (int i = 0; i < v.size(); i++)
    { // 년도
        if (v[i].start <= year && v[i].end >= year)
        {
            if (v[i].mem_num >= num)
            { // 인원
                ans.emplace_back(v[i]);
            }
        }
    }
    if (ans.size() == 0)
    {
        cout << "!" << endl;
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            if(ans[i].end<202205){
                answer+= ans[i].name+"*"+ "(" + ans[i].kind + ")";
            }else if(ans[i].end==202305){
                answer += ans[i].name + "(" + ans[i].kind + ")";
            }
            if(i<ans.size()-1){
                answer+=",";
            }
            
        }
    }

    cout << answer << endl;

    return 0;
}
