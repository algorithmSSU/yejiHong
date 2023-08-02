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

struct cond
{
    string dev;
    string pos;
    string career;
    string soulfood;
    int grade;
    cond(string d, string p, string c, string s, int g) : dev(d), pos(p), career(c), soulfood(s), grade(g){};
};

vector<personal> Information;
vector<string> str_info;
vector<pair<string, int>> infor;
vector<pair<string, int>> quer;
vector<cond> q;
vector<string> g;

vector<string> query_final;

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    for (int i = 0; i < info.size(); i++)
    {
        string temp;
        temp = info[i];

        int tmp = temp.length() - 3;
        string grade = temp.substr(tmp);
        temp.resize(temp.size() - 3);
        int g = stoi(grade);

        // cout << "info: " << temp << endl;
        infor.emplace_back(temp, g);
    }

    // sting,int 형식 제대로 들어갔는지 확인
    for (int i = 0; i < infor.size(); i++)
    {
        // cout << "infor info: "<< infor[i].first << endl;
    };

    // query에서 한줄씩 읽으면서 info에 찾는 값이 있는지 체크
    // 먼저 and랑 - 지우기

    vector<string> query_temp[10000];
    for (int j = 0; j < query.size(); j++)
    {
        string tmp;
        tmp = query[j];

        tmp = regex_replace(tmp, regex("[-]+"), "none");
        tmp = regex_replace(tmp, regex("and"), "");
        // tmp = regex_replace(tmp, regex("[ ]+"), " "); // 공백제거??

        int len = tmp.length() - 3;
        string grade = tmp.substr(len);
        int g = stoi(grade);
        // tmp.resize(tmp.size() - 3); //점수도 일단 string으로 받아서 나중에 처리
        // cout << tmp << " " << g << endl;

        stringstream ss(tmp);

        string a, b, c, d, e;
        ss >> a >> b >> c >> d >> e;

        query_temp[j].push_back(a);
        query_temp[j].push_back(b);
        query_temp[j].push_back(c);
        query_temp[j].push_back(d);
        query_temp[j].push_back(e);

        // quer.emplace_back(tmp, g);

        // query_temp.push_back(tmp);
    };

    // 28일에는 진짜 진자 마ㅜㅁ리류ㅠ유유ㅠ

    // infor에서 문장 전체 가져오고, 점수 가져와서
    // query에 있는 조건들과 비교, 점수 비교
    // infor 랑 query 조건과 점수가 맞으면 조건 인덱스에 count++ 해준다.
    // none 삭제?
    /* -> 안하는 이유? 점수는 int type으로 비교해주어야 하는데 포맷이 맞지 않으면 애매함...
    for(int i =0;i<query.size();i++){
        query_temp[i].erase(remove(query_temp[i].begin(), query_temp[i].end(), "none"), query_temp[i].end());
    };
    */

    // 아 count 왜 이상하게 되냐...
    int count = 0;
    int cnt_list[5] = {0, 0, 0, 0, 0}; // 크기 수정
    for (int i = 0; i < infor.size(); i++)
    {
        string info = infor[i].first;
        int grade = infor[i].second;
        for (int k = 0; k < query.size(); k++)
        {
            for (int j = 0; j < query_temp[i].size(); j++)
            {
                if (query_temp[k][j] == "none")
                {
                    continue;
                }
                else
                {
                    if (j < 4)
                    {
                        if (info.find(query_temp[k][j]) == string::npos)
                        {
                            break;
                        };
                    }
                    else if (j == 4)
                    {
                        int g = stoi(query_temp[k][j]);
                        if (g <= grade)
                        {
                            cnt_list[k]++;
                        }
                        else
                        {
                            break;
                        };
                    };
                };
            };
        }
    };
    vector<int>::iterator p;

    for (int i = 0; i < query.size(); i++)
    {
        answer.emplace_back(cnt_list[i]);
    };

    /*
        string,int 형식으로 잘 들어갔는지 확인용
        for (int i = 0; i < quer.size(); i++)
        {
            cout << "quer" << quer[i].first << quer[i].second << endl;
        };
    */

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