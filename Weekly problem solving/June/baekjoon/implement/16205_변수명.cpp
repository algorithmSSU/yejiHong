#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

string ans[3];

string Camel(string text){
    vector<int> idx;
    string copy = text;
    bool check = false;
    long long int size = text.length();
    for (unsigned int i = 0; i < size; i++)
    {
        if(check){
            copy[i]-=32;
            check=false;
        }else if(text[i] == '_')
        {
            check=true;
        };
    };
    copy.erase(remove(copy.begin(), copy.end(), '_'),copy.end());
    return copy;
}

string snake(string text){
    string ans = text;
    vector<int> idx;
    bool check = false;
    long long int size = text.length();
    for(unsigned int i=1;i<size;i++){
        if(text[i]<97){
            idx.emplace_back(i);
        };
    };
    int c = 0;
    long long int size= idx.size();
    for(int i=0;i<size;i++){
        ans = ans.insert(idx[i]+c,"_");
        c++;
    };

    long long int size =ans.length();
    for(int i=0;i<size;i++){
        if(ans[i]!='_'){
            ans[i]=tolower(ans[i]);
        }
    }
    

    return ans;
};

string pascal(string text){
    string ans="";
    ans = Camel(text);
    ans[0] = toupper(ans[0]);
    return ans;
};

int main(){
    int n;
    string text;
    
    cin >> n >> text;

    if(n==1){
        ans[0]= text;
        ans[1]=snake(text);
        ans[2]=pascal(text);
    }else if(n==2){
        ans[1]=text;
        ans[0]=Camel(text);
        ans[2]=pascal(text);
    }else if(n==3){
        ans[2]=text;
        ans[0]=Camel(text);
        ans[1]=snake(text);
    };

    for(int i=0;i<3;i++){
        cout << ans[i] << '\n';

    }
}