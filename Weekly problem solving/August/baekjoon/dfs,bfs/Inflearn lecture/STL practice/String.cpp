#include <iostream>
#include <string>

using namespace std;

int main(){
    string str = "It is time to study ";
    string res;
    int pos, max = INT_MIN;

    int len = INT_MIN;
    string lw="";
    while((pos=str.find(' '))!=string::npos){ // 공백이 맨 마지막 요소가 아닐 때 계속 반복
        string tmp = str.substr(0,pos); // 0번 인덱스부터 pos 개 만큼 가져와라
        int temp_len = tmp.length();
        if (len < temp_len) // string 길이는 unsigned int 라서 int type 이랑 숫자비교해주려면
                            // int type 으로 casting 해야함! 주의
        {
            len = temp_len;
            lw=tmp;
        }
        cout << tmp << " ";
        str=str.substr(pos+1); // pos+1 부터 끝까지 가져오는거
    }
    cout << "\n";
    cout << "The longest words: " << lw << endl;

    return 0;

}