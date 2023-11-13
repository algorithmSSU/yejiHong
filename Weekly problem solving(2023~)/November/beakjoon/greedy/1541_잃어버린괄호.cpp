#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int len, tmp;
int sum = 0;
bool flag; // '-'가 등장했는지 체크
string str;

int main(){
    cin >> str;
    len = str.length();


    for(int i=0;i<=len;i++){
        if(str[i]=='+' || str[i]=='-' || i==len){
            if(flag == false){
                sum+=tmp;
                tmp = 0;
            }else{
                sum -=tmp;
                tmp = 0;
            }
            if(str[i]=='-')
                flag = true;
        }else{
            tmp*=10;
            tmp+=str[i]-'0'; 
        }
    }
}