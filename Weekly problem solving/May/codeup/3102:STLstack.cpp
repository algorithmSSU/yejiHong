#include <iostream>
#include <stack>
#include <string.h>
#include <sstream>
#include <math.h>
using namespace std;

stack<int> s;
void solution(char code,string o){
    int position = 0;
    int hund, ten, won;


    string st;
    for(int i=6;i<o.length();i++){
        if(o[i]==' '){
            break;
        }else{
            position++;
            st+=o[i];
        }
    };

    int num = 0;
    if(position==3){
        for(int i=2;i>0;i--){
            num+=int(st[i])*pow(10,i);

        }
    }else if(position ==2){
        for(int i =2;i>0;i--){
            num+=int(st[i])*pow(10,i);
        }
    }else if(position==1){
        for(int i=1;i>0;i--){
            num+=int(st[i]*pow(10,i));
        };
    };
    


    if(code == 'A'){
        s.push(num);
    }else if(code == 'B'){
        cout << s.top();
    }else if(code == 'C'){
        s.pop();
    }else if(code =='D'){
        cout << s.size() << endl;
    }else if(code=='E'){
        if(!s.empty()){
            cout << "True" << endl;
        }else{
            cout << "False" << endl;
        }
    }
}




int main(){
    int n;
    stack<int> s;
    cin >> n;
    cin.ignore();

    while(n--){
        string command;
        getline(cin,command,'\n');
        cin.ignore();

        if (command.find("push") != string::npos)
        {
            solution('A', command);
        }
        else if (command.find("top") != string::npos)
        {
            solution('B', command);
        }
        else if (command.find("pop") != string::npos)
        {
            solution('C', command);
        }
        else if (command.find("size") != string::npos)
        {
            solution('D', command);
        }
        else if (command.find("empty") != string::npos)
        {
            solution('E', command);
        };
    };

    
    return 0;

}