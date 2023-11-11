#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> can={"aya", "ye", "woo", "ma"};

int solution(vector<string> b){
    int answer=0;


    int len = b.size();

    for(int i=0;i<len;i++){
        string cur = b[i];
        string temp;
        string before;
        for(int j=0;j<cur.size();j++){
            temp+=cur[j];
            auto it = find(can.begin(),can.end(),temp);
            if(it!=can.end()){
                if(before == *it){
                    break;
                }
                before = *it;
                temp.clear();
            }
        };
        if(temp.empty()){
            answer++;
        }
    }



    return answer;

}
int main(){
    int ans;
    vector<string> b = {"ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"};
    ans = solution(b);
    cout << ans << endl;


}