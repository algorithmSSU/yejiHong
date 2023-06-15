// https://school.programmers.co.kr/learn/courses/30/lessons/72412


//테스트케이스만 성공, 제출 오류..

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


vector<pair<string, int>> infor;
vector<pair<string, int>> quer;

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

        //cout << "info: " << temp << endl;
        infor.emplace_back(temp, g);
    }

    // sting,int 형식 제대로 들어갔는지 확인
    for (int i = 0; i < infor.size(); i++)
    {
       
    };


    vector<string> query_temp[10000];
    for (int j = 0; j < query.size(); j++)
    {
        string tmp;
        tmp = query[j];

        tmp = regex_replace(tmp, regex("[-]+"), "none");
        tmp = regex_replace(tmp, regex("and"), "");

        int len = tmp.length() - 3;
        string grade = tmp.substr(len);
        int g = stoi(grade);

        stringstream ss(tmp);

        string a, b, c, d, e;
        ss >> a >> b >> c >> d >> e;

        query_temp[j].push_back(a);
        query_temp[j].push_back(b);
        query_temp[j].push_back(c);
        query_temp[j].push_back(d);
        query_temp[j].push_back(e);

    };




    int count = 0;
    int cnt_list[5] = {0, 0, 0, 0, 0}; // 크기 수정
    for(int i=0;i<infor.size();i++){
        string info = infor[i].first;
        int grade = infor[i].second;
        for (int k = 0; k < query.size();k++){
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

    for (int i = 0; i < query.size();i++){
        answer.emplace_back(cnt_list[i]);
    };


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


이제 Query 배열에 변수값이 - 이면 다음 변수로 비교
-가 아닌 경우에서 일치하지않으면 바로 종료, 일치하면 그 다음 변수로 계속 확인



___________________________________________________________


vector<pair<string,int>> info; 생성

"java backend junior pizza 150" 끝에서 3글자만 떼어서
int grade= 150;
info.emplace_back(str,grade);
"java backend junior pizza",150 이런 형식으로 만들 것








*/