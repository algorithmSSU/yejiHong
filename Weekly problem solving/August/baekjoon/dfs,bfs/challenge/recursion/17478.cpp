/*다시 이해하고 풀기..*/


#include <iostream>

using namespace std;

void text(int num, int line);
void bar(int num);

int main(){
    int n;
    cin >> n;

    text(n,0);

    return 0;
};


void text(int num,int line){

    string l = "";
    for(int i=0; i<line;i++){
        l += "____"; //4 칸
    };

    if(num==0){ // 종료조건
        cout << l << "재귀함수가 뭔가요 ?" << endl;

        cout << l << "재귀함수는 자기 자신을 호출하는 함수라네" << endl;

        cout << l << "라고 답변하였지." << endl;

        return;

    }else{ // 재귀 내용
        cout << l << "\"재귀함수가 뭔가요?\"\n";
        cout << l << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
        cout << l << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
        cout << l << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
        text(num - 1, line + 1);
        // num : 반복횟수를 줄여주고, line은  4개씩 늘려주어야 함.
        // num ==0 이 되면 종료
        cout << l << "라고 답변하였지.\n";
    };
};
