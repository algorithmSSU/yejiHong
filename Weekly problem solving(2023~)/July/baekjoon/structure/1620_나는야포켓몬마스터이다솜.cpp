#include <iostream>
#include <vector>
#include <map>
#include <string>
using std::stoi;
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    vector<string> answer;
    cin >> n >> m;

    map<string,int> dict;
    string name[100001];

    for(int i=0;i<n;i++){
        string text;
        cin >> text;
        dict[text] = i + 1;
        name[i+1]=text;
    };

    for(int j=0;j<m;j++){
        string input;
        cin >> input;
        if(input[0]-'0'<10){
            int temp = stoi(input);
            answer.emplace_back(name[temp]);

        }else{
            int temp = dict[input];
            answer.emplace_back(to_string(temp));
        }
    }
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }



    
}