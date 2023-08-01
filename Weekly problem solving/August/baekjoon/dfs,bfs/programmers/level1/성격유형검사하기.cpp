#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <cstdlib>
using std::pair;
using namespace std;

/*

R T
C F
J M
A N

*/

/*

☝️ 코드 작성할 때 유의하자
1. 풀이 절차에 따라 필요 기능 분류
2. 기능 함수화(비슷한 유형,반복작업은 무조건 함수화)
3. 문제에서 주어진 데이터를 가지고 함수 호출로 기능이 실행되게끔


<문제 풀이 요약>
- choices(선택답안) 로 주어진 번호가 4이상이면 survey(설문)으로 답한 유형 중
1번째 인덱스의 유형으로 점수가 부여

- choices(선택답안)이 4인 경우 0번째와 1번째 인덱스 모두 0점으로 부여(0으로 초기화해놓은 경우 처리할 필요x)
- 따라서 이 때 실제 점수는 choices(선택답안)-4 를 한 값으로,
  음수가 나오면 절대값으로 바꿔주어서 해당하는(현재 인덱스) 성격유형에 점수를 더해준다.
  양수가 나오면 그대로 해당하는(현재 인덱스) 성격유형에 점수를 더해준다.


* 어떤 유형에 점수를 줄 것인지 고르기
-> choices 에서 5,6,7이면 1번째 인덱스 유형에 점수 부여
   choices 에서 1,2,3이면 0번째 인덱스 유형에 점수 부여

* 실제 점수 계산하기
-> 실제 점수는 choices(선택답안)-4 한 값으로 계산


* 유형별로 점수 다 기록 후 맨 마지막 merge
-> 유형별로 점수가 기록된 배열을 돌면서, 같은 행일때 더 크거나 같은 경우 그 유형이 출력




*/


// 성격 유형 검사지는 지표별로 타입이 구분되어 있음
// 답지 틀을 구조체나 클래스로 만들어놓고 시작
struct mbti{
    char arr [4] = {' ',' ',' ',' '};

    int marks[4][2] ={0,};

    char type[4][2]={
        {'R','T'},
        {'C','F'},
        {'J','M'},
        {'A','N'}
        };
};

// score 환산
int choice_check(int num){ 
    int answer= 0;
    int temp;
    temp = num-4;
    if(temp<0){
        int t;
        t = abs(temp);
        answer=(int)t;
    }
    if(temp>0){
        answer=temp;
    }

    return answer;
};

// mbti type별 score 저장
void seek(mbti &m, string t, int c) 
{
    int score = 0;
    char a, b;
    a = t[0];
    b = t[1];
    score = choice_check(c);

    if (c > 4)
    {
        for(int i=0;i<4;i++){
            for(int j=0;j<2;j++){
                if(m.type[i][j]==b){
                    m.marks[i][j]+=score;
                }
            }
        }
        
    };
    if (c < 4)
    {
        for(int i=0;i<4;i++){
            for(int j=0;j<2;j++){
                if(m.type[i][j]==a){
                    m.marks[i][j]+=score;
                }
            }
        }
        
    }
}

// 주어진 input data에 인덱스로 접근하면서 위에서 정의한 함수 호출로 문제 해결
string solution(vector<string> survey, vector<int> choices)
{
    string str;
    mbti mb;
    str ="";
    
    
    for(int i=0;i<choices.size();i++){
        seek(mb,survey[i],choices[i]);
    };

    for(int i=0;i<4;i++){
        if (mb.marks[i][0] == mb.marks[i][1])
        {
            str+= mb.type[i][0];
        }
        if(mb.marks[i][0] > mb.marks[i][1]){
            str+=mb.type[i][0];
        }
        if (mb.marks[i][0] < mb.marks[i][1])
        {
            str+= mb.type[i][1];
        };
        
    }

    return str;

};




int main(){


    vector<string>s;

    s.push_back("AN");
    s.push_back("CF");
    s.push_back("MJ");
    s.push_back("RT");
    s.push_back("NA");

    
    vector<int> c;
    c.push_back(5);
    c.push_back(3);
    c.push_back(2);
    c.push_back(7);
    c.push_back(5);

    string str="";

    str = solution(s,c);
    cout << str << endl;
    


}