// https://school.programmers.co.kr/learn/courses/30/lessons/72412

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>
#include <regex>
using namespace std;
using std::stoi;

vector<string> info = {"java backend junior pizza 150", "python frontend senior chicken 210",
                       "python frontend senior chicken 150", "cpp backend senior pizza 260",
                       "java backend junior chicken 80", "python backend senior chicken 50"};

vector<string> query = {
    "java and backend and junior and pizza 100",
    "python and frontend and senior and chicken 200",
    "cpp and - and senior and pizza 250",
    "- and backend and senior and - 150",
    "- and - and - and chicken 100",
    "- and - and - and - 150"};

struct personal
{

    string dev;
    string pos;
    string career;
    string soulfood;
    string grade;
    personal(string d, string p, string c, string s, string g) : dev(d), pos(p), career(c), soulfood(s), grade(g){};
};

vector<personal> Information;
vector<string> str_info;
vector<pair<string, int>> infor;
vector<pair<string, int>> quer;

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    for (int i = 0; i < info.size(); i++)
    {
        string temp;
        temp = info[i];

        string grade = temp.substr(temp.length() - 3);
        int g = stoi(grade);
        infor.emplace_back(temp, g);

        /*
            stringstream ss(temp);
            string a, b, c, d, e;
            ss >> a >> b >> c >> d >> e;
            personal p(a, b, c, d, e);
            Information.push_back(p);
            */
    }

    // sting,int 형식 제대로 들어갔는지 확인
    for (int i = 0; i < infor.size(); i++)
    {
        cout << infor[i].first << infor[i].second << endl;
    };

    // query에서 한줄씩 읽으면서 info에 찾는 값이 있는지 체크
    // 먼저 and랑 - 지우기

    vector<string> query_temp;
    for (int j = 0; j < query.size(); j++)
    {
        string tmp;
        tmp = query[j];

        tmp = regex_replace(tmp, regex("[ -]+"), "");
        tmp = regex_replace(tmp, regex("and"), "");

        string grade = tmp.substr(temp.length() - 3);
        query_temp.push_back(tmp);
    };

    //아왜똑같은거두개;;

    for (int j = 0; j < query_temp.size(); j++)
    {
        string temp = query_temp[j];
        temp = regex_replace(temp, regex("[ ]+"), "");
        string grade = temp.substr(temp.length() - 3);
        int g = stoi(grade);
        temp.resize(temp.size() - 3);
        quer.emplace_back(temp, g);
    };

    for (int i = 0; i < quer.size(); i++)
    {
        cout << "quer" << quer[i].first << quer[i].second << endl;
    };

    for (int r = 0; r < quer.size(); r++)
    {
        int c;
        string tmp;
        int tmpg;
        tmp = quer[r].first;
        tmpg = quer[r].second;

        for (int x = 0; x < infor.size(); x++)
        {
            string text = infor[x].first;
            if (tmp.find(text) != string::npos)
            {
                c++;
                answer.push_back(c);
            };
        }
    }
    return answer;
};

int main()
{
    vector<int> temp;
    temp = solution(info, query);

    for (int i = 0; i < temp.size(); i++)
    {
        cout << "temp:" << temp[i] << endl;
    }
};

/*
info 배열에서 string 를 각각 가져와서
공백으로 분리해서 개발언어, 직군, 경력, 소울푸드, 점수를
personal 구조체타입으로입력받고, Information 에 넣기

(-> 공백 분리가 관건)

query 배열에서도 string을 각각 가져와서
and와 공백으로 분리해서 개발언어, 직군, 경력, 소울푸드, 점수를
personal 구조체 타입으로 입력받고 Query에 넣음
(특히 - 는 해당 없음의 의미임)

(-> and와 공백으로 분리가 관건)


이제 Query 배열에 담긴 personal 구조체에서
5개의 정보를 변수에 저장하고,
Infromation 배열에서 personal 구조체에서 하나씩 값을 빼서
첫번째 변수부터 일치하는지 확인
만약 Query배열에 담긴 구조체에서 빼낸 변수값이 - 이면 다음 변수로 비교
-가 아닌 경우에서 일치하지않으면 바로 종료, 일치하면 그 다음 변수로 계속 확인



___________________________________________________________


vector<pair<string,int>> info; 생성

"java backend junior pizza 150" 끝에서 3글자만 떼어서
int grade= 150;
info.emplace_back(str,grade);
"java backend junior pizza",150 이런 형식으로 만들 것








*/