#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;


string isPallidrom(string s){
    

    string answer;
    int left = 0;
    int right = s.length()-1;
    int same = 0;

    while(left < right && s[left] == s[right]){
        same++;
        left++;
        right--;
    }

    // if(s[left]==s[right]){
    //     return "Yes";
    // }

    if(same == s.length()/2){
        return "Yes";
    }

    return "No";
    

}

int main(){
    vector<string> ans;
    cin >> N;
    cin.ignore();

    while(N--){
        string str;
        cin.clear(); // 이거뭔지 제대로 알아두기 -> 객체 내부 상태 초기화
        getline(cin,str);
        
        for(int k=0;k<str.size();k++){
            str[k]=tolower(str[k]);
        }



        string temp = isPallidrom(str);
        ans.emplace_back(temp);
    }

    for(auto it : ans){
        cout << it << endl;
    }

    
}