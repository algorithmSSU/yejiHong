#include <iostream>
#include <sstream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{

    // 공백 분리할 문자열 선언
    string input;
    cin >> input;

    // 문자열을 스트림화
    stringstream ss(input);

    // 공백 분리 결과를 저장할 배열
    vector<string> words;

    string word;
    // 스트림을 한 줄씩 읽어, 공백 단위로 분리한 뒤, 결과 배열에 저장

    int count=0;
    while (getline(ss, word, ' '))
    {
        words.push_back(word);
        if(word.find("love")!=string::npos){
            
            count ++ ;
        }
        cout << word << endl;
    }

    cout << count << endl;
}