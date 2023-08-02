#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/*
재생시간
음계치환
타이틀추출

*/


string replaceall(string &m, string from, string to){
    int pos = 0;
    while((pos=m.find(from))!=-1){
        m.replace(pos, from.length(), to);
    };
    return m;
};

string solution(string m, vector<string> musicinfos)
{
    pair<int, string> ans = {0, ""};
    vector<string> result;

    string answer = "";

    /*음계치환*/
    replaceall(m, "A#", "a");
    replaceall(m, "B#", "b");
    replaceall(m, "C#", "c");
    replaceall(m, "D#", "d");
    replaceall(m, "E#", "e");
    replaceall(m, "F#", "f");
    replaceall(m, "G#", "g");


    /*재생시간구하기*/
    for (int i = 0; i < musicinfos.size();i++){
        int t = 0, idx = 0, pos = 0;
        string hour1, hour2, minutes1, minutes2, title = "", scale = "";

        hour1 = musicinfos[i].substr(0, 2);
        minutes1 = musicinfos[i].substr(3, 2);
        hour2 = musicinfos[i].substr(6, 2);
        minutes2 = musicinfos[i].substr(9, 2);
        t = abs(stoi(hour2) - stoi(hour1)) * 60;

        if(minutes1>minutes2){
            t -= 60;
            t += (stoi(minutes2) - stoi(minutes1)) + 60;
        }
        else{
            t += stoi(minutes2) - stoi(minutes1);
        }
        for (int j = 12;j<musicinfos[i].size();j++){
            if(musicinfos[i][j]==','){
                idx = j + 1;
                break;
            };
            title += musicinfos[i][j];
        };

        for (int j = idx; j < musicinfos[i].size();j++){
            scale += musicinfos[i][j];
        };
        replaceall(scale, "A#", "a");
        replaceall(scale, "B#", "b");
        replaceall(scale, "C#", "c");
        replaceall(scale, "D#", "d");
        replaceall(scale, "E#", "e");
        replaceall(scale, "F#", "f");
        replaceall(scale, "G#", "g");

        if(t/scale.size()>=1){// 재생시간 / 길이 >=1
            int a = (t / scale.size()) - 1;
            string temp = scale;
            for (int j = 0; j < a;j++){
                scale += temp;
            };
            for (int j = 0; j < t % temp.length();j++){
                scale += temp[j];
            }
            cout << scale << endl;
        }else{
            string temp = "";
            for (int j = 0; j < t;j++){
                temp += scale[j];
                scale = temp;
            }
        }
        idx = scale.find(m);
        if(idx!=-1 && ans.first<t){
            ans.first = t;
            ans.second = title;
        }
        
    };
    answer = ans.second;
    if(answer==""){
        answer = "(None)";
    }
    return answer;
};


int main(){

    string m = "ABC";
    vector<string> musicinfos;
    musicinfos.push_back("12:00,12:14,HELLO,C#DEFGAB");
    musicinfos.push_back("13:00,13:05,WORLD,ABCDEF");

    cout << solution(m, musicinfos) << endl;

    return 0;
}

