#include <iostream> 
#include <string> 
#include <vector> 
#include <sstream> 
#include <regex> 
#include <map> 
using std::pair; 
using namespace std; 
 
vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{ 
    vector<int> answer; 
    map<string, int> t_map; // type 별 매핑 
    vector<pair<string, string>> p; 
 
    // type 별 개월 수 맵핑 
    for (int i = 0; i < terms.size(); i++) 
    { 
        string type, month_temp; 
        stringstream ss(terms[i]); 
        ss >> type >> month_temp; 
        int month = stoi(month_temp); 
        t_map.insert({type, month}); 
    }; 
 
    /* 디버깅 
    map<string, int>::iterator p; 
    for (p = t_map.begin(); p != t_map.end();p++){ 
        cout << p->first << " " << p->second << endl; 
    };*/ 
 
    for (int j = 0; j < privacies.size(); j++) 
    { 
        string date, type; 
        stringstream ss(privacies[j]); 
        ss >> date >> type; 
        p.emplace_back(date, type); 
    }; 
 
    vector<string> check_date; 
    vector<vector<int>> cd; 
 
    for (int r = 0; r < p.size(); r++) 
    { 
        string t, d, m, y, da; 
        int value, month, year, day; 
        d = p[r].first; 
        t = p[r].second; 
        m = d.substr(5, 2); 
        y = d.substr(0, 4); 
        da = d.substr(8, 2); 
        month = stoi(m); 
        year = stoi(y); 
        day = stoi(da); 
 
        value = t_map[t]; 
 
        month += value; 
        if (month >= 12) 
        { 
            int temp; 
            temp = month / 12; 
            year += temp; 
            month = month % 12; 
        }; 
        // 
        da = to_string(day); 
        m = to_string(month); 
        y = to_string(year); 
 
        if (m.size() == 1) 
        { 
            m = "0" + m; 
        }; 
        if (da.size() == 1) 
        { 
            da = "0" + da; 
        } 
 
        string new_set; 
        new_set += y + " " + m + " " + da; 
        check_date.emplace_back(new_set); 
 
        // cout << new_set << endl; 
    }; 
 
    string y, m, d; 
    y = today.substr(0, 4); 
    m = today.substr(5, 2); 
    d = today.substr(8, 2); 
 
    int Y, M, D; 
    Y = stoi(y); 
    M = stoi(m); 
    D = stoi(d); 
 
    /*for (int i = 0; i < check_date.size();i++){ 
        cout << check_date[i] << endl; 
    }*/ 
 
    for (int i = 0; i < check_date.size(); i++) 
    { 
        string x, y, z; 
        int a, b, c; 
 
        // cout << check_date[i] << endl; 
 
        x = check_date[i].substr(0, 4); 
        y = check_date[i].substr(5, 2); 
        z = check_date[i].substr(8, 2); 
 
        a = stoi(x); 
        b = stoi(y); 
        c = stoi(z); 
 
        if (Y > a) 
        { 
            answer.push_back(i + 1); 
        } 
        else if (Y == a) 
        { 
 
            if (M >= b && D >= c) 
            { 
                answer.push_back(i + 1); 
            } 
            else if (M > b) 
            { 
                answer.push_back(i + 1); 
            } 
            else 
            { 
                continue; 
            }; 
        }; 
    }; 
 
    return answer; 
}; 
 
int main(){ 
 
    string today = "2020.01.01"; 
    vector<string> terms = {"A 6", "B 12", "C 3"}; 
    vector<string> terms2 = {"Z 3", "D 5"}; 
    vector<string> privacies = {"2021.05.02 A", "2021.07.01 B", 
                                "2022.02.19 C", "2022.02.20 C"}; 
    vector<string> privacies2 = {"2019.01.01 D", "2019.11.15 Z", 
                                "2022.08.02 D", "2019.07.01 D","2018.12.28 Z"}; 
 
    vector<int> ans; 
 
    ans = solution(today, terms2, privacies2); 
 
    for (int i = 0; i < ans.size();i++){ 
        cout << ans[i] << " "; 
    }; 
 
};