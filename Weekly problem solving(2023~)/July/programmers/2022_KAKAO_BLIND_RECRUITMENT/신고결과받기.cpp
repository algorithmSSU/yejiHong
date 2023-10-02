#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    // vector<string> dc[1001];
    //vector<map<string, int> > dc[1001];
    set<int> dc[1001];
    map<string, int> user;
    map<string, int> report_cnt;
    for (int i = 0; i < id_list.size(); i++)
    {
        user[id_list[i]] = i;
    };

    for (int i = 0; i < report.size(); i++)
    {
        string rp = "";
        int idx=0;
        for (int j = 0; j < report[i].length(); j++)
        {
            if (report[i][j]==' ')
            {
                idx = user[rp];
                rp = "";
                // dc[idx].emplace_back()
            }
            else if (report[i][j]=='\n')
            {
                dc[idx].insert(user[rp]);
            }
            else
            {
                rp += report[i][j];
            }
        }
    };

    set<int>::iterator p;
    for(int i=0;i<id_list.size();i++){
        for(p=dc[i].begin();p!=dc[i].end();p++){
            cout << *p << endl;
        }
    }

    return answer;
};

int main(){

    vector<string> ID = {"muzi", "frodo", "apeach", "neo"};
    vector<string> r = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    int k= 2;
    vector<int> ans;
    ans = solution(ID,r,k);

    
}