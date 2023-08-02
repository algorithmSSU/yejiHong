#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;




// getline(cin, 입력받을변수) : 공백 제외하고 입력받음



int main(){
    int n;
    string input;
    vector<string> v;

    stack<char> st;

    cin >> n;
    cin.ignore(); // 버퍼 비우기
    while(n--){
        string word="";
        getline(cin, input); // 공백전까지만 받기// getlie(입력받을거다, 어디에?)
        input+=' ';// 맨 뒤에 공백을 추가해준다. 위에서 공백전까지만 받았고,
                    // 문자하나하나검사하면서 공백을 만나면 스택에 넣은걸 다시 다 빼줘야하기때문

        for(int i=0;i<input.length();i++){
            if(input[i]==' '){ // 공백이면
                while(!st.empty()){
                    word+= st.top();
                    st.pop();
                }
                word+=' ';
            }else{
                st.push(input[i]);
            }
        }v.push_back(word);
    }
    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }



}