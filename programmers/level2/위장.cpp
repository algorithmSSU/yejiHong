#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
using std::pair;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;

    map<string, int> m;

    for (auto cloth:clothes){
        m[cloth[1]] += 1;
        /*

        //내가 짠거보다 훨씬 심플..
        m[key]+=value; 같은 key일 때 value ++;

        */
    }
    for (auto it = m.begin(); it != m.end();it++){
        answer *= it->second + 1;
    };
    return answer - 1;
}

int main()
{
    vector<vector<string>> c = {{"yellow_hat", "headgear"},
                                {"blue_sunglasses", "eyewear"},
                                {"green_turban", "headgear"}};

    vector<vector<string>> sample = {{"crow_mask", "face"},
                                     {"blue_sunglasses", "face"},
                                     {"smoky_makeup", "face"}};

    vector<vector<string>> sample2 = {{"crow_mask", "face"},
                                      {"blue_sunglasses", "face"},
                                      {"smoky_makeup", "face"},
                                      {"blue_sunglasses", "eyewear"},
                                      {"green_turban", "headgear"},
                                      {"yellow_hat", "eyewear"}};

    int ans = solution(sample2);
    cout << ans << endl;
};

/*

종류가 같으면 +1 해주고 저장

모든 종류에 +1 해주고 모든 값 곱해주기

(바지 수+1)*(상의 수+1)*(모자 수+1)
# +1은 착용하지 않았을 때의 경우의 수

*/