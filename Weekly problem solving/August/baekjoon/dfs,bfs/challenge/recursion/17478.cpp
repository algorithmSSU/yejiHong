/*�ٽ� �����ϰ� Ǯ��..*/


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
        l += "____"; //4 ĭ
    };

    if(num==0){ // ��������
        cout << l << "����Լ��� ������ ?" << endl;

        cout << l << "����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����" << endl;

        cout << l << "��� �亯�Ͽ���." << endl;

        return;

    }else{ // ��� ����
        cout << l << "\"����Լ��� ������?\"\n";
        cout << l << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
        cout << l << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
        cout << l << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
        text(num - 1, line + 1);
        // num : �ݺ�Ƚ���� �ٿ��ְ�, line��  4���� �÷��־�� ��.
        // num ==0 �� �Ǹ� ����
        cout << l << "��� �亯�Ͽ���.\n";
    };
};
