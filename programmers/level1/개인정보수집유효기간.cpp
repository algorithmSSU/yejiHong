#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <map>
#include <string.h>
using namespace std;
using std::stoi;


// 약관종류에 따라 개인정보수집일자별로 총 기간을 계산
vector<int> cal(map<string,int> m,string today,vector<string> privacies){


    vector<int> answer;
    vector<string> new_p;

    
    for(int i=0;i<privacies.size();i++){
        int nyear,nmonth,nday;
        int effect;
        string str_y,str_m,str_d;

        map<string, int>::iterator ptr;
        
        for (ptr = m.begin(); ptr != m.end(); ptr++)
        {
            if(privacies[i].substr(11,1)==ptr->first){
                effect=ptr->second;
                break;
            }
        };
        
        nyear = stoi(privacies[i].substr(0,4));
        nmonth = stoi(privacies[i].substr(5,2));
        nday = stoi(privacies[i].substr(8,2));

        int temp = nyear*12*28+(nmonth-1)*28+nday+(effect * 28 -1); // 총  기간 계산해주는 부분
        answer.push_back(temp);
    };
    return answer;
}



// 약관종류에 따른 유효기간을 map 자료 구조로 만들기
map<string, int> makemap(vector<string> terms)
{
    map<string, int> m;

    for (int i = 0; i < terms.size(); i++)
    {
        string c, date;
        int month;

        c = terms[i].substr(0, 1);
        date = terms[i].substr(2);
        month = stoi(date);
        m.insert({c, month});
    }


    return m;
}


// input data 접근하면서 위에서 정의한 함수들 절차적 수행
vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    vector<int> v;

    map<string,int> ma;

    int year,month,day,total;
    year = stoi(today.substr(0, 4));
    month = stoi(today.substr(5, 2));
    day = stoi(today.substr(8, 2));
    total = year * 12 * 28 + (month - 1) * 28 + day;

    ma = makemap(terms); 

    v=cal(ma,today,privacies);

    
    for(int i=0;i<v.size();i++){
        if(v[i]<total){
            //cout << i+1 << " ";
            answer.push_back(i+1);   
        }
    }


    return answer;
};



int main(){
    string today;
    vector<string> terms = {"A 6", "B 12", "C 3"};
    vector<string> privacies = {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"};
    today = "2022.05.19";


    solution(today,terms,privacies);
    return 0;
}