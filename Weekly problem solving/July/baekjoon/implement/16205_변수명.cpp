#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

string result[3];

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
    int size = text.length();
    for(unsigned int i=1;i<size;i++){
        if(text[i]<97){
            idx.emplace_back(i);
        };
    };
    int c = 0;
    //int size= idx.size();
    for(int i=0;i<size;i++){
        ans = ans.insert(idx[i]+c,"_");
        c++;
    };

    //int size =ans.length();
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
        result[0]= text;
        result[1] = snake(text);
        result[2] = pascal(text);
    }else if(n==2){
        result[1] = text;
        result[0] = Camel(text);
        result[2] = pascal(text);
    }else if(n==3){
        result[2] = text;
        result[0] = Camel(text);
        result[1] = snake(text);
    };

    for(int i=0;i<3;i++){
        cout << result[i] << '\n';
    }
}