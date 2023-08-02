#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
using std::pair;

int solution(vector<vector<string>> clothes)
{
    int answer = 0;
    map<string, int> m;
    int size = clothes.size();
    int cnt = 1;
    for (int i = 0; i < size;i++){
        if(m.find(clothes[i][1])!=m.end()){
            cnt++;
            m[clothes[i][1]] = cnt;
        }else{
            m.insert(pair<string,int> (clothes[i][1], 1));
        };
    };
    int temp = 1;
    for (auto it = m.begin(); it != m.end();it++){
        cout << it->first << ":" << it->second << " ";
        temp = temp * it->second;
    };

    int count = 0;
    for(auto it = m.begin(); it!=m.end();it++){
        count += it->second;
    };

    if(m.size()>1){
        answer = temp + count;
    }else{
        answer = temp;
    }

    cout << "\n";

    //answer = m.size();
    return answer;
}

int main(){
    vector<vector<string>> c = {{"yellow_hat", "headgear"},
                                {"blue_sunglasses", "eyewear"},
                                {"green_turban", "headgear"}};

    vector<vector<string>> sample = {{"crow_mask", "face"},
                                {"blue_sunglasses", "face"},
                                {"smoky_makeup", "face"}};

    int ans = solution(c);
    cout << ans << endl;
};