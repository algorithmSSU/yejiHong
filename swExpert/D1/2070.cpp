#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int test_case;
	int T;
    vector<char> answer;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
	{
        int a, b;
        cin >> a >> b;
        if(a>b){
            answer.emplace_back('>');
        }else if(a<b){
            answer.emplace_back('<');
        }else if(a==b){
            answer.emplace_back('=');
        }	
	}

    int tag = 1;
    for(auto it : answer){
        cout << "#" << tag++ << " " << it << '\n';
    }
	return 0;//정상종료시 반드시 0을 리턴해야한다.



}