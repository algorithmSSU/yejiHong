#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>


using namespace std;
map<char,int> m;
char type[4][2]={{'R','T'},
                    {'C','F'},
                    {'J','M'},
                    {'A','N'}};

string solution(vector<string> servey, vector<int> choices){
    
    string result;
    for(int i=0;i<servey.size();i++){
        if(choices[i]>4){
            m[servey[i][1]]+=choices[i]-4;
        }else if(choices[i]<4){
            m[servey[i][0]]+=4-choices[i];
        }
    }

    for(auto it :type){
        if(m[it[0]] >= m[it[1]]){
            result+=it[0];
        }else{
            result+=it[1];
        }
    }
    return result;
}



int main(){

    vector<string> s = {"TR", "RT", "TR"};
    vector<int> c = {7,1,3};


    string answer;
    answer = solution(s,c);
    cout << answer << endl;

}