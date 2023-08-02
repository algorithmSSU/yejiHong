#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
using namespace std;
using std::stoi;

bool isdecimal(int num);
int solution(string text);
int main(){
    

    string text;
    cin >> text;
    cout << solution(text) << endl;

    return 0;
};

bool isdecimal(int num)
{
    if (num < 2)
    {
        return false;
    }
    int a = (int)sqrt(num);
    for (int i = 2; i <= a; i++)
    {
        if (num % i == 0)
        {
            return false;
        };
    };
    return true;
};

int solution(string text){
    vector<char> v;
    set<int> setnum;
    int answer = 0;

    for (int i = 0; i < text.length(); i++)
    {
        v.push_back(text[i]);
    };

    sort(v.begin(), v.end());

    do
    {
        string temp = "";
        int num;
        for (int i = 0; i < v.size(); i++)
        {
            temp += v[i];
            num = stoi(temp);
            //cout << num << endl;
            if(isdecimal(num)){
                setnum.insert(num);
            };
        };

    } while (next_permutation(v.begin(), v.end()));

    answer = setnum.size();
    return answer;
};

/*


#include <algorithm>

next_permutation(배열의 시작 주소, 배열의 끝 주소)
: next_permutation 함수는 순열을 구할 시작과 끝의 iterator 혹은
배열의 경우 시작과 끝의 주소를 입력받는다.
현재 탐색하고 있는 순열의 다음 순열을 구하고, true을 반환한다.
만약 다음 순열이 존재하지 않는다면 false를 반환.

예를 들어 v = {1,2,3} 이라는 벡터가 있을 때,

do{
    for(int i=0; i<v.size();i++){
        cout << v[i] << " ";
    };
    cout << "\n";

}while(next_permutation(v.begin(),v.end()));


-----> 시작이 배열의 처음~ 끝 까지 모든 경우의 수를 출력

*/