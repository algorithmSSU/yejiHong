#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    

    int T;
    int test_case;
    vector<int> answer;


    cin >> T;
    
    map<char,int> alphabet;
    for(int i= 65; i<=88; i++){
        alphabet[i]=0;
    };

    // map<char,int>::iterator p;
    // for(p=alphabet.begin(); p!=alphabet.end(); p++){
    //     cout << p->first << endl;
    // }


    for(test_case = 1; test_case <= T; ++test_case){
        string str;
        cin >> str;

        int size = str.length();
        string temp = "";

        for(int i=0; i<size; i++){
            if(!temp.empty() && temp.front() == str[i]){
                int temp_size = temp.size();
                int ci = i;
                int same = 0;
                for(int k=0;k<temp_size;k++){
                    if(temp[k] == str[ci++]){
                        same++;
                    }
                }
                if(same == temp_size){
                    answer.emplace_back(same);
                    break;
                }else{
                    temp+=str[i];//temp에 문자하나하나 더해줌
                }
            }
            else{
                temp+=str[i];// temp 에 문자하나하나더해줌
            }
        }
    }
    int tag = 1;
    for(auto it : answer){
        cout << "#" << tag++ << " " << it << endl;
    }
}